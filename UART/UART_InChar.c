
char UART_InChar()
{
	while((UART0_FR_R & 0x10)!=0);
	
	return (char)UART0_DR_R;
}
