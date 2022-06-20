#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int n;
char ch[1000];

int main ()
{
	scanf ( "%d %s", &n, ch );
	char prev = 0;
	int cnt = 0, ans = 0;
	for ( int i = 0 ; i < n ; ++i ) {
		if ( ch[i] != prev ) {
			if ( prev == 'x' && cnt > 2 ) ans += cnt - 2;
			prev = ch[i];
			cnt = 1;
		} else {
			++cnt;
		}
	}
	if ( prev == 'x' && cnt > 2 ) ans += cnt - 2;
	printf ( "%d\n", ans );

	return 0;
}

