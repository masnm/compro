#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

int main ()
{
	for ( int i = 0 ; i < 2 ; ++i ) {
		char x[15];
		scanf ( "%[^\n]\n", x );
		printf ( "%s %lu\n", x, strlen ( x ) );
	}

	return 0;
}

