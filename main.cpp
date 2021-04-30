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

const ll nax = 55;
ll memo[nax][nax][nax][nax];

ll find_min ( vector<vector<ll>>& v, ll sr, ll er, ll sc, ll ec )
{
	if ( memo[sr][er][sc][ec] != -1 ) {
		return memo[sr][er][sc][ec];
	}
	ll cnt = 0;
	for ( ll i = sr ; i < er ; ++i ) {
		for ( ll j = sc ; j < ec ; ++j ) {
			cnt += v[i][j];
		}
	}
	ll ans = LLONG_MAX;
	for ( ll i = sc+1 ; i < ec ; ++i ) {
		ll l = find_min ( v, sr, er, sc, i );
		ll r = find_min ( v, sr, er, i, ec );
		chmin ( ans, cnt + l + r );
	}
	for ( ll i = sr+1 ; i < er ; ++i ) {
		ll l = find_min ( v, sr, i, sc, ec );
		ll r = find_min ( v, i, er, sc, ec );
		chmin ( ans, cnt + l + r );
	}
	memo[sr][er][sc][ec] = ( ans == LLONG_MAX ? 0 : ans );
	return memo[sr][er][sc][ec];
}

void do_task ()
{
	ll n, m; cin >> n >> m;
	for ( ll i = 0 ; i <= n ; ++i ) {
		for ( ll j = 0 ; j <= n ; ++j ) {
			for ( ll k = 0 ; k <= m ; ++k ) {
				for ( ll l = 0 ; l <= m ; ++l ) {
					memo[i][j][k][l] = -1;
				}
			}
		}
	}
	vector<vector<ll>> v(n, vector<ll>(m));
	for ( ll i = 0 ; i < n ; ++i ) {
		for ( ll j = 0 ; j < m ; ++j ) {
			cin >> v[i][j];
		}
	}
	cout << find_min ( v, 0, n, 0, m ) << endl;
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
