#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int t, n;
long long ar[200005], ans;

long long max ( long long a, long long b ) { return (a>b?a:b); }
int min ( const void* a, const void* b ) { return *(long long*)a - *(long long*)b; }

void solve ()
{
	scanf ( "%d", &n );
	for ( int i = 0 ; i < n ; ++i )
		scanf ( "%lld", &ar[i] );
	qsort ( ar, n, sizeof(long long), min );
	ans = ar[0];
	for ( int i = 0 ; i < n - 1 ; ++i )
		ans = max ( ans, ar[i+1] - ar[i] );
	printf ( "%lld\n", ans );
}

int main ()
{
	scanf ( "%d", &t );
	while ( t-- )
		solve ();

	return 0;
}
