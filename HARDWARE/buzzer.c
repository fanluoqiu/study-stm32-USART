
#include "buzzer.h"


void Buzzer_init(void)
{

    //配置GPIO
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&GPIO_InitStructure);
    GPIO_ResetBits(GPIOA,GPIO_Pin_5);
}

//此处通过推挽输出模式输出PWM波形
//frq:输入的频率
//duty:占空比
void Buzzer_pwm(const uint32_t frq,const uint16_t duty)
{
    uint32_t time;
    if(frq==1000)
        delay_us(1000);    
    else
    {
        time=10000/(uint32_t)frq;
        GPIO_SetBits(GPIOA,GPIO_Pin_5);
        delay_us(time*duty);
        GPIO_ResetBits(GPIOA,GPIO_Pin_5);
        delay_us(time*(100-duty));
    }
}

void bootPOST(void)
{

    for(int i=0;i<2;i++)
    {
        for(int i=1;i<35;i++)
        {
            Buzzer_pwm(700,3);
        }
        delay_ms(100);
    }
    GPIO_ResetBits(GPIOA,GPIO_Pin_5);
}

void Buzzer_voice(void) //响一声
{
    for(int i=0;i<2;i++)
    {
        for(int i=1;i<35;i++)
        {
            Buzzer_pwm(850,5);
        }
    }
    GPIO_ResetBits(GPIOA,GPIO_Pin_5);
}    
