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
	vector<string> v ( 9 );
	for ( string& ii : v ) cin >> ii;
	ll i = 0, j = 0, ni = 0;
	while ( true ) {
		if ( i >= 9 || j >= 9 ) break;
		int x = v[i][j] - '1';
		x += 4;
		x %= 9;
		v[i][j] = char ( x + '1' );
		++j;
		i += 3;
		if ( i > 8 ) {
			++ni;
			i = ni;
		}
	}
	for ( const string& ii : v ) {
		cout << ii << endl;
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
