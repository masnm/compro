#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define nax 1005
int n, q, a, b, c, d;
char ch[nax];
int sum[nax][nax];

int querry ()
{
	fprintf ( stderr, "Error Start\n" );
	int ans = 0;
	ans += sum[c][d] + (a>0&&b>0?sum[a-1][b-1]:0);
	fprintf ( stderr, "Error %d\n", ans );
	ans -= (b>0?sum[c][b-1]:0);
	fprintf ( stderr, "Error %d\n", ans );
	ans -= (a>0?sum[a-1][d]:0);
	fprintf ( stderr, "Error %d\n", ans );
	return ans;
}

int main ()
{
	scanf ( "%d%d", &n, &q );
	for ( int i = 0 ; i < n ; ++i ) {
		scanf ( "%s", ch );
		for ( int j = 0 ; j < n ; ++j ) {
			ch[j] = (ch[j]=='*'?1:0);
			if ( j != 0 ) ch[j] = ch[j] + ch[j-1];
		}
		for ( int j = 0 ; j < n ; ++j ) {
			sum[i][j] = (i==0?0:sum[i-1][j]) + ch[j];
		}
	}
	//a = 0; b = 0;
	//for ( int i = 0 ; i < n ; ++i ) {
	//	for ( int j = 0 ; j < n ; ++j ) {
	//		c = i; d = j;
	//		printf ( "%d ", querry() );
	//	}
	//	puts ( "" );
	//}
	//puts ( "" );
	while ( q-- ) {
		scanf ( "%d%d%d%d", &b, &a, &d, &c );
		// scanf ( "%d%d%d%d", &a, &b, &c, &d );
		--a; --b; --c; --d;
		printf ( "%d\n", querry() );
	}

	return 0;
}

