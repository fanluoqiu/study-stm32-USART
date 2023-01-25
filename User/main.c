

//  ********oled********
//  SCL:PIN_B8
//  SDA:PNIN_B9
//  ********oled********

// ********Buzzer********
// IO:PIN_A 5
// ********Buzzer********


// ********USART********
// TX:PA_2
// RX:PA_3
// ********USART********
#include "stm32f10x.h"
#include "delay.h"
#include "buzzer.h"
#include "Oledprint.h"
#include "serial.h"
#include "main.h"




_Bool Rxstate=0;
_Bool Txstate=0;
uint16_t Rxdata;
_Bool i=1;
int main(void)
{
	delay_init();
	OLEDintset();	
	Buzzer_init();
	Serialprint_init();
	bootPOST();
	OLED_Clear();
	while (1)
	{	
		switch (GetShowMode())
		{
		case mode_default:
			toptitle("default",0);
			OLED_Refresh();
			Txstate=1;
			break;
		case mode_TX:

			for(;i==1;i=!i)
				OLED_Clear();
			toptitle("transport",0);
			OLED_ShowString(0,30,"Rxdata",16,0);
			Serial_print("这是测试%d:\r\n",1);
			OLED_Refresh();
			delay_ms(1000);
			break;
		case mode_RX:
			Buzzer_voice();
			toptitle("receive",0);
			OLED_ShowString(0,30,"Rxdata",16,0);
			OLED_ShowHEXNum(56,30,Rxdata,2,16,1);
			OLED_Refresh();
			Serial_print("收到数据%X\r\n",Rxdata);
			Rxstate=0;
			i=1;
			delay_ms(1000);
			break;
		default:
			break;
		}
	}
}

void USART2_IRQHandler(void) 
{
	if(USART_GetITStatus(USART2,USART_IT_RXNE)==SET)
	{
		Rxdata=USART_ReceiveData(USART2);
		Rxstate=1;
	}
		
}

OLED_maininterf_mode GetShowMode(void)
{
	if(Rxstate==1)	
	{
		Txstate=0;
		return mode_RX;
	}
	else if(Txstate==1)	
		return mode_TX;
	else 
		return mode_default;
}
