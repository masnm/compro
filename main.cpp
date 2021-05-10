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

const ll inf = 1e18 + 5;

void sssp ( vector<vector<ll>>& g, ll s, vector<ll>& d )
{
	priority_queue<pair<ll,ll>> pq;
	d[s] = 0;
	pq.push( {-0, s} );
	while ( !pq.empty() ) {
		ll cp = pq.top().second, cpd = abs(pq.top().first); pq.pop();
		if ( cpd > d[cp] ) continue;
		for ( auto& i : g[cp] ) {
			if ( d[i] > d[cp] + 1 ) {
				d[i] = d[cp] + 1;
				pq.push( {-d[i], i} );
			}
		}
	}
}

void do_task ()
{
	ll n, r; cin >> n >> r;
	vector<vector<ll>> g ( n, vector<ll>() );
	ll s, e;
	for ( ll i = 0 ; i < r ; ++i ) {
		cin >> s >> e;
		g[s].emplace_back(e);
		g[e].emplace_back(s);
	}
	cin >> s >> e;
	vector<ll> ds ( n, inf ), de ( n , inf );
	sssp ( g, s, ds );
	sssp ( g, e, de );
	ll fans = -inf;
	for ( ll i = 0 ; i < n ; ++i ) {
		chmax ( fans, ds[i] + de[i] );
	}
	cout << fans << endl;
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	prepare_lookup_table();

	int t = 1;
	cin >> t;
	for ( int i = 1 ; i <= t ; ++i ) {
		cout << "Case " << i << ": " ;
		do_task();
	}


	return 0;
}
