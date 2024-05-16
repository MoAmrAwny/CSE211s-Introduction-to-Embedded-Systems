#ifndef UART
#define UART


///*	UART 0 Init	*///
void UART0_Init(void);

///*	UART 0 functions	*///
char UART0_getChar();
void UART0_OutChar(char data);
void UART0_OutString(char *pt);
void GetCommand_UART0(char *Command,int len );

void GetCommand_UART1_Modified(char *Command,int len );


///*	UART 1 Init	*///
void UART1_Init (void);

///*	UART 1 functions	*///
char UART1_getChar();
void UART1_OutChar(char data);
void UART1_OutString(char *pt);
void GetCommand_UART1(char *Command,int len );



#endif
