#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int t, x, y, a, b;

bool top_left ()
{
	return (a < x && b < y);
}

bool top_right ()
{
	return (a > x && b < y);
}

bool down_left ()
{
	return (a < x && b > y);
}

bool down_right ()
{
	return (a > x && b > y);
}

int main ()
{
	while ( true ) {
		scanf ( "%d", &t );
		if ( t == 0 ) break;
		scanf ( "%d%d", &x, &y );
		while ( t-- ) {
			scanf ( "%d%d", &a, &b );
			if ( a == x || b == y )
				puts ( "divisa" );
			else if ( top_left () )
				puts ( "SO" );
			else if ( top_right() )
				puts ( "SE" );
			else if ( down_left() )
				puts ( "NO" );
			else if ( down_right() )
				puts ( "NE" );
			else assert ( false );
		}
	}

	return 0;
}

