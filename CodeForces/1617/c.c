#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef long long int ll;

#define nax 200005
ll inp[nax];
bool v[nax];
ll need[nax];

int qmin ( const void* a, const void* b )
{
	return (*(ll*)a - *(ll*)b);
}

void do_task ()
{
	int n; scanf ( "%d", &n );
	for ( int i = 0 ; i < n+5 ; ++i ) v[i] = false;
	int count = 0, nc = 0;
	for ( int i = 0 ; i < n ; ++i ) {
		scanf ( "%lld", &inp[count] );
		if ( inp[count] > n ) {
			need[nc++] = inp[count];
		} else if ( v[inp[count]] ) {
			need[nc++] = inp[count];
		} else if ( !v[inp[count]] ) {
			v[inp[count]] = true;
		} else {
			assert ( false );
		}
	}
	qsort ( need, nc, sizeof(ll), qmin );
	bool ans = true;
	int next = 1;
	ll cnt = 0;
	// for ( int i = 0 ; i < nc ; ++i ) {
	// 	printf ( "%lld ", need[i] );
	// }
	// puts ( "");
	// return;
	for ( int i = 0 ; i < nc ; ++i ) {
		while ( v[next] ) ++next;
		if ( next > n ) {
			ans = false;
			break;
		}
		ll num = need[i];
		ll ms = num - next;
		// printf ( "%lld %lld %lld - ", num, ms, next );
		if ( ms <= next ) {
			ans = false;
			break;
		}
		v[next] = true;
		++cnt;
	}
	if ( ans ) {
		printf ( "%lld\n", cnt );
	} else {
		puts ( "-1" );
	}
}

int main ()
{
	int t;
	scanf ( "%d", &t );
	while ( t-- )
		do_task ();

	return 0;
}

