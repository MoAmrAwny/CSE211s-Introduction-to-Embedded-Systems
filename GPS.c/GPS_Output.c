
float* GPS_OUTPUT() {
				
        static float coordinates[2]; // Array to hold latitude and longitude values
			
        char GPS_arr[80]; // Local array to store GPS data
        char received_char;
        char i;
        int log=1;
			  char GPS_logname[]="$GPRMC,";
        // Loop until we receive the required logname
        do {
						log=1;
						 UART_OutString("YOU ENTERED DO WHILE\n");
					   	getCommand(command, len);
						  UART_OutString("\n");
            for (i = 0; i < 7; i++) {
							UART_OutString("YOU ENTERED FOR LOOP\n");
                if (command[i]!=GPS_logname[i]) {//WHEN WE WANT TO TEST GPS WE WILL CHANGE COMMAND TO UART READ
									UART_OutString("YOU ENTERED IF\n");
                   log=0;
									break;
                }
							
           }
					
        } while(log==0);
				
					UART_OutString("YOU EXITED DO WHILE\n");
        // Initialize GPS array
        strcpy(GPS_arr, "");

        // Read GPS data until '*' is received
        while ( received_char != '*')
        {
						UART_OutString("YOU ENTERED THE SEC DO WHILE\n");
            received_char = command[i];
            strcat(GPS_arr, &received_char); // Append received character to GPS array
					i++;
        } 
				
				UART_OutString("YOU EXITED THE SEC DO WHILE\n");
				UART_OutString(GPS_arr);
        // Process GPS data and extract latitude and longitude
        Calc_Coord(GPS_arr,coordinates);

        return coordinates;
}
		
