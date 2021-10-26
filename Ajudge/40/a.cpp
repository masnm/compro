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

struct st {
	int a, b, c;
	st ( int _a, int _b, int _c ) :
		a(_a), b(_b), c(_c) { }
};

const int nax = 105;
vector<int> r(nax), g[nax];
vector<st> v;

int add ( int s, int e, int c )
{
	if ( r[s] == r[e] ) return 0;
	int rs = r[s], re = r[e];
	if ( g[rs].size() < g[re].size() ) swap ( rs, re );
	for ( const int& i : g[re] ) {
		r[i] = rs;
		g[rs].eb ( i );
	}
	g[re].clear();
	return c;
}

int mst ()
{
	int ans = 0;
	for ( const st& i : v )
		ans += add ( i.a, i.b, i.c );
	return ans;
}

void solve ()
{
	v.clear();
	for ( int i = 0 ; i < nax ; ++i ) r[i] = i;
	for ( int i = 0 ; i < nax ; ++i ) g[i].clear(), g[i].eb(i);
	int n;
	scanf ( "%d", &n );
	int a, b, c;
	while ( true ) {
		scanf ( "%d%d%d", &a, &b, &c );
		if ( a == b && b == c && c == 0 ) break;
		v.eb ( a, b, c );
	}
	sort ( v.begin(), v.end(), [&]( const st& l, const st& rr ) { return l.c < rr.c; } );
	int mn = mst();
	reverse ( v.begin(), v.end() );
	for ( int i = 0 ; i < nax ; ++i ) r[i] = i;
	for ( int i = 0 ; i < nax ; ++i ) g[i].clear(), g[i].eb(i);
	int mx = mst();
	debug() << imie(mn) imie(mx);
	if ( ( mn + mx ) % 2 == 0 ) {
		printf ( "%d\n", (mn + mx) / 2 );
	} else {
		printf ( "%d/%d\n", (mn+mx), 2 );
	}
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
