#include "Windows.h"
#include "cmsis_os.h"
#include "stm32h747i_discovery_sdram.h"
#include "main.h"

extern uint32_t LCD_BUFFER[];
extern DMA2D_HandleTypeDef hlcd_dma2d;
extern SDRAM_HandleTypeDef hsdram[SDRAM_INSTANCES_NBR];
extern osMutexId_t gMutexDMA2D;
extern osMessageQueueId_t gQueueDMA2D;
extern osMutexId_t gMutexMDMA;
extern osMessageQueueId_t gQueueMDMA;


void GetClientRect(HWND hwnd, RECT * rect)
{
	if(rect != 0)
	{
		rect->top = 0;
		rect->left = 0;
		rect->bottom = 480;
		rect->right = 800;
	}
}

HDC WindowFromDC(HWND hwnd)
{
	return hwnd;
}
volatile uint32_t TIME_DMA2D = 0;
volatile uint32_t TIME_MDMA = 0;
int SetDIBitsToDevice(
		  HDC              hdc,
		  int              xDest,
		  int              yDest,
		  DWORD            w,
		  DWORD            h,
		  int              xSrc,
		  int              ySrc,
		  UINT             StartScan,
		  UINT             cLines,
		  const VOID       *lpvBits,
		  const BITMAPINFO *lpbmi,
		  UINT             ColorUse
		)
{

  osStatus_t outstatus;
  osStatus_t status;


  status = osMutexAcquire(gMutexDMA2D, 5000);
  if(status == osOK)
  {
    status = osError;

    hlcd_dma2d.Instance = DMA2D;
    hlcd_dma2d.Init.Mode         = DMA2D_M2M;
    hlcd_dma2d.Init.ColorMode    = DMA2D_OUTPUT_ARGB8888;
    hlcd_dma2d.Init.OutputOffset = 0;

    /* Foreground Configuration */
    hlcd_dma2d.LayerCfg[1].AlphaMode = DMA2D_NO_MODIF_ALPHA;
    hlcd_dma2d.LayerCfg[1].InputAlpha = 0xFF;
    hlcd_dma2d.LayerCfg[1].InputColorMode = DMA2D_INPUT_ARGB8888;
    hlcd_dma2d.LayerCfg[1].InputOffset = 0;


    if(HAL_DMA2D_Init(&hlcd_dma2d) == HAL_OK)
    {
      if(HAL_DMA2D_ConfigLayer(&hlcd_dma2d, 1) == HAL_OK)
      {
        if (HAL_DMA2D_Start_IT(&hlcd_dma2d, (uint32_t)lpvBits, (uint32_t)LCD_BUFFER, w, h) == HAL_OK)
        {
          //(void)HAL_DMA2D_PollForTransfer(&hlcd_dma2d, 50);
          status = osMessageQueueGet(gQueueDMA2D, (void *)&outstatus, NULL, 5000);
        }
      }
    }
    osMutexRelease(gMutexDMA2D);
  }

  /*
  osStatus_t status = osMutexAcquire(gMutexMDMA, 5000);
  if(status == osOK)
  {
    status = osError;
    if(HAL_SDRAM_Write_DMA(&hsdram[0], (uint32_t*)LCD_BUFFER, (uint32_t*)lpvBits, w * h) == HAL_OK)
    {
      status = osMessageQueueGet(gQueueMDMA, (void *)&outstatus, NULL, 5000);
    }
    osMutexRelease(gMutexMDMA);
  }
  */

	return status == osOK ? 0 : -1;
}

#if SWGL_USE_HARDWARE_GAMMA == 1
WORD GammaArray[3][256];

BYTE SetDeviceGammaRamp(HDC hdc, LPVOID lpRamp)
{
  return 1;
}

BYTE GetDeviceGammaRamp(HDC hdc, LPVOID lpRamp)
{
  return 1;
}
#endif


