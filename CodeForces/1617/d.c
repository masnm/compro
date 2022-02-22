#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int ar[4];
int get ( int a, int b, int c )
{
	int zc = 0, oc = 0;
	ar[a] ? ++oc : ++zc;
	ar[b] ? ++oc : ++zc;
	ar[c] ? ++oc : ++zc;
	return ( zc > oc ? 0 : 1 );
}

int main ()
{
	for ( int mask = 0 ; mask < (1<<4) ; ++mask ) {
		for ( int i = 0 ; i < 4 ; ++i ) {
			if ( mask & (1 << i) ) ar[i] = true;
			else ar[i] = false;
		}
		printf ( "PQR  : %d\n", get(1, 2, 3) );
		printf ( "PQ S : %d\n", get(0, 2, 3) );
		printf ( "P RS : %d\n", get(0, 1, 3) );
		printf ( " QRS : %d\n", get(0, 1, 2) );
		printf ( "%d%d%d%d\n", get(3,3,3), get(2,2,2), get(1,1,1), get(0,0,0) );
		puts ( "\n" );
	}

	return 0;
}

