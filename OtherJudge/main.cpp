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
	ll mn = inf, mni;
	for ( int i = 1 ; i < n ; ++i ) {
		if ( abs ( v[i] - v[i-1] ) < mn ) {
			mn = abs ( v[i] - v[i-1] );
			mni = i;
		}
	}
	sort( v.begin(), v.end() );
	vector<ll> ans ( n );
	ans[0] = v[mni];
	ans[n-1] = v[mni-1];
	ll thi = 1;
	for ( ll i = 0 ; i < n && ( thi < n - 1 ) ; ++i ) {
		if ( i == mni || i == mni-1 ) continue;
		ans[thi] = v[i];
		thi += 2;
		v[i] = -1;
	}
	thi = 2;
	for ( ll i = 0 ; i < n && ( thi < n -1 ) ; ++i ) {
		if ( i == mni || i == mni-1 ) continue;
		if ( v[i] == -1 ) continue;
		ans[thi] = v[i];
		thi += 2;
	}
	if ( v[1] < v[0] && ans.size() > 2 ) {
		reverse(ans.begin(), ans.end());
		swap(ans[0], ans[n-1]);
	}
	for ( ll& i : ans ) {
		cout << i << " ";
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
