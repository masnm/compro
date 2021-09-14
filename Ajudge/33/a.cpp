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

const ll nax = 1e5 + 10;
ll pla[nax], pra[nax], plb[nax], prb[nax];
ll a[nax], b[nax];
ll n, m;

void solve ()
{
	scanf ( "%lld%lld", &n, &m );
	for ( ll i = 0 ; i < n ; ++i ) scanf ( "%lld", &a[i] );
	for ( ll i = 0 ; i < m ; ++i ) scanf ( "%lld", &b[i] );
	pla[0] = a[0];
	for ( ll i = 1 ; i < n ; ++i ) pla[i] = pla[i-1] + a[i];
	plb[0] = b[0];
	for ( ll i = 1 ; i < m ; ++i ) plb[i] = plb[i-1] + b[i];
	ll q; scanf ( "%lld", &q );
	ll w, x, y, z, sa, sb;
	while ( q-- ) {
		scanf ( "%lld%lld%lld%lld", &w, &x, &y, &z );
		--w; --x; --y; --z;
		if ( w == 0 ) sa = pla[x];
		else sa = pla[x] - pla[w-1];
		if ( y == 0 ) sb = plb[z];
		else sb = plb[z] - plb[y-1];
		printf ( "%lld\n", sa * sb );
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

