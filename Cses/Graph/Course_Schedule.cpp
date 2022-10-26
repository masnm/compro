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

string read_string ( void )
{
	static char ch[1000005];
	scanf ( "%s", ch );
	return string ( ch );
}

using ll = long long int;

const int nax = 100005;
int n, m, l, r;
vector<vector<int>> g ( nax, vector<int>() );
vector<int> in ( nax );
vector<bool> is ( nax ), vis ( nax );

bool has_cycle ( int source )
{
	vis[source] = true;
	if ( is[source] ) return true;
	is[source] = true;
	for ( auto i : g[source] )
		if ( !vis[i] )
			if ( has_cycle ( i ) )
				return true;
	is[source] = false;
}

int get_source ()
{
	for ( int i = 0 ; i < n ; ++i ) {
		if ( in[i] == 0 ) return i;
	}
	return -1;
}

int main ( void )
{
	scanf ( "%d%d", &n, &m );
	for ( int i = 0 ; i < m ; ++i ) {
		scanf ( "%d%d", &l, &r );
		--l; --r;
		g[l].eb ( r );
		in[r]++;
	}
	int source = get_source ();
	if ( source == -1 ) {
		puts ( "IMPOSSIBLE" );
		return 0;
	}
	if ( has_cycle ( source ) ) {
		puts ( "IMPOSSIBLE" );
		return 0;
	}
	fill ( vis.begin(), vis.end(), false );
	queue<int> q;
	q.push ( source );
	int cp;
	while ( !q.empty() ) {
		cp = q.front(); q.pop();
		if ( vis[cp] ) continue;
		printf ( "%d ", cp+1 );
		vis[cp] = true;
		for ( auto i : g[cp] )
			if ( !vis[i] )
				q.push ( i );
	}

	return 0;
}

