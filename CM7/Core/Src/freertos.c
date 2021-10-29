/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "delay.h"
#include "cmsis_os.h"
#include "mcc_functions.h"
#include "basic_gui.h"


#include "stm32h747i_discovery.h"
#include "stm32h747i_discovery_lcd.h"
#include "stm32h747i_discovery_ts.h"
#include "stm32h747i_discovery_sd.h"
#include "stm32h747i_discovery_sdram.h"
#include "stm32h747i_discovery_qspi.h"

#include "fatfs.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */     

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
osThreadId_t controlTaskHandle;
osThreadId_t logTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 32768 * 4
};
const osThreadAttr_t controlTask_attributes = {
  .name = "controlTask",
  .priority = (osPriority_t) osPriorityHigh,
  .stack_size = 2048 * 4
};
const osThreadAttr_t logTask_attributes = {
  .name = "controlTask",
  .priority = (osPriority_t) osPriorityRealtime,
  .stack_size = 512 * 4
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
   
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void StartLogTask(void * args);
void StartControls(void * args);

extern void MX_LWIP_Init(void);
extern void MX_USB_HOST_Init(void);
void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* Hook prototypes */
void configureTimerForRunTimeStats(void);
unsigned long getRunTimeCounterValue(void);
void vApplicationIdleHook(void);
void vApplicationTickHook(void);
void vApplicationStackOverflowHook(xTaskHandle xTask, signed char *pcTaskName);
void vApplicationMallocFailedHook(void);
void vApplicationDaemonTaskStartupHook(void);

/* USER CODE BEGIN 1 */
/* Functions needed when configGENERATE_RUN_TIME_STATS is on */
__weak void configureTimerForRunTimeStats(void)
{

}

__weak unsigned long getRunTimeCounterValue(void)
{
return 0;
}
/* USER CODE END 1 */

/* USER CODE BEGIN 2 */
__weak void vApplicationIdleHook( void )
{
   /* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
   to 1 in FreeRTOSConfig.h. It will be called on each iteration of the idle
   task. It is essential that code added to this hook function never attempts
   to block in any way (for example, call xQueueReceive() with a block time
   specified, or call vTaskDelay()). If the application makes use of the
   vTaskDelete() API function (as this demo application does) then it is also
   important that vApplicationIdleHook() is permitted to return to its calling
   function, because it is the responsibility of the idle task to clean up
   memory allocated by the kernel to any task that has since been deleted. */
}
/* USER CODE END 2 */

/* USER CODE BEGIN 3 */
__weak void vApplicationTickHook( void )
{
   /* This function will be called by each tick interrupt if
   configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.h. User code can be
   added here, but the tick hook is called from an interrupt context, so
   code must not attempt to block, and only the interrupt safe FreeRTOS API
   functions can be used (those that end in FromISR()). */
}
/* USER CODE END 3 */

/* USER CODE BEGIN 4 */
__weak void vApplicationStackOverflowHook(xTaskHandle xTask, signed char *pcTaskName)
{
   /* Run time stack overflow checking is performed if
   configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2. This hook function is
   called if a stack overflow is detected. */
}
/* USER CODE END 4 */

/* USER CODE BEGIN 5 */
__weak void vApplicationMallocFailedHook(void)
{
   /* vApplicationMallocFailedHook() will only be called if
   configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h. It is a hook
   function that will get called if a call to pvPortMalloc() fails.
   pvPortMalloc() is called internally by the kernel whenever a task, queue,
   timer or semaphore is created. It is also called by various parts of the
   demo application. If heap_1.c or heap_2.c are used, then the size of the
   heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
   FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
   to query the size of free heap space that remains (although it does not
   provide information on how the remaining heap might be fragmented). */
}
/* USER CODE END 5 */

/* USER CODE BEGIN DAEMON_TASK_STARTUP_HOOK */
void vApplicationDaemonTaskStartupHook(void)
{
}

void MX_FREERTOS_Init(void)
{
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);


}

const osMutexAttr_t dma2dmutexattrs = {
  .name = "DMA2DMutex",
  .attr_bits = osMutexRecursive,
  .cb_mem = NULL,
  .cb_size = 0
};

extern DMA2D_HandleTypeDef hlcd_dma2d;
extern SDRAM_HandleTypeDef hsdram[];
osMutexId_t gMutexDMA2D;
osMessageQueueId_t gQueueDMA2D;
osMutexId_t gMutexMDMA;
osMessageQueueId_t gQueueMDMA;

uint8_t buff[512] __attribute__((section(".SdramSection"))) = {0};

FATFS fatfs __attribute__((section(".AxiRamSection")));

