#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int main ()
{
	int t; scanf ( "%d", &t );
	while ( t-- ) {
		int a, b; scanf ( "%d%d", &a, &b );
		if ( a % b == 0 ) { puts ( "0" ); continue; }
		printf ( "%d\n", ((a/b)+1)*b - a );
	}

	return 0;
}

