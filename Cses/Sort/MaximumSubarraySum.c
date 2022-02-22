#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <limits.h>

long long n, ans, mn, mx, ar[200005];

long long max ( long long a, long long b ) {
	return (a > b ? a : b);
}

long long me ()
{
	long long mme = INT_MIN;
	for ( long long i = 0 ; i < n ; ++i )
		mme = max ( mme, ar[i] );
	assert ( mme != INT_MIN );
	return mme;
}

int main ()
{
	scanf ( "%lld", &n );
	for ( long long i = 0 ; i < n ; ++i ) scanf ( "%lld", ar+i );
	ans = 0; mn = 0; mx = 0;
	for ( long long i = 0 ; i < n ; ++i ) {
		mx = max ( mx + ar[i], 0 );
		ans = max ( ans, mx );
	}
	mn = me ();
	if ( mn < 1 )
		ans = mn;
	printf ( "%lld\n", ans );

	return 0;
}

