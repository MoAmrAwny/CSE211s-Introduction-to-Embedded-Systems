
void UART_OutChar(unsigned char data)
{
	while((UART0_FR_R & 0x20)!=0);
	
	UART0_DR_R = data;
}
