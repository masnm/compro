#include "bits/stdc++.h"
using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

#define F first
#define S second
#define eb emplace_back

using ll = long long int;

const int nax = 200005;
vector<int> v;
vector<pair<int,int>> mp[nax];
int n, m;

int main ()
{
	scanf ( "%d%d", &n, &m );
	v.resize ( n );
	for ( int i = 0 ; i < nax ; ++i ) mp[i].clear();
	int index = 0;
	for_each ( v.begin(), v.end(), [&index]( auto& i ) {
			scanf ( "%d", &i );
			mp[i%m].eb(i,index);
			index++;
		});
	int tar = n/m, cnt;
	ll ans = 0;
	queue<pair<int,int>> asg;
	for ( int rep = 0 ; rep < 2 ; ++rep ) {
		for ( int i = 0 ; i < m ; ++i ) {
			if ( int(mp[i].size()) >= tar ) {
				cnt = int(mp[i].size()) - tar;
				while ( cnt -- ) {
					asg.push ( mp[i].back() );
					mp[i].pop_back();
				}
			} else if ( int(mp[i].size()) < tar ) {
				while ( !asg.empty() ) {
					if ( int(mp[i].size()) >= tar ) break;
					int val = asg.front().F;
					int ind = val%m;
					val = i - ind;
					mp[i].eb ( asg.front().F+val, asg.front().S );
					asg.pop();
				}
			} else {
				assert ( false );
			}
		}
	}
	vector<pair<int,int>> vp;
	for ( int i = 0 ; i < m ; ++i ) {
		for ( int j = 0 ; j < int(mp[i].size()) ; ++j ) {
			vp.eb ( mp[i][j].S, mp[i][j].F );
		}
	}
	sort ( vp.begin(), vp.end() );
	ans = 0;
	for ( int i = 0 ; i < n ; ++i ) {
		ans += vp[i].S - v[i];
	}
	printf ( "%lld\n", ans );
	for ( auto i : vp ) {
		printf ( "%d ", i.S );
	}

	return 0;
}
