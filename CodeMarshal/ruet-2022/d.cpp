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
	int n;
	vector<int> gi;
	vector<vector<int>> gm;
	dsu ( int _n ) : n(_n) {
		gi.resize ( n + 1 );
		gm.resize ( n + 1 );
		for ( int i = 1 ; i <= n ; ++i ) {
			gi[i]=i;
			gm[i].clear();
			gm[i].eb(i);
		}
	}
	bool add ( int l, int r ) {
		int li = gi[l], ri = gi[r];
		if ( li == ri ) return false;
		if ( gm[li].size() > gm[ri].size() ) swap ( li, ri );
		for ( auto i : gm[li] ) {
			gi[i] = ri;
			gm[ri].eb(i);
		}
		gm[li].clear();
		return true;
	}
	bool done () {
		return int(gm[gi[1]].size()) == n;
	}
};

struct tpl {
	int l, r, c;
	tpl () : l(0), r(0), c(0) {}
	tpl ( int _l, int _r, int _c ) :
		l(_l), r(_r), c(_c) {}
};

void solve ()
{
	int n;
	scanf ( "%d", &n );
	vector<tpl> v;
	for ( int i = 1 ; i <= n ; ++i )
		for ( int j = 1 ; j <= n ; ++j )
			v.eb ( i, j, __gcd(i,j) );
	sort ( v.begin(), v.end(), [](auto &l, auto &r) { return l.c > r.c; } );
	for ( auto i : v ) printf ( "%d %d %d\n", i.l, i.r, i.c );
	//dsu d ( n );
	//for ( auto i : v ) {
	//	if ( d.add ( i.l, i.r ) ) {
	//		printf ( "%d %d\n", i.l, i.r );
	//	}
	//	if ( d.done() ) break;
	//}
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

