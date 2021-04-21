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
	ll n, k; cin >> n >> k;
	vector<ll> v(n);
	ll sm = 0;
	for ( auto& i : v ) {
		cin >> i;
		if ( k > 0 ) {
			if ( i > k ) {
				sm += k;
				i -= k;
				k = 0;
			} else {
				sm += i;
				k -= i;
				i = 0;
			}
		}
	}
	v[n-1] += sm;
	for ( auto& i : v ) cout << i << " ";
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
		//cout << "Case " << i << ": " ;
		do_task();
	}


	return 0;
}
// resize-pane -L 30 
