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

const int nax = 10005;
const ll inf = 1e18 + 5;
vector<pair<int,ll>> g[nax];
ll dp[nax];
int n, m, k, s, t, ss, ee, ti;
ll c, tc;

void clr ()
{
	for ( int i = 0 ; i < nax ; ++i ) g[i].clear();
}

ll sssp ()
{
	dp[s] = 0;
	priority_queue<pair<ll,int>> pq;
	pq.push ( { 0, s } );
	while ( !pq.empty() ) {
		ti = pq.top().S; tc = abs ( pq.top().F ); pq.pop();
		if ( ti == t ) return dp[t];
		//if ( dp[ti] < tc ) continue;
		for ( const pair<int,ll>& nxt : g[ti] ) {
			if ( dp[nxt.F] > dp[ti] + nxt.S ) {
				dp[nxt.F] = dp[ti] + nxt.S;
				pq.push ( { -dp[nxt.F], nxt.F } );
			}
		}
	}
	return -1LL;
}

void solve ()
{
	clr();
	scanf ( "%d%d%d%d%d", &n, &m, &k, &s, &t );
	for ( int i = 0 ; i < m ; ++i ) {
		scanf ( "%d%d%lld", &ss, &ee, &c );
		g[ss].eb ( ee, c );
	}
	ll ans = inf, tans;
	for ( int i = 0 ; i < k ; ++i ) {
		scanf ( "%d%d%lld", &ss, &ee, &c );
		g[ss].eb ( ee, c );
		g[ee].eb ( ss, c );
		for ( int j = 0 ; j < nax ; ++j ) dp[j] = inf;
		tans = sssp();
		if ( tans != -1LL ) ans = min ( ans, tans );
		g[ss].pop_back();
		g[ee].pop_back();
	}
	printf ( "%lld\n", (ans==inf?-1:ans) );
}

int main ()
{
	int test = 1;
	scanf ( "%d" , &test );
	for ( int i = 0 ; i < test ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

