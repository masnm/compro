#include "bits/stdc++.h"
using namespace std;

using ll = long long int;

struct BIT {
	vector<ll> bit;
	int n;
	BIT ( int _n ) : n(_n + 1)
	{
		bit.resize(n,0);
	}
	BIT ( const vector<int>& _v ) : BIT( _v.size() )
	{
		for ( int i = 0 ; i < n ; ++i ) add ( i, _v[i] );
	}
	ll sum ( int r )
	{
		ll ans = 0;
		for ( ++r ; r > 0 ; r -= ( r & ( -r ) ) ) ans += bit[r];
		return ans;
	}
	ll sum ( int l, int r )
	{
		return sum ( r ) - sum ( l - 1 );
	}
	void add ( int i, ll val )
	{
		for ( ++i ; i < n ; i += ( i & (-i) ) ) bit[i] += val;
	}
};

const int nax = 131072;
int ppl[nax], tree[2*nax], piii[nax];
ll ans[nax];

void build_tree ( int base )
{
	for ( int i = base - 1 ; i > 0 ; --i )
		tree[i] = max ( tree[i*2], tree[i*2 + 1] );
}

int querry ( int me, int ms, int mf, int& qs, int& qf )
{
	if ( mf < qs || ms > qf ) return 0;
	if ( ms >= qs && mf <= qf ) return tree[me];
	int mid = ( mf + ms ) / 2;
	return max ( querry ( 2*me, ms, mid, qs, qf ), querry ( 2*me+1, mid+1, mf, qs, qf ) );
}

void solve ()
{
	int n;
	scanf ( "%d", &n );
	int base = 1;
	while ( base <= n ) base <<= 1 ;
	for ( int i = 0 ; i < 2 * base ; ++i ) tree[i] = 0;
	for ( int i = 0 ; i < n ; ++i ) {
		scanf ( "%d", &tree[base+i] );
	}
	build_tree ( base );
	int m;
	scanf ( "%d", &m );
	int p, l, r;
	for ( int i = 0 ; i < m ; ++i ) {
		scanf ( "%d%d%d", &p, &l, &r );
		--l; --r;
		ppl[p] = querry ( 1, 0, base-1, l, r );
	}
	for ( int i = 0 ; i < m ; ++i )
		scanf ( "%d", &piii[i] );
	BIT bit(nax);
	for ( int i = m-1 ; i >-1 ; --i ) {
		bit.add ( piii[i], (ll)ppl[piii[i]] );
		ans[i] = bit.sum ( piii[i]-1);
	}
	for ( int i = 0 ; i < m ; ++i ) printf ( "%lld\n", ans[i] );
	for ( int i = 0 ; i < nax ; ++i ) piii[i] = 0;
	for ( int i = 0 ; i < nax ; ++i ) ppl[i] = 0;
}

int main ()
{
	int t;
	scanf ( "%d", &t );
	while ( t-- ) solve ();


	puts("");
	return 0;
}

