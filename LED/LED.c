
//***********************************************************
//**********   Hardware architecture layer   ****************
//***********************************************************

#include "LED.h"

void LEDs_output(unsigned char data){
	GPIO_PORTF_DATA_R &= ~PF123_mask ; // clear the LEDs data first
	GPIO_PORTF_DATA_R |= data ; // then set the LEDs data
}

void LEDs_Clear(){
	GPIO_PORTF_DATA_R &= ~PF123_mask ; 
}
