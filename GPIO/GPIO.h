#include "BitStatus.h"
#include "tm4c123gh6pm.h"

#define PF_SW2_mask  0x01


///***  FUNCTIONS  ***///
void GPIO_PortA_Init();
void portF_Init();
void SW2_Init(void);

//PF_SW2_mask
unsigned char GPIO_getSwitchValue(unsigned char sw);
void GPIO_setLedValue(unsigned char ledColor, unsigned char ledState);
void GPIO_PORTA_setPort(unsigned char sevenSegmentValue);

//switch
unsigned char read_switch2();
