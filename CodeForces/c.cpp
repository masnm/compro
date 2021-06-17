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

const ll mod = 1000000007;

ll mod_pow ( ll cnt )
{
	int a = 2;
	ll power = 1;
	while ( cnt ) {
		if ( cnt%2 ) power = (power * a) % mod;
		a = (a*a) % mod;
		cnt /= 2;
	}
	return power % mod;
}

void do_task ()
{
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
