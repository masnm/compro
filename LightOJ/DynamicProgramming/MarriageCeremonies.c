#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int *first, *second;
int sz = (1<<16);

int imax ( int a, int b ) { return ( a > b ? a : b ); }

void pswap ()
{
	int *temp = first;
	first = second;
	second = temp;
}

void solve ()
{
	int n, t, index, nindex, nval;
	scanf ( "%d", &n );
	sz = (1<<n);
	for ( int row = 0 ; row < n ; ++row ) {
		pswap ();
		for ( int i = 0 ; i < sz ; ++i ) second[i] = 0;
		for ( int col = 0 ; col < n ; ++col ) {
			scanf ( "%d", &t );
			index = (1<<col);
			for ( int i = 0 ; i < sz ; ++i )
				if ( ( i & index ) == 0 ) {
					nindex = i | index;
					nval = first[i] + t;
					second[nindex] = imax ( second[nindex], nval );
				}
			// for ( int i = 0 ; i < sz ; ++i )
			// 	printf ( "%d ", first[i] );
			// printf ( "\n" );
			// for ( int i = 0 ; i < sz ; ++i )
			// 	printf ( "%d ", second[i] );
			// printf ( "\n" );
		}
	}
	printf ( "%d\n", second[sz-1] );
}

int main ()
{
	first = (int*) malloc ( sizeof(int)*sz );
	second = (int*) malloc ( sizeof(int)*sz );
	for ( int i = 0 ; i < sz ; ++i ) first[i] = second[i] = 0;

	int t; scanf ( "%d", &t );
	for ( int i = 0 ; i < t ; ++i ) {
		printf ( "Case %d: ", i+1 );
		solve ();
	}

	free ( first );
	free ( second );
	return 0;
}

