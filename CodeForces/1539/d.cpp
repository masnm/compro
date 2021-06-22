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
	vector<pair<ll,ll>> v ( n );
	for ( pair<ll,ll>& i : v ) cin >> i.second >> i.first;
	sort ( v.begin(), v.end() );
	ll s = 0, e = n-1, ans = 0, ab = 0, nd = 0;
	while ( s < e ) {
		if ( ab >= v[s].first ) {
			ab += v[s].second;
			ans += v[s].second;
			++s;
		} else {
			nd = v[s].first - ab;
			if ( nd < v[e].second ) {
				v[e].second -= nd;
				ans += nd * 2;
				ab += nd;
			} else {
				ab += v[e].second;
				ans += v[e].second * 2;
				--e;
			}
		}
		//++s; --e;
	}
	if ( v[e].second > 0 ) {
		if ( ab >= v[e].first ) {
			ans += v[e].second;
		} else {
			nd = v[e].first - ab;
			if ( v[e].second > nd ) {
				v[e].second -= nd;
				ans += nd * 2;
				ans += v[e].second;
			} else {
				ans += v[e].second * 2;
			}
		}
	}
	//for ( pair<ll,ll>& i : v ) cout << i.first << " " << i.second << endl;
	cout << ans << endl;
	//ll n; cin >> n;
	//priority_queue<pair<ll,ll>> pq;
	//ll s, e;
	//for ( ll i = 0 ; i < n ; ++i ) {
	//	cin >> s >> e;
	//	pq.push({e,s});
	//}
	//ll ab = 0, ans = 0;
	//while ( !pq.empty() ) {
	//	pair<ll,ll> cp = pq.top(); pq.pop();
	//	if ( cp.first <= ab ) {
	//		ab += cp.second;
	//		ans += cp.second;
	//	} else {
	//		ll need = cp.first - ab;
	//		if ( need >= cp.second ) {
	//			ab += cp.second;
	//			ans += cp.second * 2;
	//		} else {
	//			ll gda = cp.second - need;
	//			cp.second -= gda;
	//			ab += gda;
	//			ans += gda * 2;
	//			ab += cp.second;
	//			ans += cp.second;
	//		}
	//		//ab += need;
	//		//ans += need*2;
	//	}
	//	//cout << ans << " " << ab << endl;
	//}
	//cout << ans-1 << endl;
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	prepare_lookup_table();

	int t = 1;
//	cin >> t;
	for ( int i = 1 ; i <= t ; ++i ) {
//		cout << "Case " << i << ": " ;
		do_task();
	}


	return 0;
}

// :args *.cpp | tab all
