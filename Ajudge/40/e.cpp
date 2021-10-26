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
	st ( int _s, int _e, int _c ) :
		s(_s), e(_e), c(_c) {}
	st():
		s(0), e(0), c(0) {}
};
debug & operator << (debug & dd, st p) { dd << "(" << p.s << ", " << p.e << ", " << p.c << ")"; return dd; }

const int nax = 205;
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
	vs.clear();
	for ( int i = 0 ; i < nax ; ++i ) rt[i] = i;
	for ( int i = 0 ; i < nax ; ++i ) gm[i].clear(), gm[i].eb(i);
	int n, m;
	bool tdo = false;
	scanf ( "%d%d", &n, &m );
	int s, e, c, bi;
	for ( int i = 0 ; i < m ; ++i ) {
		bi = i;
		scanf ( "%d%d%d", &s, &e, &c );
		--s; --e;
		vs.eb( s, e, c );
		add ( s, e );
		bool an = true;
		for ( int ii = 0 ; ii < n ; ++ii )
			if ( rt[ii] != rt[0] )
				an = false;
		if ( !an ) puts("-1");
		else {
			tdo = true;
			break;
		}
	}
	for ( int i = bi ; tdo && i < m ; ++i ) {
		for ( int ii = 0 ; ii < nax ; ++ii ) rt[ii] = ii;
		for ( int ii = 0 ; ii < nax ; ++ii ) gm[ii].clear(), gm[ii].eb(ii);
		sort ( vs.begin(), vs.end(), [&](const st& lll, const st& rr){ return lll.c < rr.c; } );
		ll ta = 0;
		vector<st> vvs;
		for ( int j = 0 ; j < (int)vs.size() ; ++j ) {
			if ( add ( vs[j].s, vs[j].e ) ) {
				ta += vs[j].c;
				vvs.eb(vs[j]);
			}
		}
		vs = vvs;
		bool an = true;
		for ( int ii = 0 ; ii < n ; ++ii )
			if ( rt[ii] != rt[0] )
				an = false;
		assert ( an == true );
		// debug() << imie(vs);
		printf ( "%lld\n", ta );
		if ( i + 1 < m ) {
			scanf ( "%d%d%d", &s, &e, &c );
			--s; --e;
			vs.eb(s, e, c);
		}
	}
}

int main ()
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
		printf ( "Case %d:\n", i+1 );
		solve ();
	}


	return 0;
}

