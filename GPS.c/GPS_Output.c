float* GPS_OUTPUT() {
	
        static float coordinates[2];    // Array to hold latitude and longitude values
        char GPS_arr[80];              // Local array to store received GPS data
        char received_char;
        char i;                        //used for iteration over for_loop below
        int flag=1;
	char GPS_logname[]="$GPRMC,"; //the required logname we want to receive

do {                         // Loop until we receive the required logname
	     flag=1;
	     UART_OutString("YOU ENTERED THE FIRST DO WHILE\n");
	     getCommand(command, len);
	     UART_OutString("\n");
            for (i = 0; i < 7; i++) {
		   UART_OutString("YOU ENTERED FOR LOOP\n");
                if (command[i]!=GPS_logname[i]) {           //WHEN WE WANT TO TEST GPS WE WILL CHANGE COMMAND TO UART READ "manual testing"
		   UART_OutString("YOU ENTERED IF\n");
                   log=0;
                   break;
                }
							
             }   
					
   } while(log==0);
				
	UART_OutString("YOU EXITED THE FIRST DO WHILE\n");            
        strcpy(GPS_arr, "");                               // Initialize GPS array
        while ( received_char != '*'){                     // Read GPS data until '*' is received
	    UART_OutString("YOU ENTERED THE SECOND WHILE LOOP\n");
            received_char = command[i];  
            strcat(GPS_arr, &received_char);              // Append received character to GPS array
	     i++;
        } 
				
	  UART_OutString("YOU EXITED THE SECOND DO WHILE\n");
	  UART_OutString(GPS_arr);
        
        Calc_Coord(GPS_arr,coordinates);                  // Process GPS data and extract latitude and longitude

        return coordinates;
}
      
		
