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
	if ( n == 2 ) {
		cout << v[0] << " " << v[1] << endl;
		return;
	}
	ll mni, mn = inf, t;
	for ( ll i = 0 ; i < n - 1 ; ++i ) {
		t = abs ( v[i+1] - v[i] );
		if ( t < mn ) {
			mn = t;
			mni = i;
		}
	}
	for ( ll i = mni + 1 ; i < n ; ++i ) {
		cout << v[i] << " ";
	}
	for ( ll i = 0 ; i <= mni ; ++i ) {
		cout << v[i] << " ";
	}
	cout << endl;
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

// :args *.cpp | tab all
