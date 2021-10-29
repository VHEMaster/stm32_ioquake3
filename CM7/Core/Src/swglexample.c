#include "OpenGL.h"
#include "Wiggle.h"
#include "cmsis_os.h"
#include "delay.h"
#include "Windows.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include "stm32h747i_discovery.h"
#include "basic_gui.h"
#include "mcc.h"

void gencolor(float value, uint8_t * r, uint8_t * g, uint8_t * b)
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

void
display(void)
{
  uint32_t start = Delay_Tick;
  static float angle = 0.0f;
  static float time_avg = 0.0f;

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

  BSP_LED_Toggle(LED_ORANGE);

  uint32_t time = Delay_Tick - start;
  if(time_avg == 0.0f)
    time_avg = time;
  else time_avg = time_avg * 0.99f + time * 0.01f;

  GUI_SetBackColor(GUI_COLOR_BLACK);
  GUI_SetTextColor(GUI_COLOR_YELLOW);
  static char buff[512];

  sprintf(buff, "%.1f FPS   %.1f", 1000000.0f / (float)time, 1000000.0f / time_avg);
  GUI_DisplayStringAt(10, 10, (uint8_t *)buff, LEFT_MODE);
  sprintf(buff, "%.1f ms  %.1f", (float)time * 0.001f, time_avg * 0.001f);
  GUI_DisplayStringAt(10, 35, (uint8_t *)buff, LEFT_MODE);

  short argsize;
  short procid;
  while(MCC_Receive(&procid, NULL, &argsize) == 0)
  {
    if(procid == 1)
      BSP_LED_Toggle(LED_GREEN);
    if(procid == 2)
      BSP_LED_Toggle(LED_RED);
    if(procid == 3)
      osDelay(10);
  }

}

void
init(void)
{
  HDC hdc = glDrv_wglGetCurrentDC();
  HGLRC context = glDrv_wglCreateContext(hdc);
  glDrv_wglMakeCurrent(hdc, context);
}

void startexample(void)
{
  init();
  while(1)
  {
    display();
  }
}
