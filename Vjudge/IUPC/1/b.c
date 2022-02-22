#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define ars 100005
#define dev 1
#define rog 2
int ar[ars];
int arb[ars];

void clrs ()
{
	for ( int i = 0 ; i < ars ; ++i ) ar[i] = 0;
	for ( int i = 0 ; i < ars ; ++i ) arb[i] = 0;
}

void solve ()
{
	int n, d, r;
	scanf ( "%d%d%d", &n, &d, &r );
	clrs();
	int ls = 0, rs = 0;
	for ( int i = 1 ; true ; ++i ) {
		ls = (i*d)%n;
		rs = (i*r)%n;
		if ( arb[ls] != 0 ) {
			printf ( "%d\n", i );
			return;
		}
		ar[ls] = dev;
		if ( ar[rs] != 0 ) {
			printf ( "%d\n", i );
			return;
		}
		arb[rs] = rog;
	}
}

int main ()
{
	int t;
	scanf ( "%d", &t );
	while ( t-- ) {
		solve();
	}

	return 0;
}
