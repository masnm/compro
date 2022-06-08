#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

const int INF = 1e9;
int *first, *second, ar[15][15], health[15], dmg[15];
int sz = (1<<15);
char ch[20];

void pswap ()
{ int* temp = first; first = second; second = temp; }

int imax ( int a, int b ) { return ( a > b ? a : b ); }
int imin ( int a, int b ) { return ( a < b ? a : b ); }

void solve ()
{
	int n; scanf ( "%d", &n );
	for ( int i = 0 ; i < n ; ++i )
		scanf ( "%d", &health[i] );
	for ( int i = 0 ; i < n ; ++i ) {
		scanf ( "%s", ch );
		for ( int j = 0 ; j < n ; ++j )
			ar[i][j] = ch[j] - '0';
	}
	sz = (1<<n);

	for ( int i = 0 ; i < sz ; ++i ) second[i] = 0;
	int cur, nindex, nval;
	for ( int row = 0 ; row < n ; ++row ) {
		pswap ();
		for ( int i = 0 ; i < sz ; ++i ) second[i] = INF;
		for ( int col = 0 ; col < n ; ++col ) {
			cur = (1 << col);
			for ( int item = 0 ; item < sz ; ++item ) {
				if ( item & cur ) continue;
				for ( int i = 0 ; i < n ; ++i ) dmg[i] = 1;
				for ( int i = 0 ; i < n ; ++i ) {
					if ( item & (1<<i) )
						for ( int j = 0 ; j < n ; ++j )
							dmg[j] = imax ( dmg[j], ar[i][j] );
				}
				nindex = item | cur;
				nval = first[item] +
					((health[col] / dmg[col]) + (health[col]%dmg[col]==0?0:1));
				second[nindex] = imin ( second[nindex], nval );
			}
		}
		for ( int i = 0 ; i < sz ; ++i ) printf ( "%d ", first[i] );
		printf ( "\n" );
		for ( int i = 0 ; i < sz ; ++i ) printf ( "%d ", second[i] );
		printf ( "\n" );
	}
	printf ( "%d\n", second[sz-1] );
}

int main ()
{
	first = (int*) malloc ( sizeof(int) * sz );
	second = (int*) malloc ( sizeof(int) * sz );
	int t; scanf ( "%d", &t );
	for ( int i = 0 ; i < t ; ++i ) {
		printf ( "Case %d: ", i+1 );
		solve ();
	}
	free ( first );
	free ( second );

	return 0;
}

