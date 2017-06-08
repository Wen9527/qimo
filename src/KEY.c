#include"KEY.h"
#include"oled.h"
extern uint8_t datamax;
extern uint8_t datamin;
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
	 }
	 
	 
	 void PIOINT3_IRQHandler()
{
 if((LPC_GPIO3->MIS &(1<<0))==(1<<0))//如果是P3.0引起的中断
 {
	    datamax++;
			if(datamax>=40)
			datamax=40;
		OLED_ShowString(0,4,"Tempmax:");
		OLED_ShowNum(70,4,datamax,2,16);
		OLED_ShowCHinese(90,4,0);
			
			
	 LPC_GPIO3->IC =(1<<0);//清中断
 }	

 if((LPC_GPIO3->MIS &(1<<1))==(1<<1))//如果是P3.1引起的中断
 {
	 datamin--;
	 if(datamin<=15)
		 datamin=15;
	  OLED_ShowString(0,2,"Tempmin:");
		OLED_ShowNum(70,2,datamin,2,16);
		OLED_ShowCHinese(90,2,0);
	 LPC_GPIO3->IC =(1<<1);//清中断
 }	
 
 if((LPC_GPIO3->MIS &(1<<2))==(1<<2))//如果是P3.2引起的中断
 {
	 OLED_Clear();
	 OLED_ShowCHinese(0,6,5);
	 OLED_ShowCHinese(20,6,6);
	 OLED_ShowCHinese(40,6,7);
	 OLED_ShowCHinese(60,6,8);
   LPC_GPIO3->IC =(1<<2);
 }
	 
}
