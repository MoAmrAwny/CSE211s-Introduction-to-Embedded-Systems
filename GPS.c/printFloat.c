void printFloat(float a){
 char array[10];
	sprintf(array,"%.6f",a);
	UART0_OutString(array);

}
