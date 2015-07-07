#include <glib.h>
#include <stdio.h>

int main(int argc, char ** argv){
	
	// Random number between 0 & 1
	double r = g_random_double();
	printf("Random number between 0 & 1: %f",r);
	
	// Random integer between a & b
	int a,b;
	printf("\nEnter 'a' and 'b' : \n");
	scanf("%i%i", &a,&b);
	int rr = g_random_int_range(a+1,b);
	printf("\nRandom number between %d and %d: %d\n", a, b, rr);
	return 0;
}