extern int Q3_main( int argc, char **argv );

void DMA2D_TransferCompleteCallback(DMA2D_HandleTypeDef * hdma2d)
{
  osStatus_t status = osOK;
  osMessageQueuePut(gQueueDMA2D, (const void *)&status, 0, 0);
}

void DMA2D_TransferErrorCallback(DMA2D_HandleTypeDef * hdma2d)
{
  osStatus_t status = osError;
  osMessageQueuePut(gQueueDMA2D, (const void *)&status, 0, 0);
}

void HAL_SDRAM_DMA_XferCpltCallback(MDMA_HandleTypeDef * hmdma)
{
  osStatus_t status = osOK;
  osMessageQueuePut(gQueueMDMA, (const void *)&status, 0, 0);
}

void HAL_SDRAM_DMA_XferErrorCallback(MDMA_HandleTypeDef * hmdma)
{
  osStatus_t status = osError;
  osMessageQueuePut(gQueueMDMA, (const void *)&status, 0, 0);
}

extern void startexample(void);

FIL file;
volatile FRESULT res = FR_OK;

void StartDefaultTask(void *argument)
{
  MX_LWIP_Init();
  //MX_USB_HOST_Init();

  gMutexDMA2D = osMutexNew(&dma2dmutexattrs);
  gQueueDMA2D = osMessageQueueNew(32, sizeof(osStatus_t), NULL);
  hlcd_dma2d.XferCpltCallback = DMA2D_TransferCompleteCallback;
  hlcd_dma2d.XferErrorCallback = DMA2D_TransferErrorCallback;

  gMutexMDMA = osMutexNew(&dma2dmutexattrs);
  gQueueMDMA = osMessageQueueNew(32, sizeof(osStatus_t), NULL);

  //startexample();

  //while(1)
  //{
    //MCC_HandleOpenGL();
    //BSP_LED_Toggle(LED_GREEN);
  //}

  TS_State_t TS_State = {0};

  char * dir = "0:\\ioquake3";
  if(f_mount(&fatfs,SDPath,1) == FR_OK)
  {
    if(f_chdir(dir) == FR_OK)
    {
      BSP_LCD_FillRect(0, 0, 0, 800, 480, 0xFF000000);
      BSP_LED_On(LED_BLUE);

      logTaskHandle = osThreadNew(StartLogTask, NULL, &logTask_attributes);
      controlTaskHandle = osThreadNew(StartControls, NULL, &controlTask_attributes);

      Q3_main(1, &dir);
    }
    else
      BSP_LCD_FillRect(0, 0, 0, 800, 480, 0xFF808080);
  }
  else
  BSP_LCD_FillRect(0, 0, 0, 800, 480, 0xFFFF0000);

  while(1)
  {
    BSP_TS_GetState(0, &TS_State);
    if(TS_State.TouchDetected)
    {
      int x1 = TS_State.TouchX;
      int y1 = TS_State.TouchY;
      BSP_LCD_FillRect(0, x1-10, 480-y1-10, 20, 20, 0xFF808080);
    }
  }
}

#include "SDL_events.h"
#include "SDL_keyboard.h"

extern int SDL_PrivateKeyboard(Uint8 state, SDL_keysym *key);

