#include "LPC11xx.h"                    // Device header
#include"UART.h"
#include"ADC.h"
#include<stdio.h>
#include<string.h>
#include"oled.h"

int main()
{
	ADC_Init();
	UART_Init();
	OLED_Init();    //OLED≥ı ºªØ
	OLED_Clear();
}