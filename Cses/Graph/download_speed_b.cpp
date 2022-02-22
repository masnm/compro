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

const int nax = 505;
vector<int> g[nax];
ll cost[nax][nax];
ll pre[nax+nax], c;
int n, e, l, r, pc;

ll bfs ( int source, int sink )
{
	for ( int i = 0 ; i < nax+nax ; ++i ) pre[i] = -1;
	queue<pair<int,ll>> q;
	q.push( { source, LLONG_MAX } );
	while ( !q.empty() ) {
		int cp = q.front().first;
		ll flow = q.front().second;
		q.pop();
		for ( const int next : g[cp] ) {
			if ( pre[next] == -1 && cost[cp][next] ) {
				pre[next] = cp;
				ll next_flow = min ( flow, cost[cp][next] );
				if ( next == sink ) return next_flow;
				q.push ( { next, next_flow } );
			}
		}
	}
	return 0;
}

ll max_flow ( int source, int sink )
{
	ll flow = 0;
	pc = 0;
	while ( true ) {
		ll tc = bfs ( source, sink );
		if ( tc == 0 ) break;
		debug() << imie(tc);
		flow += tc;
		int cr = sink;
		while ( cr != source ) {
			int prev = pre[cr];
			cost[cr][prev] += tc;
			cost[prev][cr] -= tc;
			cr = prev;
		}
	}
	return flow;
}

int main ()
{
	scanf ( "%d%d", &n, &e );
	for ( int i = 0 ; i < e ; ++i ) {
		scanf ( "%d%d%lld", &l, &r, &c );
		--l; --r;
		g[l].eb(r);
		cost[l][r] += c;
		g[r].eb(l);
		cost[r][l] += 0;
	}

	ll flow = max_flow ( 0, n-1 );
	printf ( "%lld\n", flow );
	//TODO: implement Min-Cut edges finder.

	return 0;
}
