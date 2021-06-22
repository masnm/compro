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
	ll n, m, i, j;
	cin >> n >> m >> i >> j;
	--n; --m; --i; --j;
	ll a = i+j, b = i + abs( n - j ),
	   c = j + abs ( n - i ), d = abs ( n - i ) + abs ( m - j );
	++n; ++m; ++i; ++j;
	if ( a + d > b + c ) {
		cout << "1 1 " << n << " " << m << endl;
	} else {
		cout << 1 << " " << m << " " << n << " " << 1 << endl;
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

// :args *.cpp | tab all
