#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <limits.h>

typedef long long int ll;

int inc ( const void* a, const void* b )
{
	if ( *(ll*)a == *(ll*)b ) return 0;
	else if ( *(ll*)a > *(ll*)b ) return 1;
	else return -1;
}

ll min ( ll l, ll r ) { return (l<r?l:r); }
ll max ( ll l, ll r ) { return (l>r?l:r); }

ll n, ar[200005], r, prev, ls, rs, dif, ans;

int main ()
{
	r = scanf ( "%lld", &n );
	for ( int i = 0 ; i < n ; ++i ) r = scanf ( "%lld", ar+i );
	qsort ( ar, n, sizeof(ll), inc );
	prev = ar[n-1]; ls = 0; rs = 0; ans = LLONG_MAX;
	for ( int i = 0 ; i < n ; ++i ) ls += ( ar[n-1] - ar[i] );
	for ( int i = n - 1 ; i > -1 ; --i ) {
		dif = prev - ar[i];
		ls -= ( dif * (i+1) );
		rs += ( dif * (n-i-1) );
		ans = min ( ans, ls + rs );
		prev = ar[i];
	}
	printf ( "%lld\n", ans );

	return 0;
}

