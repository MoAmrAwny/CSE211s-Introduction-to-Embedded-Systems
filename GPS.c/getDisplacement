/////////////////////////displacement function////////////////////////////
		
float getDisplacement(float currentLat, float currentLong,float desiredLat, float desiredLong)
{
    // get radian angle
    float currentLongRad = toRad(ToDegree (currentLong));   /*  convert coordinates to radian   */
    float currentLatRad = toRad(ToDegree (currentLat));
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
