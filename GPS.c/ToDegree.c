

	float ToDegree (float angle){
	int degree = (int)angle/100 ; 
	float minutes = angle -(float)degree*100;
		return (degree + (minutes/60) );
}
