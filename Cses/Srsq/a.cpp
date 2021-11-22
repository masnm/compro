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

const int nax = 200005;
ll v[nax], b[nax];

void solve ()
{
	int n, q;
	scanf ( "%d%d", &n, &q );
	for ( int i = 0 ; i < n ; ++i )
		scanf ( "%lld", &v[i] );
	int sq = sqrt(n + .0) + 1;
	for ( int i = 0 ; i < n ; ++i )
		b[i/sq] += v[i];
	int s, e;
	debug() << imie(sq);
	for ( int qq = 0 ; qq < q ; ++qq ) {
		scanf ( "%d%d", &s, &e );
		--s; --e;
		ll ans = 0;
		int ls = s/sq, rs = e/sq;
		if ( ls == rs ) {
			for ( int i = s ; i <= e ; ++i )
				ans += v[i];
		} else {
			for ( int i = s, end = sq*(1+(int)(s/sq)) ; i < end ; ++i )
				ans += v[i];
			for ( int i = ls+1 ; i < rs ; ++i )
				ans += b[i];
			for ( int i = rs*sq ; i <= e ; ++i )
				ans += v[i];
		}
		printf ( "%lld\n", ans );
	}
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

