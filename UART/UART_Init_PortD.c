void UART_Init_PortD()
{      // PD6 / PD7  U2Rx / U2Tx               
	
	SYSCTL_RCGCGPIO_R |= 0x0008; 	// activate port D
	SYSCTL_RCGCUART_R |= 0x0004; 		// activate UART2
	UART2_CTL_R &= ~0x0001; 		// disable UART
	UART0_IBRD_R = 104; 			// IBRD=int(16M / (16*9600)) = int(104.166)
	UART0_FBRD_R = 11; 		// FBRD = round(0.166 * 64) + 0.5 = 11
	UART0_LCRH_R = 0x0070; 		// 8-bit word length, enable FIFO
	UART0_CTL_R = 0x0301; 		// enable RXE, TXE and UART
	GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R&0xFFFFFF00)+0x00000011; 		// UART
	GPIO_PORTD_AMSEL_R &= ~0xC0; 		// disable analog function on PD7-6
	GPIO_PORTD_AFSEL_R |= 0xC0; 		// enable alt funct on PD7-6
	GPIO_PORTD_DEN_R |= 0xC0; 		// enable digital I/O on PD7-6

}
