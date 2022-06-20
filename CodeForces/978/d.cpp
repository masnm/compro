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

vector<int> v;
struct tpl {
	tpl () : dif(0), cst(0), sec(0) {}
	tpl ( int d, int c, int s ) :
		dif(d), cst(c), sec(s) {}
	int dif, cst, sec;
};
vector<tpl> vp;

void solve ()
{
	int n; scanf ( "%d", &n );
	v.resize ( n );
	for ( auto& i : v ) scanf ( "%d", &i );
	if ( n == 1 || n == 2 ) { puts ( "0" ); return; }
	vp.clear();
	for ( int i = -1 ; i < 2 ; ++i ) {
		for ( int j = -1 ; j < 2 ; ++j ) {
			vp.eb ( v[1]+j - v[0]+i, abs(i)+abs(j), v[1]+j );
		}
	}
	// do the cheacking
	int ans = INT_MAX;
	for ( auto& elem : vp ) {
		int nxt = elem.dif + elem.sec;
		int cst = elem.cst;
		bool ok = true;
		for ( int i = 2 ; i < n ; ++i ) {
			if ( nxt == v[i] ) {
				// nothing to do
			} else if ( nxt == v[i] + 1 ) {
				cst += 1;
			} else if ( nxt == v[i] - 1 ) {
				cst += 1;
			} else {
				ok = false;
				break;
			}
			nxt += elem.dif;
		}
		if ( ok ) ans = min ( ans, cst );
	}
	printf ( "%d\n", ans==INT_MAX ? -1 : ans );
}

int main ()
{
	int t = 1;
//	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

