#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#define nax 200005

int main ()
{
	char a[nax], b[nax];
	scanf ( "%s %s", a, b );
	int la = strlen ( a ), lb = strlen ( b );
	int mn = ( la > lb ? lb : la );
	int cnt = 0;
	for ( int i = 0 ; i < mn ; ++i ) {
		if ( a[la-i-1] == b[lb-i-1] )
			++cnt;
		else break;
	}
	printf ( "%d\n", la - cnt + lb - cnt );

	return 0;
}

