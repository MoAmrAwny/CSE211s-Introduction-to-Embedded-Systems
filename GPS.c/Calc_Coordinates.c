
void Calc_Coord (char GPS_arr[],float coordinates[])
{
// *  logname  date      lattitude      longitude
// *  $GPRMC,043438.00,A,1833.62410,N,07354.76336,E,0.024,,070319,,,A*78
//                     |            |             |
//                    valid        North         East

    const int len = 80;
    char GPS_Elements[15][15];
    // Tokenization
    char *token = strtok(GPS_arr, ","); 
    int i = 0;
    while (token != NULL && i < 15) 
    {
        strcpy(GPS_Elements[i], token);
        token = strtok(NULL, ",");
        i++;
    }

    // Data extraction
    if (strcmp(GPS_Elements[1], "A") == 0) // strcmp() vif equal returns 0
      {
            if (strcmp(GPS_Elements[3], "N") == 0) { // incase of North the value will be positive
    					  coordinates[0]= atof(GPS_Elements[2]);
    						UART_OutString(GPS_Elements[2]);
            }
    				else {
                coordinates[0]= -atof(GPS_Elements[2]); // incase of South the value will be negative
    					
            }
    
            if (strcmp(GPS_Elements[5], "E") == 0) { // incase of East the value will be positive
    				
              coordinates[1]= atof(GPS_Elements[4]);
    				 	
            } 
    				else{
              coordinates[1]= -atof(GPS_Elements[4]); // incase of West the value will be negative
    					
            }
   
     }
    
}
