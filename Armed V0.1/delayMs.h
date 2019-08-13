#ifndef __delayMs__h
#define __delayMs__h
#include "stm32f10x.h"


static __IO uint32_t TimingDelay;
void InitTimer(void);
void SysTick_Handler(void);
void Delay(__IO uint32_t nTime);



#endif
