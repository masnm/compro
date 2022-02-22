#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef long long int ll;
#define nax 262144
ll ar[nax*2], item;
int n, l, r, x, tl, op, q;

void get_init ()
{
	tl = nax;
	for ( int i = 0 ; i < 2 * tl ; ++i ) ar[i] = 0;
	for ( int i = 0 ; i < n ; ++i ) scanf ( "%lld", &ar[tl+n-i-1] );
	for ( int i = tl - 1 ; i > -1 ; --i )
		ar[i] = ar[i*2] + ar[i*2+1];
}

ll get_sum ( int me, int ms, int mf )
{
	if ( ms > r || mf < l ) return 0LL;
	if ( ms >= l && mf <= r ) return ar[me];
	int mid = ( ms + mf ) / 2, nme = 2 * me;
	return (get_sum(nme, ms, mid) + get_sum(nme+1, mid+1, mf));
}

void opre_one ()
{
	scanf ( "%d%d", &l, &r );
	l = n - l + 1; r = n - r + 1;
	int t = l; l = r; r = t;
	printf ( "%lld\n", get_sum ( 1, 1, tl ) );
}

void opre_two ()
{
	scanf ( "%lld", &item );
	int ind = tl + n; ++n;
	while ( ind > 0 ) {
		ar[ind] += item;
		ind/=2;
	}
}

int main ()
{
	scanf ( "%d", &n );
	get_init ();
	scanf ( "%d", &q );
	for ( int i = 0 ; i < q ; ++i ) {
		scanf ( "%d", &op );
		if ( op == 1 ) opre_one ();
		else opre_two ();
	}

	return 0;
}
