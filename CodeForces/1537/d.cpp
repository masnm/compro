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

const ll nax = 125;
bitset<nax> bits;
vector<ll> prms;
void prepare_lookup_table ()
{
	bits[0] = bits[1] = true;
	for ( ll i = 2 ; i * i < nax ; ++i ) {
		if ( !bits[i] ) {
			for ( ll j = i * i ; j < nax ; j += i ) {
				bits[j] = true;
			}
		}
	}
	for ( ll i = 0 ; i < nax ; ++i ) if ( !bits[i] ) prms.emplace_back(i);
}

void solve ( ll n, ll& ans )
{
	assert ( n > 0 );
	if ( !bits[n] ) {
		return;
	}
	bool me = false;
	//ll mxmns = -inf;
	for ( ll i = 2 ; i < n ; ++i ) {
		if ( n % i == 0 ) {
			//chmax ( mxmns, i );
			if ( !bits[n-i] ) {
				me = true;
			}
		}
	}
	//if ( mxmns == -inf ) {
	//	return;
	//}
	if ( me ) {
		return;
	} else {
		//ans ^= 1 ^ 2;
		bool fd = false;
		ll nxt_ans = ans ^ 1 ^ 2;
		for ( ll i = 2 ; i < n ; ++i ) {
			if ( n % i == 0 ) {
				fd = true;
				solve ( n - i, nxt_ans );
				if ( nxt_ans == ans ) {
					return;
				}
				nxt_ans = ans;
			}
		}
		if ( fd ) {
			ans ^= 1 ^ 2;
		}
		return;
	}
}

void do_task ()
{
	for ( ll i = 1 ; i < nax ; ++i ) {
		ll ans = 1;
		solve ( i, ans );
		assert ( ans == 1 || ans == 2 );
		if ( ans == 2 ) {
			cout << i << " " << ( ans==1 ? "Alice" : "Bob" ) << endl;
		}
	}
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	prepare_lookup_table();

	int t = 1;
	for ( int i = 1 ; i <= t ; ++i ) {
//		cout << "Case " << i << ": " ;
		do_task();
	}


	return 0;
}

// :args *.cpp | tab all
