#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trajectory.h"


	 size_t latSize;
   size_t lonSize;
	 size_t h;
	 char buffer[64];
	 char* combinedString;
	 
// Function to calculate the length of the final string
size_t calculateLength(const float* latitudes, size_t latSize, const float* longitudes, size_t lonSize) {
    size_t totalLength = 0;
    char buffer[64];  // Temporary buffer to hold each pair's string representation

    for ( h = 0; h < latSize; ++h) {
        totalLength += snprintf(buffer, sizeof(buffer), "%.6f, ", latitudes[h]);
    }

    for ( h = 0; h < lonSize; ++h) {
        totalLength += snprintf(buffer, sizeof(buffer), "%.6f, ", longitudes[h]);
    }

    return totalLength + 1; // +1 for the null terminator
}

// Function to combine latitude and longitude arrays into a single character array
char* combineLatLonToString(const float* latitudes, size_t latSize, const float* longitudes, size_t lonSize) {
    // Calculate the length of the resulting string
    size_t length = calculateLength(latitudes, latSize, longitudes, lonSize);

    // Allocate memory for the resulting string
    char* result = (char*)malloc(length * sizeof(char));
    if (result == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    // Combine the arrays into the resulting string
    result[0] = '\0';  // Initialize the result as an empty string
     // Temporary buffer to hold each pair's string representation

    // Append latitudes
    for ( h = 0; h < latSize; ++h) {
        snprintf(buffer, sizeof(buffer), "%.6f, ", latitudes[h]);
        strcat(result, buffer);
    }

    // Append longitudes
    for (h = 0; h < lonSize; ++h) {
        snprintf(buffer, sizeof(buffer), "%.6f, ", longitudes[h]);
        strcat(result, buffer);
    }

    // Replace the last ", " with a newline character
    result[strlen(result) - 2] = '\n';
    result[strlen(result) - 1] = '\0';

    return result;
}

char* trajectory( float *latitudes,float *longitudes){
    // Provided latitude and longitude arrays


    // Sizes of the arrays
    latSize = sizeof(latitudes) / sizeof(latitudes[0]);
    lonSize = sizeof(longitudes) / sizeof(longitudes[0]);

    // Combine the latitude and longitude arrays into a single string
    combinedString = combineLatLonToString(latitudes, latSize, longitudes, lonSize);
		
    if (combinedString == NULL) {
        return 0; // Exit if memory allocation failed
    }

    // Print the combined string

    
		return combinedString;
	
	}

