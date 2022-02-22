#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int t;
long long a, b;

int main ()
{
	scanf ( "%d", &t );
	while ( t-- ) {
		scanf ( "%lld%lld", &a, &b );
		if ( a > b ) {
			puts ( ">" );
		} else if ( a < b ) {
			puts ( "<" );
		} else {
			puts ( "=" );
		}
	}

	return 0;
}

