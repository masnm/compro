#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <limits.h>

const long long inf = LLONG_MAX;
long long n, b, h, w, mn, cost, tc, t;

int main ()
{
	while ( scanf ( "%lld%lld%lld%lld", &n, &b, &h, &w ) != EOF ) {
		mn = inf;
		for ( long long i = 0 ; i < h ; ++i ) {
			scanf ( "%lld", &cost );
			for ( long long j = 0 ; j < w ; ++j ) {
				scanf ( "%lld", &t );
				if ( t >= n ) {
					tc = cost * n;
					if ( tc < mn )
						mn = tc;
				}
			}
		}
		if ( mn <= b ) {
			printf ( "%lld\n", mn );
		} else {
			puts ( "stay home" );
		}
	}

	return 0;
}

