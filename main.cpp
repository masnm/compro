#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long double ld;
typedef long long int ll;
typedef unsigned long long ull;

template<typename T> void chmax ( T& a, T b ) { if ( a < b ) a = b; }
template<typename T> void chmin ( T& a, T b ) { if ( a > b ) a = b; }

void prepare_lookup_table ()
{
}

ll min_distance ( vector<vector<ll>>& v, ll sr, ll er, ll sc, ll ec )
{
	ll cnt = 0;
	for ( ll i = sr ; i < er ; ++i ) {
		for ( ll j = sc ; j < ec ; ++j ) {
			cnt += v[i][j];
		}
	}
	ll ans = LLONG_MAX;
	for ( ll i = sr + 1 ; i < er ; ++i ) {
		ll thl = min_distance ( v, sr, i, sc, ec );
		ll thr = min_distance ( v, i, er, sc, ec );
		chmin ( ans, thl + thr );
	}
	for ( ll i = sc + 1 ; i < ec ; ++i ) {
		ll thl = min_distance ( v, sr, er, sc, i );
		ll thr = min_distance ( v, sr, er, i, ec );
		chmin ( ans, thl + thr );
	}
	return cnt + (ans == LLONG_MAX ? 0 : ans );
}

void do_task ()
{
	ll n, m, mns = 0; cin >> n >> m;
	vector<vector<ll>> v(n, vector<ll>(m));
	for ( ll i = 0 ; i < n ; ++i ) {
		for ( ll j = 0 ; j < m ; ++j ) {
			cin >> v[i][j];
			mns += v[i][j];
		}
	}
	cout << min_distance ( v, 0, n, 0, m ) - mns << endl;
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	prepare_lookup_table();

	int t = 1;
	for ( int i = 1 ; i <= t ; ++i ) {
		//cout << "Case " << i << ": " ;
		do_task();
	}


	return 0;
}
// resize-pane -L 30 
