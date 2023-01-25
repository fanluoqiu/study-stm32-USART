#ifndef BUZZER_H
#define BUZZER_H

#include "stm32f10x.h"
#include "delay.h"

typedef enum {OPEN_BUZZER=1,CLOSE_BUZZER=!OPEN_BUZZER} BUZZERSTATE;



//basic
void Buzzer_init(void);

void Buzzer_pwm(const uint32_t frq,const uint16_t duty);



//function
void bootPOST(void);
void Buzzer_voice(void);
#endif

