#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



float fpow(float x, float pow){
	float result = 1;
	for (int i = 0; i < pow; ++i){
		result*=x;
	}
	return result;
}

int main(){
	float x = fpow(2, 5);
	printf("%.5f\n", x);
	return 0;
}
