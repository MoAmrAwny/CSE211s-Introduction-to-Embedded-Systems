
void SW2_Init(void)

{

	GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY ; // unlock portF
	GPIO_PORTF_CR_R |= PF_SW2_mask ; // allow changes on SW2 PF0
	GPIO_PORTF_AMSEL_R &= ~(PF_SW2_mask); // 0x01 = PF_SW2_mask , disable the analog input
	GPIO_PORTF_AFSEL_R &= ~(PF_SW2_mask); // 0x01 = PF_SW2_mask , disable the alternate functions
	GPIO_PORTF_PCTL_R &= ~(0x0000000F); // clear the desired bits PCTL PF0 
	GPIO_PORTF_DIR_R &= ~PF_SW2_mask ; // enable direction of I/O , set the SW2 pin to be input
	GPIO_PORTF_DEN_R |= PF_SW2_mask ; // enable digital I/O
	GPIO_PORTF_PUR_R |= PF_SW2_mask ; // pull up the switch 

}


unsigned char read_switch2()

{

	return GPIO_PORTF_DATA_R &0x01;

}
