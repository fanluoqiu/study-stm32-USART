#include "serial.h"


void Serialprint_init(void)
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

    //TX
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;
    GPIO_InitStruct.GPIO_Pin=GPIO_Pin_2;
    GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&GPIO_InitStruct);

    //RX
    GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPU;
    GPIO_InitStruct.GPIO_Pin=GPIO_Pin_3;
    GPIO_Init(GPIOA,&GPIO_InitStruct);


    USART_InitTypeDef USART_InitStruct;
    USART_InitStruct.USART_BaudRate=9600;
    USART_InitStruct.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
    USART_InitStruct.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
    USART_InitStruct.USART_Parity=USART_Parity_No;
    USART_InitStruct.USART_StopBits=USART_StopBits_1;
    USART_InitStruct.USART_WordLength=USART_WordLength_8b;
    USART_Init(USART2,&USART_InitStruct);
    USART_Cmd(USART2,ENABLE);


    NVIC_InitTypeDef NVIC_InitStruct;
    NVIC_InitStruct.NVIC_IRQChannel=USART2_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=0;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority=0;
    NVIC_Init(&NVIC_InitStruct);
    USART_ITConfig(USART2,USART_IT_RXNE,ENABLE);
}

void Serialprint(uint8_t data)
{
    USART_SendData(USART2,data);
    while (USART_GetFlagStatus(USART2,USART_FLAG_TXE)==RESET);
}

