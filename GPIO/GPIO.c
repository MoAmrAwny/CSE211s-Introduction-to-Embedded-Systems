#include "GPIO.h"
#include "tm4c123gh6pm.h"
#include "bit_utilies.h"



void GPIO_Init_PortA(void){
    SET_BIT(SYSCTL_RCGCGPIO_R , 0);
    while(GET_BIT(SYSCTL_PRGPIO_R,0)==0);
    GPIO_PORTA_CR_R |= 0x03; //allow changes to pin 0->Rx and pin 1->Tx
    GPIO_PORTA_AMSEL_R = 0x00; //disable analog for PortA
    GPIO_PORTA_AFSEL_R = 0x03; //Enable Alternate Function for pins 0,1
    GPIO_PORTA_PCTL_R = 0x11; //PCTL UART ON pins 0,1 
    GPIO_PORTA_DIR_R = 0x02; //pin 0 I/P , pin 1 O/P
    GPIO_PORTA_DEN_R = 0x03; //Digital Enable for pins 0,1
}


void GPIO_Init_PortF(void){

SET_BIT(SYSCTL_RCGCGPIO_R , 5); //Configuration of clock of portF
while((GET_BIT(SYSCTL_PRGPIO_R,5)==0)); 
GPIO_PORTF_LOCK_R=GPIO_LOCK_KEY;
GPIO_PORTF_CR_R|= 0x1F ; //allow changes to pins 1 ,2 and 3 for portF 
GPIO_PORTF_AMSEL_R &= ~0x1F; //disable analog for PortF
GPIO_PORTF_AFSEL_R &= ~0x1F; //Disable Alternate Function for PortF
GPIO_PORTF_PCTL_R &= 0x0000000; // clear bits in PCTL
GPIO_PORTF_DIR_R |= 0x0E ; // O/P direction for pins 1 ,2 & 3 & I/P direction for pins 0 & 4 
GPIO_PORTF_DEN_R |= 0x1F; // Digital Enable for PortF
GPIO_PORTF_DATA_R &= ~0x0E; // Data=1 on pins 0 , 4 & Data=0 on pins 1 , 2 & 3
GPIO_PORTF_PUR_R = 0x11; // Enable pullup
}
unsigned char read_switch2(){
	return GPIO_PORTF_DATA_R &0x01;
}


//check if the switch is pressed or not
void LEDs_output(unsigned char data){
	GPIO_PORTF_DATA_R &= ~PF123_mask ; // clear the LEDs data first
	GPIO_PORTF_DATA_R |= data ; // then set the LEDs data
}

void LEDs_Clear(){
	GPIO_PORTF_DATA_R &= ~PF123_mask ; 
}
