
#include "tm4c123gh6pm.h"

#define redLed  0x02
#define greenLed  0x04
#define blueLed  0x08

#define yellowLed  0x06
#define whiteLed  0x0E

#define PF123_mask 0x0E


//*********************************
void LEDs_output(unsigned char data);
void LEDs_Clear();
