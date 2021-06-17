#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long double ld;
typedef long long int ll;
typedef unsigned long long ull;

const ll inf = 1e18 + 5;

template<typename T> void chmax ( T& a, T b ) { if ( a < b ) a = b; }
template<typename T> void chmin ( T& a, T b ) { if ( a > b ) a = b; }

void prepare_lookup_table ()
{
}

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
	ll n, q; cin >> n >> q;
	ll clz = __builtin_popcount(n)==1 ? n : 1<<(32-__builtin_clz(n));
	vector<ll> tree ( 2*clz, 0 );
	for ( ll i = 0 ; i < n ; ++i ) {
		cin >> tree[clz+i];
	}
	build_tree ( tree, clz );
	ll low = 0, high = n-1;
	while ( q-- ) {
		if ( low >= high ) break;
		ll total = st ( tree, 1, 0, clz-1, low, high );
		ll target = total/2;
		ll l = low, h = high, m;
		while ( l < h ) {
			m = l + ( h - l ) / 2;
			ll sum = st ( tree, 1, 0, clz-1, l, m );
			if ( sum < target && l == m ) break;
			if ( sum < target ) {
				l = m;
			} else {
				h = m;
			}
		}
		ll left = st ( tree, 1, 0, clz-1, low, l );
		ll right = total - left;
		if ( left < right ) {
			low = l + 1;
		} else {
			high = l;
		}
	}
	//cout << low << " " << high << " " << endl;
	cout << st ( tree, 1, 0, clz-1, low, high ) << endl;
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	prepare_lookup_table();

	int t = 1;
	cin >> t;
	for ( int i = 1 ; i <= t ; ++i ) {
//		cout << "Case " << i << ": " ;
		do_task();
	}


	return 0;
}
