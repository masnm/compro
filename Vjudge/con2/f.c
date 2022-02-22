#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

char key[28], inp[55];
int t;

int get ( char a, char b )
{
	int l, r;
	for ( int i = 0 ; i < 26 ; ++i )
		if ( key[i] == a ) {
			l = i; break;
		}
	for ( int i = 0 ; i < 26 ; ++i )
		if ( key[i] == b ) {
			r = i; break;
		}
	return abs(l-r);
}

void solve ()
{
	scanf ( "%s%s", key, inp );
	int ans = 0;
	for ( int i = 1 ; i < strlen(inp) ; ++i )
		ans += get ( inp[i], inp[i-1] );
	printf ( "%d\n", ans );
}

int main ()
{
	scanf ( "%d", &t );
	while ( t-- )
		solve ();

	return 0;
}

