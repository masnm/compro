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

struct DSU {
	vector<int> gn;
	vector<vector<int>> gm;
	int n;
	DSU ( int _n ) : n(_n)
	{
		gn.resize(n+1);
		gm.resize(n+1);
		for ( int i = 0 ; i < n ; ++i ) gn[i] = i;
		for ( int i = 0 ; i < n ; ++i ) gm[i].clear(), gm[i].eb(i);
	}
	void uni ( int s, int e )
	{
		int gs = gn[s], ge = gn[e];
		if ( gs == ge ) return;
		// assert ( gs != ge );
		if ( gm[gs].size() < gm[ge].size() ) swap ( gs, ge );
		for ( const int& i : gm[ge] ) {
			gn[i] = gs;
			gm[gs].eb(i);
		}
		gm[ge].clear();
	}
	bool fnd ( int s, int e ) { return ( gn[s] == gn[e] ); }
};

int main ()
{
	int n;
	scanf ( "%d", &n );
	DSU fr ( n ), em ( n );
	int c, x, y;
	while ( true ) {
		scanf ( "%d%d%d", &c, &x, &y );
		// debug() << imie(c) imie(x) imie(y);
		if ( c == 4 && x == 1 && y == 2 ) {
			for ( int i = 0 ; i < n+1 ; ++i ) {
				debug() << imie(i) imie(fr.gm[i]);
			}
			debug() << imie("");
			for ( int i = 0 ; i < n+1 ; ++i ) {
				debug() << imie(i) imie(em.gm[i]);
			}
		}
		if ( c == x && x == y && y == 0 ) break;
		if ( c == 1 ) {
			if ( em.fnd ( x, y ) ) {
				printf ( "-1\n" );
			} else {
				if ( fr.fnd ( x, y ) ) assert ( false );
				int gx = em.gn[x];
				for ( const int& i : em.gm[gx] ) {
					fr.uni ( i, y );
				}
				gx = em.gn[y];
				for ( const int& i : em.gm[gx] ) {
					fr.uni ( i, x );
				}
			}
		} else if ( c == 2 ) {
			if ( fr.fnd ( x, y ) ) {
				printf ( "-1\n" );
			} else {
				if ( em.fnd ( x, y ) ) assert ( false );
				int gx = fr.gn[x];
				for ( const int& i : fr.gm[gx] ) {
					em.uni ( i, y );
				}
				gx = fr.gn[y];
				for ( const int& i : fr.gm[gx] ) {
					em.uni ( i, x );
				}
			}
		} else if ( c == 3 ) {
			if ( fr.fnd ( x, y ) ) {
				printf ( "1\n" );
			} else {
				printf ( "0\n" );
			}
		} else if ( c == 4 ) {
			if ( em.fnd ( x, y ) ) {
				printf ( "1\n" );
			} else {
				printf ( "0\n" );
			}
		} else assert ( false );
	}


	return 0;
}

