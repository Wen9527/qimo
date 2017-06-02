#include"Delay.h"
static volatile unsigned int ticks;
void Delay(uint32_t ulTime)
{
	uint32_t i;
	i=0;
	while(ulTime--)
	{
		for(i=0;i<5000;i++);
	}
}
void delay_ms(int ms)       //延时到毫秒
{
    SysTick->CTRL &= ~(1 << 2);      
    SysTick->LOAD = 25000*ms-1;            
    SysTick->VAL = 0;           //将当前值清零
    SysTick->CTRL = ((1<<1) | (1<<0));          //使能中断，启动系统节拍定时器
    while(!ticks);              //等待定时时间到，ticks = 1
    ticks = 0;              //清零
    SysTick->CTRL = 0;          //停止系统节拍定时器
}
