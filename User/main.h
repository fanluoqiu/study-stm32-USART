#ifndef MAIN_H
#define MAIN_H

typedef enum {mode_TX=0,mode_RX=1,mode_default=2} OLED_maininterf_mode ;


OLED_maininterf_mode GetShowMode(void);


#endif 
