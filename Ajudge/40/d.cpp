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

const int nax = 100005;
vector<pair<int,int>> vp[nax];

void solve ()
{
	int n, m, a;
	scanf ( "%d%d%d", &n, &m, &a );
	for ( int i = 0 ; i < n ; ++i ) vp[i].clear();
	int x, y, c;
	for ( int i = 0 ; i < m ; ++i ) {
		scanf ( "%d%d%d", &x, &y, &c );
		--x; --y;
		vp[x].eb ( y, c );
		vp[y].eb ( x, c );
	}
	priority_queue<pair<int,int>> pq;
	set<int> s;
	ll ans = 0;
	int ac = 0;
	for ( int ii = 0 ; ii < n ; ++ii ) {
		if ( s.find(ii) != s.end() ) continue;
		s.insert(ii);
		ans += a;
		++ac;
		for ( const pair<int,int>& i : vp[ii] )
			pq.push ( { -1*i.S, i.F } );
		while ( !pq.empty() ) {
			pair<int,int> cp = pq.top();
			pq.pop();
			if ( s.find(cp.S) == s.end() ) {
				ll add = abs ( cp.F );
				if ( add >= a ) {
					ans += a;
					++ac;
				} else
					ans += add;
				s.insert ( cp.S );
				for ( const pair<int,int>& i : vp[cp.S] )
					pq.push ( { -1*i.S, i.F } );
			}
		}
	}
	printf ( "%lld %d\n", ans, ac );
}

int main ()
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}
