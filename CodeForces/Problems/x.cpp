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

using ll = long long int;

struct dsu {
	int n, gc;
	vector<int> v;
	vector<vector<int>> g;
	dsu ( int _n ) : n(_n)
	{
		gc = n;
		v.resize(n);
		g.resize(n);
		for ( int i = 0 ; i < n ; ++i ) v[i] = i;
		for ( int i = 0 ; i < n ; ++i ) g[i].clear(), g[i].emplace_back(i);
	}
	bool dab ( int s, int e )
	{
		if ( v[s] == v[e] ) return false;
		else if ( gc == 1 ) return false;
		return true;
	}
	void add ( int s, int e )
	{
		assert ( v[s] != v[e] );
		if ( g[v[s]].size() > g[v[e]].size() ) swap ( s, e );
		int si = v[s], ei = v[e];
		for ( int& i : g[ei] ) {
			v[i] = v[s];
			g[si].emplace_back(i);
		}
		g[ei].clear();
		--gc;
	}
	bool conn ( int s, int e )
	{
		return v[s] == v[e];
	}
};

int main ()
{
	int n;
	scanf ( "%d", &n );
	vector<int> vvvv ( n );
	for ( int i = 0 ; i < n ; ++i ) vvvv[i] = i;
	dsu ds ( n );
	int s, e;
	while ( true ) {
		scanf ( "%d%d", &s, &e );
		--s; --e;
		if ( ds.dab ( s, e ) ) {
			ds.add ( s, e );
			for ( int i = 0 ; i < n ; ++i ) debug() << imie(ds.g[i]);
		}
	}


	return 0;
}

