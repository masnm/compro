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

void dfs ( vector<vector<ll>>& g, vector<bool>& v, ll me )
{
	for ( const ll& next : g[me] ) {
		if ( !v[next] ) {
			v[next] = true;
			dfs ( g, v, next );
		}
	}
}

ll mod_pow ( ll cnt )
{
	ll a = 2;
	ll power = 1;
	while ( cnt ) {
		if ( cnt%2 ) power = (power * a) % mod;
		a = (a*a) % mod;
		cnt /= 2;
	}
	return power % mod;
}

ll power ( ll a, ll b )
{
	ll answer = 1;
	while ( b ) {
		if ( b & 1 ) {
			answer = ( answer * a ) % mod;
		}
		a = ( a * 2 ) % mod;
		b /= 2;
	}
	return ( answer % mod );
}

void do_task ()
{
	ll n; cin >> n;
	vector<vector<ll>> v ( 2, vector<ll> ( n ) );
	for ( ll row = 0 ; row < 2 ; ++row ) {
		for ( ll i = 0 ; i < n ; ++i ) {
			cin >> v[row][i]; --v[row][i];
		}
	}
	vector<vector<ll>> g ( n, vector<ll> () );
	for ( ll i = 0 ; i < n ; ++i ) {
		g[v[0][i]].emplace_back(v[1][i]);
		g[v[1][i]].emplace_back(v[0][i]);
	}
	ll cnt = 0;
	vector<bool> vs ( n, false );
	for ( ll i = 0 ; i < n ; ++i ) {
		if ( !vs[i] ) {
			vs[i] = true;
			dfs ( g, vs, i );
			++cnt;
		}
	}
	// cout << power ( 2, cnt ) << endl;
	cout << mod_pow ( cnt ) << endl;
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
