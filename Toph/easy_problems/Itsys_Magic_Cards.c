#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	union {
		int first;
		int F;
	};
	union {
		int second;
		int S;
	};
} pair ;
int n, m;
bool pro[20][20];
char a, b;
pair tp;
pair pr[15];

int main ( int argc, char* argv[] )
{
	(void) argc; (void) argv;
	scanf ( "%d%d", &n, &m );
	for ( int i = 0 ; i < m ; ++i ) {
		scanf ( " %c %c", &a, &b );
		tp.F = (int)a - 'A';
		tp.S = (int)b - 'A';
		pr[i] = tp;
	}
	int ans = 0;
	for ( int i = 0 ; i < (1<<n) ; ++i ) {
		bool ok = true;
		for ( int j = 0 ; j < m ; ++j )
			if ( !(i & (1<<pr[j].F)) && !(i & (1<<pr[j].S)) ) {
				ok = false;
				break;
			}
		if ( ok ) {
			int cnt = 0;
			for ( int j = 0 ; j < n ; ++j ) {
				if ( i & (1<<j) )
					++cnt;
			}
			cnt = n - cnt;
			if ( cnt > ans ) ans = cnt;
		}
	}
	printf ( "%d\n", ans );

	return 0;
}

