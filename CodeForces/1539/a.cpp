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
	ull n, x, t; cin >> n >> x >> t;
	ull df = t / x, two = 2;
	if ( df > n ) {
		cout << (n*(n-1))/two << endl;
		return;
	}
	ull nn = n-df;
	ull ans = nn * df;
	ull tha = (df-1)*(df);
	tha /= 2;
	ans += tha;
	cout << ans << endl;
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
