
#include <stdio.h>
#include <limits.h>
#include <float.h>


int main() {

	int integer_variable = INT_MAX;
    	float float_variable = FLT_MAX;
    	double double_variable = DBL_MAX;

	//Size of Variable
	printf("-> Integer Size: %lu\n", sizeof(integer_variable));
	printf("-> Double Size: %lu\n", sizeof(double_variable));
	printf("-> Float Size: %lu\n", sizeof(float_variable));

	//Max Value of Variable
	printf("-> Integer MAX Value: %d\n", integer_variable);
	printf("-> Float MAX Value: %f\n", float_variable);
    	printf("-> Double MAX Value: %f\n", double_variable);
    
return 0;
}