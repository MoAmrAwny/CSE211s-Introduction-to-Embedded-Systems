
void UART_OutString(char *pt)
{
	 while(*pt)
   {
		 UART_OutChar(*pt);
		 pt++ ;
	 }
}
