
const int len=80;
char gps[len]={0};
char gps_Check[len]={0};
char GPS_logname[]="$GPRMC,";
int flag=1;
char i=0;



/// ************************************************************************************************************************************* ///



float* GPS_OUTPUT() {
				
        static float coordinates[3]={0,0,0}; // Array to hold latitude and longitude values
        char GPS_arr[80]; // Local array to store GPS data
        char received_char;
        char i=0;
        int log=1;
			  char GPS_logname[]="$GPRMC,";
	    	int j=0;
        // Loop until we receive the required logname
				const int len = 80;
				int m =0;
				//char GPS_Elements[15][15];
				// Tokenization
				char *token;
				char k=0;
				k++;
				
	check:
        do {
						log=1;
					LEDs_output(greenLed);
					  
						
            for (i = 0; i < 7; i++) {
							
                if (UART1_getChar()!=GPS_logname[i]) {
								
                   log=0;
									break;
                }
							
           }
					
        } while(log==0);
				
			
        strcpy(GPS_arr, "");

        // Read GPS data until '*' is received
						 j=0;
				do{
				
				
			  	 received_char = UART1_getChar();
          
				
					GPS_arr[j++]=received_char;
				
				
				
				}while(received_char != '*');
			
			    UART0_OutString(GPS_arr);
					UART0_OutString("\n");
      
		
				m = -1; //should be zero nevermind hussien
				for(token = strtok(GPS_arr, ",") ; token ; token = strtok(NULL , ",") ){			//"203522.00,A,30.06416667,N,31.28055556,W,0.004,133.4,130522,0.0,E,D*2B"
						
					  m++;																																	

						if(m==0){
						 
						    continue;    
						}
            else if(m==1 && *token!='A'){
							m=-1; //should be -1 nevermind hussien
							j =0;
							strcpy( gps , "" );
              goto check;
						}
                
            else if(m==2){
							
						coordinates[0]= str_to_float(token);
						
						UART0_OutString("ana gwa m=2");
						UART0_OutString(token);
						UART0_OutString("\n");
					//	printFloat(coordinates[0]);

							
						}
						else if(m==3){

							if(*token == 'N')
								coordinates[0] = (coordinates[0]);
							else if(*token != 'N')
								coordinates[0] = -(coordinates[0]);
						}

            else if(m==4){
  
							coordinates[1]= str_to_float(token);

						}
						else if(m==5){

							if(*token == 'E')
								coordinates[1] = (coordinates[1]);
							else if(*token != 'E')
								coordinates[1] = -(coordinates[1]);
						}						
            
						else if(m==6) //speed
                coordinates[2]= str_to_float(token);

            else if(m==7){

							m=-1; // should be -1 nevermind hussien
							j =0;
							strcpy( GPS_arr , "" );
							break;
						}
				
                
			}
				
        
  
			
			
						
			
        return coordinates;
			
	
}
		
