#include "GPS.h"

#include "UART.h"

#include "GPIO.h"

#include "LED.h"

#include "Timer.h"


int main() {
  UART_Init_PortA();
  portF_Init();
  SW2_Init();
  Systick_Init();

  while (1) {

    unsigned char SW_value;
    float * coordinates;
    float starting_latitude, starting_longitude;
    float totalDisplacment, totaldistance;

    //float finalDestination[]={30.0640669,31.2804439};  // destination coordinates of credit building

    /*program sstarts with redLed on, and exit when switch 2 is pressed*/
    do {
      LEDs_output(redLed);

      SW_value = read_switch2();

    } while (SW_value == 1);

    // redLed off
    LEDs_Clear(redLed);
    // blueLed on
    LEDs_output(blueLed);

    //taking the lattitude and the magnitude from the gps   
    coordinates = GPS_OUTPUT();
    starting_latitude = coordinates[0];
    starting_longitude = coordinates[1];

    //calculating the displacment between the intial and final position
    totalDisplacment = getDistance(starting_latitude, starting_longitude, finalDestinationLat, finalDestinationLong);

    // loop to calculate the total distance covered till we reach the distination 
    totaldistance = totalDistance(totalDisplacment);

    // blue led off
    LEDs_Clear(blueLed);

    do {
      /*
      	code waiting to start the program again
      */
      // green led on	that means that we arrived
      LEDs_output(greenLed);

    } while (SW_value == 1);

    LEDs_Clear(greenLed);
  }
  return 0;
}
