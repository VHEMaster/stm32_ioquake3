#include "mcc.h"

MCC_ProcTypeDef MCC_Procedures[MCC_QUEUE_SIZE] MCC_RELOCATE;
char MCC_Arguments[MCC_ARGUMENTS_SIZE] MCC_RELOCATE;
volatile unsigned short MCC_WriteProcPointer MCC_RELOCATE;
volatile unsigned short MCC_ReadProcPointer MCC_RELOCATE;
volatile unsigned short MCC_WriteArgPointer MCC_RELOCATE;
volatile unsigned short MCC_ReadArgPointer MCC_RELOCATE;
volatile unsigned int MCC_SyncWord MCC_RELOCATE;
volatile void * MCC_ReturnPointer MCC_RELOCATE;

void MCC_Initialize(void)
{
  int * pointer = (int*)MCC_BASE_ADDR;
  while((int)pointer < MCC_BASE_ADDR + MCC_MEMORY_SIZE)
    *pointer++ = 0;
}

//#ifdef CORE_CM7

inline void MCC_SetReturnPointer(void * pointer)
{
  MCC_ReturnPointer = pointer;
}

MCC_ResultTypeDef MCC_Receive(short * procId, void * arg, short * argSize)
{
  char * argument = (char*)arg;
  MCC_ProcTypeDef proc;
  MCC_ResultTypeDef result = MCC_Ok;
  do
  {
    result = MCC_Ok;
    proc.u32 = 0;
    short argsize = 0;
    int currentargreadpointer = MCC_ReadArgPointer;
    int currentprocreadpointer = MCC_ReadProcPointer;
    int argoffset = currentargreadpointer;

    if(currentprocreadpointer == MCC_WriteProcPointer || currentargreadpointer == MCC_WriteArgPointer)
      return MCC_NoData;

    for(int i = 0; i < sizeof(*argSize); i++)
    {
      ((char*)&argsize)[i] = MCC_Arguments[currentargreadpointer++];
      if(currentargreadpointer >= MCC_ARGUMENTS_SIZE)
        currentargreadpointer = 0;
    }

    *argSize = argsize;

    for(int i = 0; i < argsize; i++)
    {
      argument[i] = MCC_Arguments[currentargreadpointer++];
      if(currentargreadpointer >= MCC_ARGUMENTS_SIZE)
        currentargreadpointer = 0;
    }

    proc = MCC_Procedures[currentprocreadpointer++];
    if(currentprocreadpointer >= MCC_QUEUE_SIZE)
      currentprocreadpointer = 0;

    if(proc.data.ArgOffset != argoffset)
    {
      //WTF?!
      result = MCC_BadData;
    }

    MCC_ReadArgPointer = currentargreadpointer;
    MCC_ReadProcPointer = currentprocreadpointer;

    if(proc.data.FuncId == 0xFFFF)
    {
      result = MCC_Sync;
      MCC_SyncWord = 1;
    }
    else
      *procId = proc.data.FuncId;

  } while(proc.data.FuncId == 0xFFFF);
  return result;
}

//#endif

//#ifdef CORE_CM4

inline void * MCC_GetReturnPointer(void)
{
  void * pointer = (void*)MCC_ReturnPointer;
  MCC_ReturnPointer = 0;
  return pointer;
}

MCC_ResultTypeDef MCC_Flush(int timeout)
{
  MCC_SyncWord = 0;
  MCC_Send(0xFFFF, 0, 0);
  while(MCC_SyncWord == 0)
  {
    //Timeout handling;
  }
  MCC_SyncWord = 0;
  return MCC_Ok;
}

void MCC_Send(short procId, void * arg, short argSize)
{
  MCC_ProcTypeDef proc;
  char * argument = (char*)arg;
  int currentargwritepointer = MCC_WriteArgPointer;
  int currentprocwritepointer = MCC_WriteProcPointer;
  int argoffset = currentargwritepointer;

  for(int i = 0; i < sizeof(argSize); i++)
  {
    MCC_Arguments[currentargwritepointer++] = ((char*)&argSize)[i];
    if(currentargwritepointer >= MCC_ARGUMENTS_SIZE)
      currentargwritepointer = 0;

    while(currentargwritepointer == MCC_ReadArgPointer)
    {
        //delay?? for overflow protection
    }
  }

  for(int i = 0; i < argSize; i++)
  {
    MCC_Arguments[currentargwritepointer++] = argument[i];
    if(currentargwritepointer >= MCC_ARGUMENTS_SIZE)
      currentargwritepointer = 0;

    while(currentargwritepointer == MCC_ReadArgPointer)
    {
        //delay?? for overflow protection
    }

  }

  proc.data.ArgOffset = argoffset;
  proc.data.FuncId = procId;

  MCC_Procedures[currentprocwritepointer++] = proc;
  if(currentprocwritepointer >= MCC_QUEUE_SIZE)
    currentprocwritepointer = 0;

  while(currentprocwritepointer == MCC_ReadProcPointer)
  {
    //delay??
  }

  MCC_WriteArgPointer = currentargwritepointer;
  MCC_WriteProcPointer = currentprocwritepointer;
}
//#endif

