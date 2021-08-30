#include "bits/stdc++.h"
using namespace std;
using ll = long long;
struct nd {
	ll sm, pval;
	bool pu;
};
ll update ( vector<nd>& tree, int me, int ms, int mf, int qs, int qf )
{
	if ( ms > qf || mf < qs ) return 0;
	if ( mf <= qf && ms >= qs ) {
		tree[me].sm += (ll)(mf-ms+1);
		if ( ms != mf ) {
			tree[me].pu = true;
			++tree[me].pval;
		}
		return (mf-ms+1);
	}
	int mid = (ms+mf)/2;
	ll lr = update ( tree, 2*me, ms, mid, qs, qf );
	ll rr = update ( tree, 2*me+1, mid+1, mf, qs, qf );
	tree[me].sm += ( lr + rr );
	return ( lr + rr );
}
void take_care ( vector<nd>& tree, int me, int ms, int mf, ll value )
{
	if ( ms == mf )
		tree[me].sm += value;
	else {
		tree[me].sm += ((mf-ms+1)*value);
		tree[me].pu = true;
		tree[me].pval = value;
	}
}
ll sum ( vector<nd>& tree, int me, int ms, int mf, int ind )
{
	if ( ms > ind || mf < ind ) return 0;
	if ( mf <= ind && ms >= ind ) {
		return tree[me].sm;
	}
	int mid = (ms+mf)/2;
	if ( tree[me].pu ) {
		tree[me].pu = false;
		take_care ( tree, 2*me, ms, mid, tree[me].pval );
		take_care ( tree, 2*me+1, mid+1, mf, tree[me].pval );
		tree[me].pval = 0;
	}
	return sum ( tree, 2*me, ms, mid, ind ) + sum ( tree, 2*me+1, mid+1, mf, ind );
}
int main ()
{
	int n;
	scanf ( "%d", &n );
	int nn = ( 1<<18 );
	vector<nd> tree ( 2*nn, {0, false, 0} );
	vector<bool> b ( nn, false );
	int l, r;
	for ( int i = 0 ; i < n ; ++i ) {
		scanf ( "%d%d", &l, &r );
		if ( r - l > 1 ) update ( tree, 1, 0, nn-1, l+1, r-1 );
		ll sm = 0;
		if ( !b[l] ) {
			sm = sum ( tree, 1, 0, nn-1, l );
			if ( sm != 0 ) b[l] = true;
		}
		if ( !b[r] ) {
			ll smh = sum ( tree, 1, 0, nn-1, r );
			if ( smh != 0 ) b[r] = true, sm += smh;
		}
		printf ( "%lld\n", sm );
	}

	return 0;
}
