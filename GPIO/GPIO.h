#ifndef GPIO
#define GPIO


#define redLed  0x02
#define greenLed  0x08
#define blueLed  0x04

#define yellowLed  0x06
#define whiteLed  0x0E
#define PF123_mask 0x0E

#include "tm4c123gh6pm.h"


//*********************************
void LEDs_output(unsigned char data);
void LEDs_Clear();


void GPIO_Init_PortA(void);
void GPIO_Init_PortF(void);
unsigned char read_switch2();
#endif
