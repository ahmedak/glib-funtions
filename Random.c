#include <glib.h>
#include <stdio.h>

int main(int argc, char ** argv){
	double r = g_random_double();
	int a,b;
	printf("\nEnter 'a' and 'b' : \n");
	scanf("%i%i", &a,&b);
	int rr = g_random_int_range(a+1,b);
	printf("Random number between 0 & 1: %f",r);
	printf("\nRandom number between %d and %d: %d\n", a, b, rr);
	return 0;
}
