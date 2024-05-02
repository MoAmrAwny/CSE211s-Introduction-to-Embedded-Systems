#include "tm4c123gh6pm.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define logname_length        7
#define pi                    3.14159265359
#define Earth_Radius          6371000
#define finalDestinationLat   30.0640669
#define finalDestinationLong  31.2804439



float toRad(float angle);
float getDistance(float currentLong, float currentLat, float desiredLong, float desiredLat);
char UART_Read ();
float* GPS_OUTPUT();
void Calc_Coord ();
float totalDistance(float totalDisplacement);
