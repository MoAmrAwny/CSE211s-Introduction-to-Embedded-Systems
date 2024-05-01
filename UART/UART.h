#include "tm4c123gh6pm.h"
#define CR 0x0D	

//void UART_Init_PortD(void);
void UART_Init_PortA(void);

void UART_OutString(char *pt);
void RGB_clearOutput(unsigned char data);
void RGB_setOutput(unsigned char data);
void getCommand(char *command, int length);
void UART_OutChar(unsigned char data);
char UART_InChar();


