#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long double ld;
typedef long long int ll;
typedef unsigned long long ull;

const ll inf = 1e18 + 5;
const ll mod = 1e9 + 7;

template<typename T> void chmax ( T& a, T b ) { if ( a < b ) a = b; }
template<typename T> void chmin ( T& a, T b ) { if ( a > b ) a = b; }

void prepare_lookup_table ()
{
}

void build_tree ( vector<vector<ll>>& tree, ll s )
{
	for ( ll i = s-1 ; i > 0 ; --i ) {
		for ( ll j = 0 ; j < 26 ; ++j ) {
			tree[i][j] = tree[i*2][j] + tree[i*2 + 1][j];
		}
	}
}

/*
void build_tree ( vector<ll>& v, ll s )
{
	for ( ll i = s - 1 ; i > 0 ; --i ) {
		v[i] = v[i*2] + v[i*2 + 1];
	}
}
 
ll st ( vector<ll>& tree, ll me, ll ms, ll mf, ll& qs, ll& qf )
{
	if ( ms >= qs && mf <= qf ) return tree[me];
	if ( ms > qf || mf < qs ) return 0;
	ll mid = ( mf + ms ) / 2;
	return st ( tree, 2*me, ms, mid, qs, qf ) + st ( tree, 2*me + 1, mid + 1, mf, qs, qf );
}
 
void do_task ()
{
	ll n,q; cin >> n >> q;
	ll clz = __builtin_popcount(n)==1 ? n : 1<<(32-__builtin_clz(n));
	vector<ll> tree ( 2*clz, 0 );
	for ( ll i = 0 ; i < n ; ++i ) {
		cin >> tree[clz+i];
	}
	build_tree ( tree, clz );
	ll l, r;
	while ( q-- ) {
		cin >> l >> r; --l; --r;
		cout << st ( tree, 1, 0, clz - 1, l, r ) << endl;
	}
}
*/

vector<ll> st ( const vector<vector<ll>>& tree, ll me, ll ms, ll mf, ll& qs, ll& qf )
{
	if ( ms >= qs && mf <= qf ) return tree[me];
	if ( ms > qf || mf < qs ) return vector<ll>(26,0);
	ll mid = (mf + ms) / 2;
	vector<ll> lft = st ( tree, 2*me, ms, mid, qs, qf );
	vector<ll> rht = st ( tree, 2*me + 1, mid + 1, mf, qs, qf );
	for ( ll i = 0 ; i < 26 ; ++i ) {
		lft[i] += rht[i];
	}
	return lft;
}

void do_task ()
{
	ll n, q; cin >> n >> q;
	string s; cin >> s;
	ll clz = __builtin_popcount(n)==1? n : 1<<(32-__builtin_clz(n));
	vector<vector<ll>> tree ( 2*clz, vector<ll> ( 26, 0 ) );
	for ( ll i = 0 ; i < n ; ++i ) {
		tree[clz+i][s[i]-'a'] = 1;
	}
	build_tree ( tree, clz );
	ll l, r;
	while ( q-- ) {
		cin >> l >> r; --l; --r;
		ll ans = 0;
		vector<ll> v = st ( tree, 1, 0, clz-1, l , r );
		for ( ll i = 0 ; i < 26 ; ++i ) {
			ans += v[i]*(i+1);
		}
		cout << ans << endl;
	}
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	prepare_lookup_table();

	int t = 1;
	for ( int i = 1 ; i <= t ; ++i ) {
//		cout << "Case " << i << ": " ;
		do_task();
	}


	return 0;
}

// :args *.cpp | tab all
