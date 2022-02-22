#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int t, n, ar[200005], unc, mcc, cc, prev;

int min ( const void* a, const void* b )
{ return *(int*)a - *(int*)b; }
int max ( int a, int b )
{ return (a>b?a:b); }

void solve ()
{
	scanf ( "%d", &n );
	for ( int i = 0 ; i < n ; ++i ) scanf ( "%d", ar + i );
	qsort ( ar, n, sizeof(int), min );
	mcc = 0; unc = 0; cc = 1; prev = -1;
	for ( int i = 0 ; i < n ; ++i ) {
		if ( ar[i] == prev ) {
			++cc;
		} else {
			prev = ar[i];
			mcc = max ( mcc, cc );
			cc = 1;
			++unc;
		}
	}
	mcc = max ( mcc, cc );
	if ( unc > mcc )
		printf ( "%d\n", mcc );
	else if ( unc == mcc )
		printf ( "%d\n", mcc - 1 );
	else
		printf ( "%d\n", unc );
}

int main ()
{
	scanf ( "%d", &t );
	while ( t-- )
		solve ();

	return 0;
}

