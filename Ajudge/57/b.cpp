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

string read_string ()
{
	static char ch[1000005];
	scanf ( "%s", ch );
	return string ( ch );
}

using ll = long long int;

const int nax = 505;
int n, m, u, v, w;
int source;
vector<pair<int,int>> g[nax];
vector<bool> vis ( nax );
vector<int> cst ( nax );

void sssp ( int me )
{
	cst[me] = 0;
	priority_queue<pair<int,int>> pq;
	pq.push ( make_pair ( 0, me ) );
	while ( !pq.empty() ) {
		pair<int,int> cp = pq.top(); pq.pop();
		cp.F *= -1;
		if ( vis[cp.S] ) continue;
		vis[cp.S] = true;
		cst[cp.S] = cp.F;
		for ( auto& i : g[cp.S] ) {
			if ( !vis[i.F] ) pq.push ( make_pair ( -1 * max (cp.F, i.S), i.F ) );
		}
	}
}

void solve ()
{
	fill ( cst.begin(), cst.end(), -1 );
	fill ( vis.begin(), vis.end(), false );
	scanf ( "%d%d", &n, &m );
	for ( int i = 0 ; i <= n ; ++i ) g[i].clear();
	for ( int i = 0 ; i < m ; ++i ) {
		scanf ( "%d%d%d", &u, &v, &w );
		g[u].eb ( v, w );
		g[v].eb ( u, w );
	}
	scanf ( "%d", &source );
	sssp ( source );
	for ( int i = 0 ; i < n ; ++i ) {
		if ( cst[i] == -1 ) {
			printf ( "Impossible\n" );
		} else {
			printf ( "%d\n", cst[i] );
		}
	}
}

int main ( int argc, char* argv[] )
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
		printf ( "Case %d:\n", i+1 );
		solve ();
	}


	return 0;
}

