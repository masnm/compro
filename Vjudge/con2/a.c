#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

long long t, n, ar[200005], sum, cnt, mid;

void solve ()
{
	scanf ( "%lld", &n );
	for ( int i = 0 ; i < n ; ++i ) scanf ( "%lld", ar + i );
	sum = 0; cnt = 0;
	for ( int i = 0 ; i < n ; ++i ) sum += ar[i];
	if ( sum % n != 0 ) { puts ( "-1" ); return; }
	mid = sum / n;
	for ( int i = 0 ; i < n ; ++i )
		if ( ar[i] > mid )
			++cnt;
	printf ( "%lld\n", cnt );
}

int main ()
{
	scanf ( "%lld", &t );
	while ( t-- )
		solve ();

	return 0;
}

