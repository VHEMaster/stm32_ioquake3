#ifndef MCC_H_
#define MCC_H_

#if defined(CORE_CM4)
#define MCC_BASE_ADDR 0x10040000
#elif defined(CORE_CM7)
#define MCC_BASE_ADDR 0x30040000
#else
#error "Must be defined one of the following expressions: CORE_CM4 or CORE_CM7"
#endif

#define MCC_RELOCATE __attribute__((section(".ahbram")))

#define MCC_MEMORY_SIZE 32768
#define MCC_QUEUE_SIZE 1024

typedef enum
{
  MCC_Ok = 0,
  MCC_NoData,
  MCC_BadData,
  MCC_Timeout,
  MCC_Sync
}MCC_ResultTypeDef;

typedef union
{
  struct
  {
      unsigned short FuncId;
      unsigned short ArgOffset;
  } data;
  unsigned int u32;
} MCC_ProcTypeDef;


extern MCC_ProcTypeDef MCC_Procedures[] MCC_RELOCATE;
extern volatile unsigned short MCC_WriteProcPointer MCC_RELOCATE;
extern volatile unsigned short MCC_ReadProcPointer MCC_RELOCATE;
extern volatile unsigned short MCC_WriteArgPointer MCC_RELOCATE;
extern volatile unsigned short MCC_ReadArgPointer MCC_RELOCATE;
extern volatile unsigned int MCC_SyncWord MCC_RELOCATE;
extern char MCC_Arguments[] MCC_RELOCATE;
extern volatile void * MCC_ReturnPointer MCC_RELOCATE;

#define MCC_ARGUMENTS_SIZE ((MCC_MEMORY_SIZE - sizeof(MCC_ReturnPointer) - sizeof(MCC_SyncWord) - sizeof(MCC_Procedures) - sizeof(MCC_WriteProcPointer) - sizeof(MCC_ReadProcPointer) - sizeof(MCC_WriteArgPointer) - sizeof(MCC_ReadArgPointer)))

extern void MCC_Initialize(void);
extern void MCC_Send(short procId, void * arg, short argSize);
extern MCC_ResultTypeDef MCC_Receive(short * procId, void * arg, short * argSize);
extern MCC_ResultTypeDef MCC_Flush(int timeout);
extern void * MCC_GetReturnPointer(void);
extern void MCC_SetReturnPointer(void * pointer);

#endif /* MCC_H_ */
