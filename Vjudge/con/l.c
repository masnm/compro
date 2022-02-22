#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define nax 131072
//#define nax 8

long long segt[nax*2];
int n, a, b, c, d;

void update ( int l, int r, int val )
{
	for ( l+=nax, r+=nax ; l < r ; l >>= 1, r >>= 1 ) {
		if ( l&1 ) segt[l++] += val;
		if ( r&1 ) segt[--r] += val;
	}
}

void push ()
{
	for ( int i = 1 ; i < nax ; ++i ) {
		segt[i<<1] += segt[i];
		segt[i<<1|1] += segt[i];
		segt[i] = 0;
	}
}

int get_ans ()
{
	int cnt = 0;
	for ( int i = nax ; i < nax*2 ; ++i )
		cnt += (segt[i]==0?0:1);
	return cnt;
}

int main ()
{
	scanf ( "%d", &n );
	for ( int i = 0 ; i < n ; ++i ) {
		scanf ( "%d%d%d%d", &a, &b, &c, &d );
		if ( a > c ) { int t = a; a = c; c = t; }
		update ( a, c, 1 );
	}
	push ();
	printf ( "%d\n", get_ans() );
	//for ( int i = 1 ; i < nax*2 ; ++i )
	//	printf ( "%lld ", segt[i] );
	//puts ( "" );

	return 0;
}
