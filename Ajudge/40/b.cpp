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

const int nax = 55;

struct st {
	int s, e, c;
	st ( int _s, int _e, int _c ) :
		s(_s), e(_e), c(_c) { }
};
debug & operator << (debug & dd, st p) { dd << "(" << p.s << ", " << p.e << ", " << p.c << ")"; return dd; }

vector<st> vs;
vector<int> rt(nax), gm[nax];

bool add ( int l, int r )
{
	if ( rt[l] == rt[r] ) return false;
	int rl = rt[l], rr = rt[r];
	if ( gm[rl].size() > gm[rr].size() ) swap ( rl, rr );
	for ( const int& i : gm[rl] ) {
		rt[i] = rr;
		gm[rr].eb(i);
	}
	gm[rl].clear();
	return true;
}

void solve ()
{
	vs.clear();
	for ( int i = 0 ; i < nax ; ++i ) rt[i] = i;
	for ( int i = 0 ; i < nax ; ++i ) gm[i].clear(), gm[i].eb(i);
	int n, t; scanf ( "%d", &n );
	ll sum = 0;
	for ( int i = 0 ; i < n ; ++i ) {
		for ( int j = 0 ; j < n ; ++j ) {
			scanf ( "%d", &t );
			if ( t == 0 ) continue;
			vs.eb( i, j, t );
			sum += t;
		}
	}
	sort ( vs.begin(), vs.end(), [&](const st& lll, const st& rr){ return lll.c < rr.c; } );
	ll cst = 0;
	for ( const st& i : vs ) {
		if ( add ( i.s, i.e ) )
			cst += i.c;
	}
	bool ans = true;
	for ( int i = 0 ; i < n ; ++i )
		if ( rt[i] != rt[0] )
			ans = false;
	if ( !ans ) {
		puts ( "-1" );
		return;
	}
	printf ( "%lld\n", sum - cst );
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
