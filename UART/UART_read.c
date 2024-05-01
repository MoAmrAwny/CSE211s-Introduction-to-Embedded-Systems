
char UART_Read () 
{
	
  while((UART0_FR_R &0x10)!=0);     // check if the buffer is empty
  return (char)(UART0_DR_R & 0xFF) ;//return the first 8 bits that contains Data

}
