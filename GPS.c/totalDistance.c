
		float totalDistance(float totalDisplacement)
		{
			
		float *reading_coordinates;
		char finally_arrived=1 ; //flag
		float lati1, longi1,lati2,longi2,x,sum=0;
		float current_vs_final;
			  reading_coordinates= GPS_OUTPUT();
			 	lati1= reading_coordinates[0];     //start point
				longi1 =reading_coordinates[1];
			
		while(finally_arrived)
			{
			
			  Systick_wait10ms(100);
			
				reading_coordinates= GPS_OUTPUT();
				lati2= reading_coordinates[0];     //second point
				longi2 =reading_coordinates[1];
				 
			  x=getDistance( lati1, longi1 , lati2,  longi2); 
				sum=x+sum; 
				
				current_vs_final = getDistance(lati2,longi2,finalDestinationLat,finalDestinationLong);
        if (current_vs_final <= (0.05*totalDisplacement))
					{
            finally_arrived=0;
						LEDs_Clear(blueLed);  // blue led off
						LEDs_output(greenLed);  // green led on	
					}
					lati1=lati2;
					longi1=longi2;
        				
			}
			return sum;		
		} 

