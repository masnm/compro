#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int nax = 100000;

int main ()
{
	printf ( "%d\n", nax );
	for ( int i = 0 ; i < nax ; ++i ) {
		printf ( "%d\n", (rand()%1001) + 12 );
	}

	return 0;
}