void StartControls(void * args)
{
  uint32_t joystate = 0;
  uint32_t old_joystate = 0;
  uint32_t buttonstate = 0;
  uint32_t old_buttonstate = 0;
  Uint8 bstate;
  SDL_keysym keysym;
  while(1)
  {
    osDelay(20);
    //SDL_KeyState[SDLK_LCTRL] = BSP_PB_GetState(BUTTON_WAKEUP) == GPIO_PIN_SET ? SDL_PRESSED : SDL_RELEASED;
    //SDL_KeyState[SDLK_LEFT] = joystate & JOY_LEFT ? SDL_PRESSED : SDL_RELEASED;
    //SDL_KeyState[SDLK_RIGHT] = joystate & JOY_RIGHT ? SDL_PRESSED : SDL_RELEASED;
    //SDL_KeyState[SDLK_UP] = joystate & JOY_UP ? SDL_PRESSED : SDL_RELEASED;
    //SDL_KeyState[SDLK_DOWN] = joystate & JOY_DOWN ? SDL_PRESSED : SDL_RELEASED;
    //SDL_KeyState[SDLK_RETURN] = joystate & JOY_SEL ? SDL_PRESSED : SDL_RELEASED;

    buttonstate = BSP_PB_GetState(BUTTON_WAKEUP) == GPIO_PIN_SET;
    joystate = BSP_JOY_GetState(JOY1, 0);

    if(buttonstate != old_buttonstate)
    {
      bstate = buttonstate > 0 ? SDL_PRESSED : SDL_RELEASED;
      keysym.scancode = 1;
      keysym.sym = SDLK_LCTRL;
      SDL_PrivateKeyboard(bstate, &keysym);
    }

    if((joystate & JOY_LEFT) != (old_joystate & JOY_LEFT))
    {
      bstate = joystate & JOY_LEFT ? SDL_PRESSED : SDL_RELEASED;
      keysym.scancode = 2;
      keysym.sym = SDLK_LEFT;
      SDL_PrivateKeyboard(bstate, &keysym);
    }

    if((joystate & JOY_RIGHT) != (old_joystate & JOY_RIGHT))
    {
      bstate = joystate & JOY_RIGHT ? SDL_PRESSED : SDL_RELEASED;
      keysym.scancode = 3;
      keysym.sym = SDLK_RIGHT;
      SDL_PrivateKeyboard(bstate, &keysym);
    }

    if((joystate & JOY_UP) != (old_joystate & JOY_UP))
    {
      bstate = joystate & JOY_UP ? SDL_PRESSED : SDL_RELEASED;
      keysym.scancode = 4;
      keysym.sym = SDLK_UP;
      SDL_PrivateKeyboard(bstate, &keysym);
    }

    if((joystate & JOY_DOWN) != (old_joystate & JOY_DOWN))
    {
      bstate = joystate & JOY_DOWN ? SDL_PRESSED : SDL_RELEASED;
      keysym.scancode = 5;
      keysym.sym = SDLK_DOWN;
      SDL_PrivateKeyboard(bstate, &keysym);
    }

    if((joystate & JOY_SEL) != (old_joystate & JOY_SEL))
    {
      bstate = joystate & JOY_SEL ? SDL_PRESSED : SDL_RELEASED;
      keysym.scancode = 6;
      keysym.sym = SDLK_RETURN;
      SDL_PrivateKeyboard(bstate, &keysym);
    }

    old_joystate = joystate;
    old_buttonstate = buttonstate;


  }
}

#include "sys_local.h"
//unsigned int CON_LogRead( char *out, unsigned int outSize );

char LOG_Buffer[3700];

void StartLogTask(void * args)
{
  sFONT * font = &Font12;
  char * buffer = LOG_Buffer;
  char tempbuffer[512];
  int size_x = (800 - 1) / (font->Width + 1) - 1;
  int size_y = (480 - 1) / (font->Height + 1) - 1;
  int step_x = font->Width + 1;
  int step_y = font->Height + 1;
  int off_x = 2;
  int off_y = 2;

  char * chr;
  char tchar;
  int pos_x = 0;
  int read;

  GUI_SetFont(font);
  GUI_SetBackColor(GUI_COLOR_BLACK);
  GUI_Clear(GUI_COLOR_BLACK);
  GUI_SetTextColor(GUI_COLOR_WHITE);
  memset(buffer, ' ', size_x * size_y);

  while(1)
  {
    read = CON_LogRead(tempbuffer, sizeof(tempbuffer) - 1);
    tempbuffer[read] = 0;
    if(read > 0)
    {
      chr = tempbuffer;
      while(*chr)
      {
        tchar = *chr;
        if(tchar == '\n' || pos_x >= size_x)
        {
          if(tchar == '\n')
             chr++;
          pos_x = 0;
          for(int i = 0; i < size_y - 1; i++)
          {
            for(int j = 0; j < size_x; j++)
            {
              tchar = buffer[((i + 1) * size_x) + j];
              if(buffer[(i * size_x) + j] != tchar)
              {
                buffer[(i * size_x) + j] = tchar;
                GUI_DisplayChar(j * step_x + off_x, i * step_y + off_y, tchar);
              }
            }
          }
          for(int j = 0; j < size_x; j++)
          {
            tchar = ' ';
            if(buffer[((size_y - 1) * size_x) + j] != tchar)
            {
              buffer[((size_y - 1) * size_x) + j] = tchar;
              GUI_DisplayChar(j * step_x + off_x, (size_y - 1) * step_y + off_y, tchar);
            }
          }
        }
        else
        {
          if(tchar < 0x20 || tchar > 0x7E)
            tchar = 0x20;
          buffer[((size_y - 1) * size_x) + pos_x] = tchar;
          GUI_DisplayChar(pos_x * step_x + off_x, (size_y - 1) * step_y + off_y, tchar);
          pos_x++;
          chr++;
        }
      }
    }
    else osDelay(10);
  }
  osThreadExit();
}



/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
