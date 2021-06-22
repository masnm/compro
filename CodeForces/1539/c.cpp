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
	ll n, k, x; cin >> n >> k >> x;
	vector<ll> v ( n );
	for ( ll& i : v ) cin >> i;
	sort ( v.begin(), v.end() );
	vector<ll> fs;
	for ( ll i = 1 ; i < n ; ++i ) {
		ll dif = abs(v[i]-v[i-1]);
		if ( dif > x ) {
			ll ths = ( dif/x ) - ( dif%x==0?1:0 );
			fs.emplace_back( ths );
		}
	}
	sort(fs.begin(), fs.end());
//	for ( ll& i : fs ) {
//		cout << i << " ";
//	}
	if ( fs.empty() ) {
		cout << 1 << endl;
		return;
	}
	ll sum = 0, sz = fs.size(), cnt = 0;
	for ( ll i = 0 ; i < sz ; ++i ) {
		if ( sum + fs[i] <= k ) {
			sum += fs[i];
			++cnt;
		}
	}
	++sz;
	if ( sz - cnt < 2 ) {
		cout << 1 << endl;
	} else {
		cout << sz - cnt << endl;
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
