/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "mcc_functions.h"
#include "main.h"
#include "string.h"
#include "mcc.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
 
#define HSEM_ID_0 (0U) /* HW semaphore 0*/
/* USER CODE END PD */

/* USER CODE END PV */

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

inline void gencolor(float value, uint8_t * r, uint8_t * g, uint8_t * b)
{
  float fr = 0, fb = 0, fg = 0;
  value = fmodf(value, 1.0f);
  value *= 6.0f;

  if(value >= 2.0f && value < 4.0f)
    fr = 0.0f;
  if(value >= 4.0f && value < 5.0f)
    fr = value - 4.0f;
  if(value >= 5.0f || value < 1.0f)
    fr = 1.0f;
  if(value >= 1.0f && value < 2.0f)
    fr = 2.0f - value;

  if(value >= 0.0f && value < 1.0f)
    fg = value;
  if(value >= 1.0f && value < 3.0f)
    fg = 1.0f;
  if(value >= 3.0f && value < 4.0f)
    fg = 4.0f - value;
  if(value >= 4.0f && value < 1.0f)
    fg = 0.0f;

  if(value >= 0.0f && value < 2.0f)
    fb = 0.0f;
  if(value >= 2.0f && value < 3.0f)
    fb = value - 2.0f;
  if(value >= 3.0f && value < 5.0f)
    fb = 1.0f;
  if(value >= 5.0f && value < 6.0f)
    fb = 6.0f - value;

  *r = fr * 255.0f;
  *g = fg * 255.0f;
  *b = fb * 255.0f;

}
/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

/* USER CODE BEGIN Boot_Mode_Sequence_1 */
  /*HW semaphore Clock enable*/
  __HAL_RCC_HSEM_CLK_ENABLE();
  /* Activate HSEM notification for Cortex-M4*/
  HAL_HSEM_ActivateNotification(__HAL_HSEM_SEMID_TO_MASK(HSEM_ID_0));
  /*
  Domain D2 goes to STOP mode (Cortex-M4 in deep-sleep) waiting for Cortex-M7 to
  perform system initialization (system clock config, external memory configuration.. )
  */
  HAL_PWREx_ClearPendingEvent();
  HAL_PWREx_EnterSTOPMode(PWR_MAINREGULATOR_ON, PWR_STOPENTRY_WFE, PWR_D2_DOMAIN);
  /* Clear HSEM flag */
  __HAL_HSEM_CLEAR_FLAG(__HAL_HSEM_SEMID_TO_MASK(HSEM_ID_0));

/* USER CODE END Boot_Mode_Sequence_1 */
  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  MCC_Initialize();



  HDC hdc = glDrv_wglGetCurrentDC();
  HGLRC context = glDrv_wglCreateContext(hdc);
  glDrv_wglMakeCurrent(hdc, context);

  while (1)
  {
    //HAL_GPIO_TogglePin(GPIOI, GPIO_PIN_12);

    //MCC_Send(1, NULL, 0);
    //MCC_Flush(5000);
    //MCC_Send(2, NULL, 0);
    //MCC_Flush(5000);

    static float angle = 0.0f;

    angle += 3.1415f / 180.0f * 3.0f;
    float angle1 = 0.0f + angle;
    float angle2 = 2.094f + angle;
    float angle3 = 4.189f + angle;

    float angleq1 = 0.0f + angle*1.3f;
    float angleq2 = 1.57f + angle*1.3f;
    float angleq3 = 3.14f + angle*1.3f;
    float angleq4 = 4.71f + angle*1.3f;

    glDrv_glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrv_glMatrixMode(GL_PROJECTION);
    glDrv_glLoadIdentity();
    glDrv_glOrtho(0.0, 800.0, 0.0, 480.0, 0.0, 4.0);

  /*
    glDrv_glBegin(GL_QUADS);

    glDrv_glColor3ub(255,255,0);
    glDrv_glVertex2f(-1.0f, -1.0f);
    glDrv_glColor3ub(0,255,255);
    glDrv_glVertex2f(1.0f, -1.0f);
    glDrv_glColor3ub(128,255,192);
    glDrv_glVertex2f(1.0f, 1.0f);
    glDrv_glColor3ub(255,0,255);
    glDrv_glVertex2f(-1.0f, 1.0f);

    glDrv_glEnd();
  */
    int div = 30;
    float sino = sinf(-angle1 * 0.7f);
    float coso = cosf(-angle1 * 0.7f);
    float cnt = 0;
    float sin;
    float cos;
    uint8_t r,g,b;
    uint8_t ro,go,bo;
    gencolor(cnt + angle1 * 0.8f, &ro ,&go ,&bo);

    for(int i = 1; i <= div; i++)
    {
      glDrv_glBegin(GL_QUADS);
      cnt = (float)i / (float)div;
      sin = sinf(cnt * 6.2831853f - angle1 * 0.7f);
      cos = cosf(cnt * 6.2831853f - angle1 * 0.7f);

      gencolor(cnt + angle1 * 0.8f, &r ,&g ,&b);
      glDrv_glColor3ub(r,g,b);
      glDrv_glVertex2f(sin*200.0f+600.0f, cos*200.0f+240.0f);
      glDrv_glVertex2f(sin*190.0f+600.0f, cos*190.0f+240.0f);
      glDrv_glColor3ub(ro,go,bo);
      glDrv_glVertex2f(sino*200.0f+600.0f, coso*200.0f+240.0f);
      glDrv_glVertex2f(sino*190.0f+600.0f, coso*190.0f+240.0f);
      glDrv_glEnd();

      sino = sin;
      coso = cos;
      ro = r;
      bo = b;
      go = g;

    }

    glDrv_glBegin(GL_TRIANGLES);

    glDrv_glColor3ub(255,0,0);
    glDrv_glVertex2f(sinf(angle1)*195.0f+600.0f, cosf(angle1)*195.0f+240.0f);
    glDrv_glColor3ub(0,255,0);
    glDrv_glVertex2f(sinf(angle2)*195.0f+600.0f, cosf(angle2)*195.0f+240.0f);
    glDrv_glColor3ub(0,0,255);
    glDrv_glVertex2f(sinf(angle3)*195.0f+600.0f, cosf(angle3)*195.0f+240.0f);
    glDrv_glEnd();


    glDrv_glBegin(GL_QUADS);

    glDrv_glColor3ub(255,0,0);
    glDrv_glVertex2f(sinf(angleq1)*195.0f+200.0f, cosf(angleq1)*195.0f+240.0f);
    glDrv_glColor3ub(80,255,0);
    glDrv_glVertex2f(sinf(angleq2)*195.0f+200.0f, cosf(angleq2)*195.0f+240.0f);
    glDrv_glColor3ub(0,170,90);
    glDrv_glVertex2f(sinf(angleq3)*195.0f+200.0f, cosf(angleq3)*195.0f+240.0f);
    glDrv_glColor3ub(80,0,230);
    glDrv_glVertex2f(sinf(angleq4)*195.0f+200.0f, cosf(angleq4)*195.0f+240.0f);

    glDrv_glEnd();



    HDC hdc = glDrv_wglGetCurrentDC();
    glDrv_wglSwapBuffers(hdc);

  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
