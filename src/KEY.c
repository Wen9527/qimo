#include"KEY.h"
#include"oled.h"
#include"Delay.h"
extern uint8_t datamax;
extern uint8_t datamin;
extern float HS;
 void Keyinit()
	 {
	 LPC_GPIO3->DIR &=~(1<<0);//将P3.0置为输入
	 LPC_GPIO3->IE |=(1<<0);//允许中断
	 LPC_GPIO3->IS  &=~(1<<0);//边缘触发
	 LPC_GPIO3->IEV  &=~(1<<0);//下降沿触发
		 
   LPC_GPIO3->DIR &=~(1<<1);//将P3.1置为输入
	 LPC_GPIO3->IE |=(1<<1);//允许中断
	 LPC_GPIO3->IS  &=~(1<<1);//边缘触发
	 LPC_GPIO3->IEV  &=~(1<<1);//下降沿触发
		 
	 LPC_GPIO3->DIR &=~(1<<2);//将P3.2置为输入
	 LPC_GPIO3->IE |=(1<<2);//允许中断
	 LPC_GPIO3->IS  &=~(1<<2);//边缘触发
	 LPC_GPIO3->IEV  &=~(1<<2);//下降沿触发
		 
	 LPC_GPIO3->DIR &=~(1<<3);//将P3.3置为输入
	 LPC_GPIO3->IE |=(1<<3);//允许中断
	 LPC_GPIO3->IS  &=~(1<<3);//边缘触发
	 LPC_GPIO3->IEV  &=~(1<<3);//下降沿触发
		 
	 LPC_GPIO3->DIR &=~(1<<4);//将P3.4置为输入
	 LPC_GPIO3->IE |=(1<<4);//允许中断
	 LPC_GPIO3->IS  &=~(1<<4);//边缘触发
	 LPC_GPIO3->IEV  &=~(1<<4);//下降沿触发
		 
	 }
	 
	 
	 void PIOINT3_IRQHandler()
{
  if((LPC_GPIO3->MIS &(1<<0))==(1<<0))//如果是P3.0引起的中断
	{  datamax++;
			if(datamax>=40)
			datamax=40;
			
	OLED_ShowString(0,6,"   Tempmax:");
	OLED_ShowNum(90,6,datamax,2,16);
	OLED_ShowCHinese(115,6,0);	
	 LPC_GPIO3->IC =(1<<0);//清中断
 }	

 if((LPC_GPIO3->MIS &(1<<1))==(1<<1))//如果是P3.1引起的中断
 {  
	 datamin--;
	 if(datamin<=15)
		 datamin=15;
	 
	 
	OLED_ShowString(0,4,"   Tempmin:");
	OLED_ShowNum(90,4,datamin,2,16);
	OLED_ShowCHinese(115,4,0);
	 LPC_GPIO3->IC =(1<<1);//清中断
 }	
 
 if((LPC_GPIO3->MIS &(1<<2))==(1<<2))//如果是P3.2引起的中断
 {
	 OLED_Clear();
	 OLED_Clear();
	OLED_ShowString(0,6,"Author:");	//显示字符串"Author :"
  OLED_ShowCHinese(60,6,2);
	OLED_ShowCHinese(80,6,3);
	OLED_ShowCHinese(100,6,4);
   LPC_GPIO3->IC =(1<<2);
 }
 
 if((LPC_GPIO3->MIS &(1<<3))==(1<<3))//如果是P3.2引起的中断
 {
	 OLED_Clear();
	 OLED_Clear();
	 OLED_ShowCHinese(0,6,5);
	 OLED_ShowCHinese(20,6,6);
	 OLED_ShowCHinese(40,6,7);
	 OLED_ShowCHinese(60,6,8);
	
	 LPC_GPIO3->IC =(1<<3);
 }
 
 if((LPC_GPIO3->MIS &(1<<4))==(1<<4))//如果是P3.4引起的中断
 {
	 OLED_Clear();
	 OLED_Clear();
	
	 LPC_GPIO3->IC =(1<<4);
 }
 }

