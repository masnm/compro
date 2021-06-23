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
	sort ( v.begin(), v.end() );
	ll mx = -inf;
	for ( ll i = 0 ; i < n ; ++i ) {
		ll s = i, e = i + 1;
		while ( e < n && v[e] == v[s] ) {
			++e;
		}
		ll len = e - s;
		i = e - 1;
		chmax ( mx, len );
	}
	v.resize ( unique ( v.begin(), v.end() ) - v.begin() );
	ll vlen = v.size();
	if ( mx > vlen ) {
		cout << vlen << endl;
	} else if ( mx < vlen ) {
		cout << mx << endl;
	} else {
		cout << vlen - 1 << endl;
	}
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
