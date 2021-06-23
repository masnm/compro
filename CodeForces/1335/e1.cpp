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

void do_task ()
{
	ll n; cin >> n;
	vector<ll> v ( n );
	for ( ll& i : v ) cin >> i;
	vector<vector<ll>> dp ( n+1, vector<ll> ( n+1 ) );
	for ( ll i = 1 ; i <= n ; ++i ) {
		for ( ll j = 1 ; j <= n ; ++j ) {
			ll ni=i-1, nj=j-1;
			if ( v[ni] == v[nj] ) {
				dp[i][j] = dp[i-1][j-1] + 1;
			} else {
				dp[i][j] = max ( dp[i-1][j], dp[i][j-1] );
			}
		}
	}
	cout << dp[n][n] << endl;
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
