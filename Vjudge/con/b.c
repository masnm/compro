#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int n, l, r, rc, ar[1000005], ac, ned, con, t;

void solve ()
{
	scanf ( "%d%d", &l, &r );
	ac = 0; rc = r;
	while ( l != 1 ) {
		int dv = l/r;
		int su = l - (dv * r);
		ar[ac++] = dv;
		l = su;
		t = l; l = r; r = t;
	}
	if ( ac == 0 ) {
		printf ( "%d %d %d\n", 1, 0, r );
		return;
	} else {
		printf ( "%d ", ac - 1 );
		for ( int i = 0 ; i < ac ; ++i )
			printf ( "%d ", ar[i] );
		puts ( "" );
	}
}

int main ()
{
	scanf ( "%d", &n );
	while ( n-- )
		solve ();

	return 0;
}

