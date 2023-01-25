#ifndef __OLED_H
#define __OLED_H 


#include "sys.h"
#include "stdlib.h"	

//-----------------OLED引脚定义---------------- 

#define OLED_SCL_Clr() GPIO_ResetBits(GPIOB,GPIO_Pin_8)//SCL
#define OLED_SCL_Set() GPIO_SetBits(GPIOB,GPIO_Pin_8)

#define OLED_SDA_Clr() GPIO_ResetBits(GPIOB,GPIO_Pin_9)//SDA
#define OLED_SDA_Set() GPIO_SetBits(GPIOB,GPIO_Pin_9)




#define OLED_CMD  0	
#define OLED_DATA 1	
extern _Bool once;

void OLED_ColorTurn(u8 i);
void OLED_DisplayTurn(u8 i);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_WaitAck(void);
void Send_Byte(u8 dat);
void OLED_WR_Byte(u8 dat,u8 mode);
void OLED_DisPlay_On(void);
void OLED_DisPlay_Off(void);
void OLED_Refresh(void);
void OLED_Clear(void);
//清行函数
void OLED_Clearrow(u8 row);    //by yqy 2023.1.17
void OLED_DrawPoint(u8 x,u8 y,u8 t);
void OLED_DrawLine(u8 x1,u8 y1,u8 x2,u8 y2,u8 mode);
void OLED_DrawCircle(u8 x,u8 y,u8 r);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size1,u8 mode);
void OLED_ShowChar6x8(u8 x,u8 y,u8 chr,u8 mode);
void OLED_ShowString(u8 x,u8 y,u8 *chr,u8 size1,u8 mode);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size1,u8 mode);


//show HEX
void OLED_ShowHEXNum(u8 x,u8 y,u32 num,u8 len,u8 size1,u8 mode);//by yqy(2022_12_31)


void OLED_ShowChinese(u8 x,u8 y,u8 num,u8 size1,u8 mode);


void OLED_ScrollDisplay(u8 num,u8 space,u8 mode);
void OLED_ShowPicture(u8 x,u8 y,u8 sizex,u8 sizey,u8 BMP[],u8 mode);
void OLED_Init(void);

#endif


