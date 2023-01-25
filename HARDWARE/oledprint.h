#ifndef OLEDPRINT_H
#define OLEDPRINT_H

#include "OledDriver.h"
void OLEDintset(void);
void OLEDloding(u8 x,u8 y,u8 sizex,u8 sizey,u8 BMP[],u8 mode,uint64_t delayms);
void toptitle(u8 str[],u8 mode);
void print_p(u8 x,u8 y, uint32_t  addr);
void OLED_maininterf(void);
#endif  

