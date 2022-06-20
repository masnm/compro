#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int ar[105];
int n, k, l, r, ans;

int main ()
{
	scanf ( "%d%d", &n, &k );
	for ( int i = 0 ; i < n ; ++i ) scanf ( "%d", ar+i );
	l = 0; r = n - 1; ans = 0;
	while ( l <= r ) {
		if ( ar[l] <= k ) {
			++ans; ++l;
		} else if ( ar[r] <= k ) {
			++ans; --r;
		} else break;
	}
	printf ( "%d\n", ans );

	return 0;
}

