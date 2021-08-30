#include "bits/stdc++.h"
using namespace std;
using ll = long long;
struct st {
	ll sm = 0;
	bool pu = false;
	ll puv = 0;
};
st tree[2*(1<<17)];

ll update ( ll me, ll ms, ll mf, ll qs, ll qf )
{
	if ( ms > qf || mf < qs ) return 0LL;
	if ( ms >= qs && mf <= qf ) {
		if ( ms == mf ) {
			tree[me].sm += 1LL;
			return 1LL;
		} else {
			ll dis = mf - ms + 1LL;
			tree[me].sm += ( dis * 1LL );
			tree[me].pu = true;
			tree[me].puv += 1LL;
			return (dis * 1LL );
		}
	}
	ll mid = ( ms + mf ) / 2;
	ll lr = update ( 2*me, ms, mid, qs, qf );
	ll rr = update ( 2*me+1, mid+1, mf, qs, qf );
	tree[me].sm += ( lr + rr );
	return (lr + rr);
}

void take_care ( ll me, ll ms, ll mf, ll val )
{
	if ( ms == mf ) {
		tree[me].sm += val;
	} else {
		tree[me].pu = true;
		tree[me].puv += val;
		tree[me].sm += ( val * ( mf - ms + 1 ) );
	}
}

ll sum ( ll me, ll ms, ll mf, ll qs, ll qf )
{
	if ( ms > qf || mf < qs ) return 0LL;
	if ( ms >= qs && mf <= qf ) return tree[me].sm;
	ll mid = ( ms + mf ) / 2;
	if ( tree[me].pu ) {
		tree[me].pu = false;
		take_care ( 2*me, ms, mid, tree[me].puv );
		take_care ( 2*me+1, mid+1, mf, tree[me].puv );
		tree[me].puv = 0;
	}
	return sum ( 2*me, ms, mid, qs, qf ) + sum ( 2*me+1, mid+1, mf, qs, qf );
}

void erase ( ll ind )
{
	assert ( tree[ind].pu == false );
	tree[ind].sm = 0;
	ind /= 2;
	while ( ind > 0 ) {
		tree[ind].sm = tree[ind*2LL].sm + tree[ind*2LL+1LL].sm;
		ind /= 2;
	}
}

int main ( int argc, char** argv )
{
	ll nn = (1<<17);
	int n;
	scanf ( "%d", &n );
	long long l, r;
	for ( int i = 0 ; i < n ; ++i ) {
		scanf ( "%lld%lld", &l, &r );
		++l; --r;
		if ( l <= r ) update ( 1LL, 0LL, nn-1LL, l, r );
		--l; ++r;
		printf ( "%lld\n", sum ( 1LL, 0LL, nn-1LL, l, l ) + sum ( 1LL, 0LL, nn-1LL, r, r ) );
		erase ( nn+l );
		erase ( nn+r );
	}
	return 0;
}
