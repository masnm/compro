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

void do_task ()
{
	ll n, t, p; cin >> n >> t >> p; --p;
	vector<vector<ll>> v(n,vector<ll>(t));
	vector<pair<pair<ll,ll>,ll>> vpp;
	ll sc[t] = { };
	for ( ll i = 0 ; i < n ; ++i ) {
		ll cnt = 0;
		for ( ll j = 0 ; j < t ; ++j ) {
			cin >> v[i][j];
			if ( v[i][j] ) ++sc[j], ++cnt;
		}
		vpp.emplace_back ( make_pair( make_pair( -1, cnt ), n-i ) );
	}
	for ( ll i = 0 ; i < t ; ++i ) sc[i] = n - sc[i];
	for ( ll i = 0 ; i < n ; ++i ) {
		ll scr = 0;
		for ( ll j = 0 ; j < t ; ++j ) {
			scr += v[i][j] ? sc[j] : 0;
		}
		vpp[i].first.first = scr;
	}
	sort ( vpp.begin(), vpp.end() );
	for ( ll i = n - 1 ; i > -1 ; --i ) {
		if ( n - vpp[i].second == p ) {
			cout << vpp[i].first.first << " " << n - vpp[i].second + 1 << endl;
			return;
		}
	}
	assert(false);
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
