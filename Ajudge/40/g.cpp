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
	int s, e, c;
	bool a;
	st ( int _s, int _e, int _c, bool _a ) :
		s(_s), e(_e), c(_c), a(_a) {}
	st () :
		s(0), e(0), c(0), a(false) {}
};

const int nax = 105;
vector<int> rt(nax), gm[nax], no, an;
vector<st> vs;

void clr ()
{
	for ( int i = 0 ; i < nax ; ++i ) rt[i] = i;
	for ( int i = 0 ; i < nax ; ++i ) gm[i].clear(), gm[i].eb(i);
}

bool add ( int s, int e )
{
	if ( rt[s] == rt[e] )
		return false;
	int rs = rt[s], re = rt[e];
	if ( gm[rs].size() < gm[re].size() ) swap ( rs, re );
	for ( const int& i : gm[rs] ) {
		rt[i] = re;
		gm[re].eb(i);
	}
	gm[rs].clear();
	return true;
}

void solve ()
{
	no.clear();
	an.clear();
	vs.clear();
	clr ();
	int n, m, s, e, c;
	scanf ( "%d%d", &n, &m );
	for ( int i = 0 ; i < m ; ++i ) {
		--s; --e;
		scanf ( "%d%d%d", &s, &e, &c );
		vs.eb(s,e,c,true);
	}
	sort ( vs.begin(), vs.end(), [&](const st& lll, const st& rr) { return lll.c < rr.c; } );
	int ans = 0;
	for ( int i = 0 ; i < m ; ++i ) {
		if ( add ( vs[i].s, vs[i].e ) ) {
			no.eb(i);
			ans += vs[i].c;
		}
	}
	an.eb(ans);
	debug() << imie(no);
	for ( const int& inn : no ) {
		clr ();
		vs[inn].a = false;
		ans = 0;
		for ( int i = 0 ; i < m ; ++i )
			if ( vs[i].a && add ( vs[i].s, vs[i].e ) )
				ans += vs[i].c;
		bool bb = true;
		for ( int i = 0 ; i < n ; ++i )
			if ( rt[i] != rt[0] )
				bb = false;
		if ( bb ) an.eb(ans);
		vs[inn].a = true;
	}
	sort ( an.begin(), an.end() );
	an.resize( unique(an.begin(), an.end()) - an.begin() );
	if ( an.size() < 2 ) {
		printf ( "%d %d\n", an[0], an[0] );
	} else {
		printf ( "%d %d\n", an[0], an[1] );
	}
}

int main ()
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

