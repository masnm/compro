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
struct tp {
	int me, cost, par;
	tp () : me(0), cost(0), par(0) { }
	tp ( int _me, int _cost, int _par ) :
		me(_me), cost(_cost), par(_par)
	{ }
};
debug & operator << (debug & dd, tp p) { dd << "(" << p.me << ", " << p.cost << ", " << p.par << ")"; return dd; }
// const int nax = 1e5 + 5;
const int nax = 505;
vector<pair<int,int>> g[nax];
vector<tp> p(nax);
vector<bool> v(nax);
int n, e, l, r, c, ps;
int source, sink;

void reset ()
{
	for ( int i = 0 ; i < nax ; ++i ) g[i].clear();
	for ( int i = 0 ; i < nax ; ++i ) p[i] = {0,0,0};
}

bool dfs ( int me, int pet )
{
	if ( v[me] ) return false;
	v[me] = true;
	if ( me == sink ) return true;
	for ( const pair<int,int> i : g[me] )
		if ( i.S>0 && dfs ( i.F, me ) ) {
			p[ps++] = { me, i.second, pet };
			return true;
		}
	return false;
}

int main ()
{
	reset ();
	scanf ( "%d%d", &n, &e );
	source = 0;
	sink = n-1;
	for ( int i = 0 ; i < e ; ++i ) {
		scanf ( "%d%d%d", &l, &r, &c );
		--l; --r;
		g[l].eb ( r, c );
		g[r].eb ( l, 0 );
	}
	//scanf ( "%d%d", &source, &sink );
	int itc = 0;
	ll flow = 0;
	while ( true ) {
		// if ( ++itc > 15 ) assert(false);
		for ( int i = 0 ; i < nax ; ++i ) v[i] = false;
		ps = 0;
		if ( ! dfs ( source, -1 ) ) break;
		ll mmin = 1e9 + 5;
		for ( int i = 0 ; i < ps ; ++i ) mmin = min ( mmin, (ll)p[i].cost );
		flow += mmin;
		int cs = sink;
		for ( int i = 0 ; i < ps ; ++i ) {
			int cur = p[i].me;
			for ( pair<int,int>& x : g[cur] )
				if ( x.first == cs && x.second >= mmin ) {
					x.second -= mmin;
					break;
				}
			for ( pair<int,int>& x : g[cs] )
				if ( x.first == cur ) {
					x.second += mmin;
					break;
				}
			cs = p[i].me;
		}
		//debug() << imie(ps);
		//debug() << imie(p);
		// if ( ++itc > 5 ) break;
		(void)itc;
	}
	printf ( "%lld\n", flow );

	return 0;
}
