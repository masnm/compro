#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( int argc, char* argv[] )
{
	int t; scanf ( "%d", &t );
	while ( t-- ) {
		static char ch[200005];
		scanf ( "%s", ch );
		int len = strlen ( ch );
		bool cnt[30] = { };
		int ans = 1, au = 0;
		for ( int i = 0 ; i < len ; ++i ) {
			if ( !cnt[(int)(ch[i]-'a')] && au > 2 ) {
				for ( int j = 0 ; j < 30 ; ++j ) cnt[j] = false;
				au = 1;
				cnt[(int)(ch[i]-'a')] = true;
				++ans;
			} else if ( !cnt[(int)(ch[i]-'a')] && au < 3 ) {
				au++;
				cnt[(int)(ch[i]-'a')] = true;
			}
		}
		printf ( "%d\n", ans );
	}

	return 0;
}

