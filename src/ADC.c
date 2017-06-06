#include"ADC.h"
void ADC_Init(void)
{
	LPC_SYSCON->SYSAHBCLKCTRL |=(1<<16);
	LPC_IOCON->PIO1_11&=~0xBF;
	LPC_IOCON->PIO1_11|=0x01;
	LPC_SYSCON ->PDRUNCFG &=~(0x01<<4);
	LPC_SYSCON->SYSAHBCLKCTRL |=(0x01<<13);
	LPC_ADC->CR =(0x01<<7)|((SystemCoreClock /1000000-1)<<8)|(0<<16)|(0<<17)|(0<<24)|(0<<27);
	
}

int32_t  CaculTwoPoint(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x)
{
    return y1 + ((int64_t)(y2 - y1) * (x - x1)) / (x2 - x1);
}
