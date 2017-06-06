#include "LPC11xx.h"                    // Device header
#include"UART.h"
#include"ADC.h"
#include<stdio.h>
#include<string.h>
#include"OLED.h"
#include"KEY.h"
#include"Delay.h"
uint8_t datamax;
uint8_t datamin;
char   GcRcvBuf[20];

int main()
{
	uint32_t i;
	uint32_t ulADCData=0;
	uint32_t ulADCBuf;
	int32_t temp;
	int R;
	datamax=30;
	datamin=30;
	ADC_Init();
	UART_Init();
	OLED_Init();    
	OLED_Clear();
	Keyinit();
	NVIC_EnableIRQ (EINT3_IRQn);
	delay_ms(10);   //ÇåÆÁµÈ´ý
	while(1)
	{
	  for(i=0;i<10;i++)
     {
			 LPC_ADC->CR |=(1<<24);
			 while((LPC_ADC ->DR[7]&0x80000000)==0);
			 LPC_ADC->CR |=(1<<24);
			 while((LPC_ADC ->DR[7]&0x80000000)==0);
			 ulADCBuf =LPC_ADC->DR[7];
			 ulADCBuf =(ulADCBuf >>6)&0x3ff;
			 ulADCData+=ulADCBuf ;
		 }	
    ulADCData=ulADCData/10;
		
    ulADCData=(ulADCData*3300)/1024/1000;
		R=(10000*ulADCData)/(3.3-ulADCData);
		temp=CaculTwoPoint(184900,-30, 12570,20,R);
		sprintf (GcRcvBuf,"Temp=%4d¡æ\r\n",temp);		 
	  UART_SendStr(GcRcvBuf);
		Delay(200);
	 
		 
		 
    OLED_ShowString(0,6,"Author:");	//ÏÔÊ¾×Ö·û´®"Author :"
    OLED_ShowCHinese(60,6,2);
	  OLED_ShowCHinese(80,6,3);
	  OLED_ShowCHinese(100,6,4);
	 
		OLED_ShowString(0,0,"Temp:"); 
    OLED_ShowNum(40,0,temp,2,16);
		OLED_ShowCHinese(60,0,0);
		 
		OLED_ShowString(0,4,"Tempmax:");
		OLED_ShowNum(70,4,datamax,2,16);
		OLED_ShowCHinese(90,4,0);
		 
		OLED_ShowString(0,2,"Tempmin:");
		OLED_ShowNum(70,2,datamin,2,16);
		OLED_ShowCHinese(90,2,0);
	}
   	
}