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

void play ( vector<pair<ll,ll>>& v )
{
	for ( auto& i : v ) if ( i.first > i.second ) swap ( i.first, i.second );
}

void print ( vector<pair<ll,ll>>& v )
{
	for ( auto& i : v ) cout << i.first << " ";
	cout << endl;
	for ( auto& i : v ) cout << i.second << " ";
	cout << endl;
	cout << endl;
}

void decide ( vector<pair<ll,ll>>& v )
{
	ll fl = v[0].second, sz = v.size();
	v[0].second = v[1].first;
	for ( ll i = 1 ; i < sz - 1 ; ++i ) {
		v[i].first = v[i+1].first;
	}
	v[sz-1].first = fl;
}

void do_task ()
{
	ll n, r; cin >> n >> r;
	vector<pair<ll,ll>> vv(n);
	for ( auto& i : vv ) cin >> i.first >> i.second;
	for ( ll i = 0 ; i < 2 * n - 1 ; ++i ) {
		vector<pair<ll,ll>> v = vv;
		for ( ll x = 0 ; x < r ; ++x ) {
			play ( v );
			decide ( v );
		}
		print ( v );
		if ( i%2 == 0 ) {
			ll ind = i/2;
			swap ( vv[ind].first, vv[ind].second );
		} else {
			ll ind = i/2;
			swap ( vv[ind].second, vv[ind+1].first );
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
		//cout << "Case " << i << ": " ;
		do_task();
	}


	return 0;
}
// resize-pane -L 30 
