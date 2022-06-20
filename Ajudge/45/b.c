#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

char ch[105];
int n;

int main ()
{
	scanf ( "%d", &n );
	scanf ( "%s", ch );
	for ( int i = 2 ; i <= n ; ++i ) {
		if ( n % i == 0 ) {
			for ( int j = 0 ; j < i/2 ; ++j ) {
				char t = ch[j]; ch[j] = ch[i-j-1]; ch[i-j-1] = t;
			}
		}
	}
	printf ( "%s", ch );

	return 0;
}

