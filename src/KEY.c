#include"KEY.h"
#include"oled.h"
extern uint8_t datamax;
extern uint8_t datamin;
 void Keyinit()
	 {
	 LPC_GPIO3->DIR &=~(1<<0);//��P3.0��Ϊ����
	 LPC_GPIO3->IE |=(1<<0);//�����ж�
	 LPC_GPIO3->IS  &=~(1<<0);//��Ե����
	 LPC_GPIO3->IEV  &=~(1<<0);//�½��ش���
		 
   LPC_GPIO3->DIR &=~(1<<1);//��P3.1��Ϊ����
	 LPC_GPIO3->IE |=(1<<1);//�����ж�
	 LPC_GPIO3->IS  &=~(1<<1);//��Ե����
	 LPC_GPIO3->IEV  &=~(1<<1);//�½��ش���
		 
	 LPC_GPIO3->DIR &=~(1<<2);//��P3.2��Ϊ����
	 LPC_GPIO3->IE |=(1<<2);//�����ж�
	 LPC_GPIO3->IS  &=~(1<<2);//��Ե����
	 LPC_GPIO3->IEV  &=~(1<<2);//�½��ش���
	 }
	 
	 
	 void PIOINT3_IRQHandler()
{
 if((LPC_GPIO3->MIS &(1<<0))==(1<<0))//�����P3.0������ж�
 {
	    datamax++;
			if(datamax>=40)
			datamax=40;
		OLED_ShowString(0,4,"Tempmax:");
		OLED_ShowNum(70,4,datamax,2,16);
		OLED_ShowCHinese(90,4,0);
			
			
	 LPC_GPIO3->IC =(1<<0);//���ж�
 }	

 if((LPC_GPIO3->MIS &(1<<1))==(1<<1))//�����P3.1������ж�
 {
	 datamin--;
	 if(datamin<=15)
		 datamin=15;
	  OLED_ShowString(0,2,"Tempmin:");
		OLED_ShowNum(70,2,datamin,2,16);
		OLED_ShowCHinese(90,2,0);
	 LPC_GPIO3->IC =(1<<1);//���ж�
 }	
 
 if((LPC_GPIO3->MIS &(1<<2))==(1<<2))//�����P3.2������ж�
 {
	 OLED_Clear();
	 OLED_ShowCHinese(0,6,5);
	 OLED_ShowCHinese(20,6,6);
	 OLED_ShowCHinese(40,6,7);
	 OLED_ShowCHinese(60,6,8);
   LPC_GPIO3->IC =(1<<2);
 }
	 
}
