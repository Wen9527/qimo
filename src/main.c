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
	uint32_t res_value;
	float temp,k;
	datamax=30;
	datamin=30;
	ADC_Init();
	UART_Init();
	OLED_Init();    
	OLED_Clear();
	Keyinit();
	NVIC_EnableIRQ (EINT3_IRQn);
	delay_ms(10);   //ÇåÆÁµÈ´ý
	
	OLED_ShowString(0,6,"Author:");	//ÏÔÊ¾×Ö·û´®"Author :"
  OLED_ShowCHinese(60,6,2);
	OLED_ShowCHinese(80,6,3);
	OLED_ShowCHinese(100,6,4);
	
	OLED_ShowString(0,4,"Tempmax:");
	OLED_ShowNum(70,4,datamax,2,16);
	OLED_ShowCHinese(90,4,0);
	
	OLED_ShowString(0,2,"Tempmin:");
	OLED_ShowNum(70,2,datamin,2,16);
	OLED_ShowCHinese(90,2,0);

	while(1)
	{
	  
			 LPC_ADC->CR |=(1<<24);
			 while((LPC_ADC ->DR[7]&0x80000000)==0);
			 LPC_ADC->CR |=(1<<24);
			 while((LPC_ADC ->DR[7]&0x80000000)==0);
			 ulADCBuf =LPC_ADC->DR[7];
			 ulADCBuf =(ulADCBuf >>6)&0x3ff;
       ulADCData=(ulADCBuf*3300)/1024;
		   res_value=(10000*ulADCData)/(3300-ulADCData);
		 
	if((res_value<33970)&&(res_value>20310))  //0-10
	{
			k = 1366;
		  temp = (33970-res_value)/k;
	}		
	 if ((res_value<20310)&&(res_value>12570)) //10-20
	{
			k = 774;
		  temp = (20310-res_value)/k+10;
	}
	 if ((res_value<12570)&&(res_value>8034)) //20-30
	{
			k = 453.7;
		  temp = ((12570-res_value)/k)+20;
	}
	 if ((res_value<8034)&&(res_value>5298))  //30-40
	{
			k = 273.7;
		  temp = ((8034-res_value)/k)+30;
	}
	 if ((res_value<5298)&&(res_value>3586))  //40-50
	{
			k = 171.7;
		  temp = ((5298-res_value)/k)+40;
	}
	 if ((res_value<3586)&&(res_value>2484))  //50-60
	{   k = 110.2;
		  temp = ((3586-res_value)/k)+50;
	}
		sprintf (GcRcvBuf,"Temp=%f¡æ\r\n",temp);		 
	  UART_SendStr(GcRcvBuf);
	
	  OLED_ShowString(0,0,"Temp:"); 
    OLED_ShowNum(40,0,temp,2,16);
		OLED_ShowCHinese(60,0,0);
   
	}

}