#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int t;
long long a, b, c;

void swap ( long long* _a, long long* _b )
{
	long long _t = *_a;
	*_a = *_b;
	*_b = _t;
}

int main ()
{
	int cs = 1;
	scanf ( "%d", &t );
	while ( t-- ) {
		scanf ( "%lld%lld%lld", &a, &b, &c );
		for ( int i = 0 ; i < 4 ; ++i ) {
			if ( a > b ) swap ( &a, &b );
			if ( b > c ) swap ( &b, &c );
		}
		printf ( "Case %d: %lld\n", cs++, b );
	}

	return 0;
}

