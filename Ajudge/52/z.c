#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( int argc, char* argv[] )
{
	int t; scanf ( "%d", &t );
	while ( t-- ) {
		int a, b, c; scanf ( "%d%d%d", &a, &b, &c );
		puts ( a+b+c==180?"YES":"NO" );
	}

	return 0;
}

