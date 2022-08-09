#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( int argc, char* argv[] )
{
	(void) argc;
	(void) argv;

	int a, b, c;
	printf ( "Enter first number : " );
	scanf ( "%d", &a );
	printf ( "Enter second number : " );
	scanf ( "%d", &b );
	printf ( "Enter third number : " );
	scanf ( "%d", &c );

	if ( a < b ) {
		int t = a;
		a = b;
		b = t;
	}
	if ( a < c ) {
		int t = a;
		a = c;
		c = t;
	}

	printf ( "%d is greter than both %d and %d.\n", a, b, c );

	return 0;
}

