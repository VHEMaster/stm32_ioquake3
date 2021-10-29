#include "stm32h7xx.h"
#include "stm32h7xx_hal.h"

#define DelayDivider 1

#define Delay_Tick (TIM5->CNT)
#define COUNTERS 50
extern volatile uint32_t DelStart[COUNTERS];

void DelayInit(void);					//�������������
void DelayUs(uint32_t micros);			//�������� � ���
void DelayMs(uint32_t millis);			//�������� � ��
uint32_t DelayBetween(uint32_t startpoint);
#define DelayStartCount(counter) (DelStart[counter]=Delay_Tick)
uint32_t DelayStopCount(uint32_t counter);	//����, ������� �����, ����������� �� ���������� � ���
