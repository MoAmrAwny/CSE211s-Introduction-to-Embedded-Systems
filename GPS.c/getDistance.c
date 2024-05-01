//////////////////////////convert angle to radian////////////////////////////
float toRad(float angle){
    return angle * (pi/180);
}

/*The haversine formula determines the great-circle distance between two points on a sphere given their longitudes and latitudes.*/

float getDistance(float currentLat, float currentLong,float desiredLat, float desiredLong)
{
    // get radian angle
    float currentLongRad = toRad(currentLong);   /*  convert coordinates to radian   */
    float currentLatRad = toRad(currentLat);
    float desiredLongRad =toRad(desiredLong);
    float desiredLatRad = toRad(desiredLat);

    // get difference
    float longDifference = desiredLongRad - currentLongRad;
    float latDifference = desiredLatRad - currentLatRad;

    // calculate distance
    double a = sin(latDifference/2)*sin(latDifference/2)+(cos(currentLatRad)*cos(desiredLatRad)*sin(longDifference/2)*sin(longDifference/2)); // haversine formula
    double c = 2* atan2(sqrt(a),sqrt(1-a));

    return Earth_Radius * c;
}
