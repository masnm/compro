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

struct dsu {
	// one based implemantation
	vector<int> gi;
	vector<vector<int>> gm;
	int _n;
	void init ( int __n )
	{
		_n = __n + 1;
		gi.resize(_n);
		iota ( gi.begin(), gi.end(), 0 );
		gm.resize(_n);
		for ( int i = 1 ; i < _n ; ++i ) {
			gm[i].clear();
			gm[i].eb(i);
		}
	}
	int add ( int st, int en )
	{
		int sti = gi[st], eni = gi[en];
		if ( sti == eni ) return 0;
		if ( gm[sti].size() > gm[eni].size() )
			swap ( sti, eni );
		for ( int i : gm[sti] ) gm[eni].eb(i), gi[i] = eni;
		gm[sti].clear();
		return gm[eni].size();
	}
	void done ()
	{
		gi.clear();
		gm.clear();
	}
};

struct P {
	int x, y, c;
	P () : x(0), y(0), c(0) { }
	P ( int _x, int _y, int _c ) :
		x(_x), y(_y), c(_c) { }
};
debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ", " << p.c << ")"; return dd; }

struct st {
	int _n;
	vector<P> ar;
	vector<vector<pair<int,int>>> vp;
	int ans;
	void init ( int __n )
	{
		_n = __n + 1;
		ar.clear();
		vp.assign ( _n, vector<pair<int,int>>() );
		ans = 0;
	}
	void stor ( P in ) { ar.eb(in); }
	void prepare ()
	{
		sort ( ar.begin(), ar.end(), []( const P& l, const P& r) { return l.c < r.c; } );
		dsu ds; ds.init(_n-1);
		for ( P& p : ar ) {
			int ret = ds.add ( p.x, p.y );
			if ( ret != 0 ) {
				ans += p.c;
				vp[p.x].eb(p.y,p.c);
				vp[p.y].eb(p.x,p.c);
			}
			if ( ret == _n - 1 ) break;
		}
		ds.done ();
	}
	P m_max (P l, P r) { return (l.c > r.c ? l : r); }
	bool Pok ( P in ) { return in.x != 0; }
	P gm ( int pa, int cst, int me, int tar )
	{
		P p ( 0, 0, 0 );
		if ( me == tar ) {
			p.x = me; p.y = pa; p.c = cst;
			return p;
		}
		for ( pair<int,int>& _p : vp[me] )
			if ( _p.F != pa ) {
				P te = gm ( me, _p.S, _p.F, tar );
				if ( Pok ( te ) ) {
					p = m_max ( p, te );
					p = m_max ( p, P{me, pa, cst} );
				}
			}
		return p;
	}
	void erase ( int s, int e )
	{
		vp[s].erase ( find_if ( vp[s].begin(), vp[s].end(), [e](pair<int,int>& i) { return i.F==e; } ) );
		vp[e].erase ( find_if ( vp[e].begin(), vp[e].end(), [s](pair<int,int>& i) { return i.F==s; } ) );
	}
	void update ( P in )
	{
		P an = gm ( -1, 0, in.x, in.y );
		if ( an.c > in.c ) {
			ans -= an.c;
			ans += in.c;
			erase ( an.x, an.y );
			vp[in.x].eb ( in.y, in.c );
			vp[in.y].eb ( in.x, in.c );
		}
	}
};

void solve ()
{
	int n, w; scanf ( "%d%d", &n, &w );
	dsu ds; ds.init(n);
	st s; s.init(n);
	int l, r, c;
	bool broken = false;
	while ( w-- ) {
		scanf ( "%d%d%d", &l, &r, &c );
		s.stor ( P{l, r, c} );
		if ( ds.add ( l, r ) == n ) {
			ds.done();
			broken = true;
			break;
		}
		puts ( "-1" );
	}
	s.prepare();
	if ( w != -1 ) {
		while ( w-- ) {
			printf ( "%d\n", s.ans );
			scanf ( "%d%d%d", &l, &r, &c );
			s.update ( P{l, r, c} );
		}
	}
	if ( broken ) printf ( "%d\n", s.ans );
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

