#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


float factorial(float x){ 
	float result = 1;
	for (int i = 2; i <= x; ++i){
		(result *= i); 
	}
	return result;
}



float fpow(float x, float pow){ 
	float result = 1;
	for (int i = 0; i < pow; ++i){
		result *= x;
	}
	return result;
}
