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
	ll n; cin >> n;
	vector<ll> v(n);
	for ( auto& i : v ) cin >> i;
	--n;
	vector<vector<ll>> cost(n+1,vector<ll>(n+1,0)), mink(n+1,vector<ll>(n+1,0));
	for ( ll i = 2 ; i <= n ; ++i ) {
		for ( ll j = 1 ; j <= n-i+1 ; ++j ) {
			ll ind = j+i-1;
			cost[j][ind] = LLONG_MAX;
			for ( ll k = j ; k < ind ; ++k ) {
				ll t = cost[j][k] + cost[k+1][ind] + v[j-1]*v[k]*v[ind];
				if ( t < cost[j][ind] ) {
					cost[j][ind] = t;
					mink[j][ind] = k;
				}
			}
		}
	}
	string s = "";
	for ( auto& i : cost ) {
		for ( auto& j : i ) {
			s = to_string(j); reverse(s.begin(),s.end());
			ll llen = 6-s.length();
			while ( llen-- ) { s += ' '; }
			reverse(s.begin(),s.end());
			cout << s << " ";
		}
		cout << endl;
	}
	cout << endl;
	for ( auto& i : mink ) {
		for ( auto& j : i ) {
			s = to_string(j); reverse(s.begin(),s.end());
			ll llen = 3-s.length();
			while ( llen-- ) { s += ' '; }
			reverse(s.begin(),s.end());
			cout << s << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	prepare_lookup_table();

	int t = 1;
	for ( int i = 1 ; i <= t ; ++i ) {
		//cout << "Case " << i << ": " ;
		do_task();
	}


	return 0;
}
// resize-pane -L 30 
