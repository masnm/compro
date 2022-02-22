#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int t, n, d, ar[105];

int min ( const void* a, const void* b )
{
	return *(int*)a - *(int*)b;
}

bool all ()
{
	for ( int i = 0 ; i < n ; ++i )
		if ( ar[i] > d )
			return false;
	return true;
}

void solve ()
{
	scanf ( "%d%d", &n, &d );
	for ( int i = 0 ; i < n ; ++i ) scanf ( "%d", &ar[i] );
	qsort ( ar, n, sizeof(int), min );
	if ( all () ) {
		puts ( "YES" );
		return;
	}
	if ( ar[0] + ar[1] <= d )
		puts ( "YES" );
	else
		puts ( "NO" );
}

int main ()
{
	scanf ( "%d", &t );
	while ( t-- )
		solve ();

	return 0;
}

