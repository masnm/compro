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
	static char ch[15];
	scanf ( "%s", ch );
	return string ( ch );
}

struct st {
	int s, e, c;
	st ( int _s, int _e, int _c ) :
		s(_s), e(_e), c(_c) { }
	st ( ) :
		s(0), e(0), c(0) { }
};

int n, m, N, ll, rr, cc;
const int nax = 405;
map<string,int> mp;
vector<st> vs;
vector<int> rt(nax), gm[nax];

bool add ( int s, int e )
{
	if ( rt[s] == rt[e] ) return false;
	int rs = rt[s], re = rt[e];
	if ( gm[rs].size() > gm[re].size() ) swap ( rs, re );
	for ( const int& i : gm[rs] ) {
		rt[i] = re;
		gm[re].eb(i);
	}
	gm[rs].clear();
	return true;
}

void solve ()
{
	mp.clear();
	vs.clear();
	for ( int i = 0 ; i < nax ; ++i ) rt[i] = i;
	for ( int i = 0 ; i < nax ; ++i ) gm[i].clear(), gm[i].eb(i);
	string s;
	N = 0;
	for ( int i = 0 ; i < n ; ++i ) {
		s = read_string ();
		mp[s] = N++;
	}
	for ( int i = 0 ; i < m ; ++i ) {
		s = read_string();
		ll = mp[s];
		s = read_string();
		rr = mp[s];
		scanf ( "%d", &cc );
		vs.eb ( ll, rr, cc );
	}
	s = read_string();
	long long ans = 0 ;
	sort ( vs.begin(), vs.end(), [&](const st& l, const st& r){return l.c < r.c; } );
	for ( const st& ss : vs )
		if ( add ( ss.s, ss.e ) )
			ans += ss.c;
	bool ok = true;
	for ( int i = 0 ; i < n ; ++i )
		if ( rt[i] != rt[0] )
			ok = false;
	if ( !ok )
		puts ( "Impossible" );
	else
		printf ( "%lld\n", ans );
}

int main ()
{
	for ( int i = 0 ; ; ++i ) {
		scanf ( "%d%d", &n, &m );
		if ( n == m && n == 0 ) break;
		solve ();
	}


	return 0;
}
