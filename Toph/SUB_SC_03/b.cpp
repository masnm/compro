#include "bits/stdc++.h"
using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0LL) x 1LL, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0LL);
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
	*this << ", " + 2LL * (it == d.b) << *it;
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

int main ()
{
	ll t = 1LL, temp;
	scanf ( "%lld" , &t );
	int pc = 0LL, nc = 0LL, zc = 0LL;
	for ( int i = 0LL ; i < t ; ++i ) {
		scanf ( "%lld", &temp );
		if ( temp == 0LL ) ++zc;
		else if ( temp > 0LL ) ++pc;
		else if ( temp < 0LL ) ++nc;
		else assert(false);
	}
	ll ans = 0LL;
	if ( pc==t || nc==t || zc == t )
		if ( nc == t ) {
			ans = t;
		} else {
			ans = 0LL;
		}
	else {
		if ( pc == 0LL ) {
			ans = nc;
			assert(zc!=0LL);
		} else if ( nc == 0LL ) {
			ans = 1LL;
		} else if ( zc == 0LL ) {
			ans = nc;
			assert(pc!=0LL);
		} else {
			ans = nc + 2LL;
			assert(pc!=0LL);
			assert(zc!=0LL);
		}
	}
	printf ( "%lld\n", ans );


	return 0LL;
}

