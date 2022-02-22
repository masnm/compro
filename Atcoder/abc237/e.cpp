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
vector<int> h(nax), g[nax];
vector<ll> cst(nax);
int n, m, l, r, cp;
ll csst, tc;

ll sssp ()
{
	priority_queue<pair<int,int>> pq;
	pq.push ( { 0, 0 } );
	cst[0] = 0;
	ll ans = 0;
	while ( !pq.empty() ) {
		cp = pq.top().S; csst = pq.top().F; pq.pop();
		ans = max ( ans, csst );
		if ( csst < cst[cp] ) continue;
		for ( int i : g[cp] ) {
			tc = h[cp] - h[i];
			if ( tc < 0 ) tc *= 2;
			tc = csst + tc;
			if ( cst[i] < tc ) {
				cst[i] = tc;
				pq.push ( { tc, i } );
			}
		}
	}
	return ans;
}

void solve ()
{
	scanf ( "%d%d", &n, &m );
	for ( int i = 0 ; i < n ; ++i ) scanf ( "%d", &h[i] );
	for ( int i = 0 ; i < n ; ++i ) cst[i] = LLONG_MIN;
	for ( int i = 0 ; i < m ; ++i ) {
		scanf ( "%d%d", &l, &r );
		--l; --r;
		g[l].eb(r);
		g[r].eb(l);
	}
	printf ( "%lld\n", sssp() );
}

int main ()
{
	int t = 1;
//	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

