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
//	random_device rd;
//	mt19937 mt(rd());
//	uniform_int_distribution<int> un(1,20);
//	uniform_int_distribution<int> ut(2,5);
//
//	ll n = 29; // must be odd ans > 3
//	vector<ll> v ( n );
//	for ( ll i = 0 ; i < n ; ++i ) v[i] = i+1;
//	ll t = un(mt);
//	while ( t-- ) random_shuffle(v.begin(), v.end());
//	queue<ll> q;
//	for ( auto& i : v ) q.push(i);
//	set<ll> s;
//	vector<pair<ll,ll>> vp;
//	s.insert ( q.front() ); q.pop();
//	while ( !q.empty() ) {
//		ll sz = ut(mt); if ( sz % 2 == 1 ) ++sz;
//		if ( sz > (ll)q.size() ) sz = q.size();
//		vector<ll> nd;
//		for ( ll i = 0 ; i < sz ; ++i ) {
//			nd.emplace_back ( q.front() );
//			q.pop();
//		}
//		for ( ll i = 0 ; i < sz ; ++i ) {
//			ll start = *s.begin();
//			s.erase(s.begin());
//			s.insert(nd[i]);
//			vp.emplace_back(start,nd[i++]);
//			s.insert(nd[i]);
//			vp.emplace_back(start,nd[i]);
//		}
//	}
//	for ( auto& i : vp ) {
//		cout << i.first << " " << i.second << endl;
//	}
	cout << 4999999937 << endl;
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	prepare_lookup_table();

//	random_device rd;
//	mt19937 mt(rd());
//	uniform_int_distribution<int> ud(1,10);

	int t = 5000;
	//t = ud(mt);
	cout << t << endl;
	for ( int i = 1 ; i <= t ; ++i ) {
		//cout << "Case " << i << ": " ;
		do_task();
	}


	return 0;
}
// resize-pane -L 30 
