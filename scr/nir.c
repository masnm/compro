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

	int x, y;
	printf ( "Enter first number : " );
	scanf ( "%d", &x );
	printf ( "Enter second number : " );
	scanf ( "%d", &y );

	if ( x < y ) {
		int t = x;
		x = y;
		y = t;
	}

	printf ( "%d is greater than %d\n", x, y );

	return 0;
}

