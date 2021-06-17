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

int F ( int x )
{
	if ( x == 0 ) {
		return 0;
	} else {
		int nf = F ( x - 1 );
		return (3 * ( nf + 1 )) - 1;
	}
}

void do_task ()
{
	int x = 8;
	for ( int i = 0 ; i < x ; ++i ) {
		cout << i << " " << F(i) << endl;
	}
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	prepare_lookup_table();

	int t = 1;
	//cin >> t;
	for ( int i = 1 ; i <= t ; ++i ) {
//		cout << "Case " << i << ": " ;
		do_task();
	}


	return 0;
}
