void Calc_Coord (char GPS_arr[],float coordinates[])
{
// *  logname  date      lattitude      longitude
// *  $GPRMC,043438.00,A,1833.62410,N,07354.76336,E,0.024,,070319,,,A*78
//                     |            |             |
//                    valid        North         East
    // GPS_arr[80] = "043438.00,A,30.0640669,N,31.2804439,E,0.024,,070319,,,A*78";
   // float coordinates[2];
    const int len = 80;
    char GPS_Elements[15][15];
    // Tokenization
    char *token = strtok(GPS_arr, ",");
    int i = 0;
    while (token != NULL && i < 15) {
        strcpy(GPS_Elements[i], token);
        token = strtok(NULL, ",");
        i++;
    }

    // Data extraction
   if (strcmp(GPS_Elements[1], "A") == 0) {  //strcmp( )  if the two operands are equal it returns zero
        if (strcmp(GPS_Elements[3], "N") == 0) {
           
            coordinates[0] = strtof(GPS_Elements[2], NULL); // Latitude assigned to coordinates[0]
        }
        else {
           
            coordinates[0] = -strtof(GPS_Elements[2], NULL); // Latitude assigned to coordinates[0]
        }

        if (strcmp(GPS_Elements[5], "E") == 0) {
           
            coordinates[1] = strtof(GPS_Elements[4], NULL); // Longitude assigned to coordinates[1]
        }
        else {
            
            coordinates[1] = -strtof(GPS_Elements[4], NULL); // Longitude assigned to coordinates[1]
        }

    }
    //cout<<coordinates[0] <<"\n"<<coordinates[1];
    //return getDistance(lattitude,longitude,30.0633998,31.2784695);
}
