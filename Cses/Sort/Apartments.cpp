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

const int nax = 2e5 + 5;
int n, m, k, as, bs, ans;
int a[nax], b[nax];

int ok ( int l, int r )
{
	if ( a[l] >= (b[r]-k) && a[l] <= (b[r]+k) ) return 0;
	else if ( a[l] < (b[r]-k) ) return 1;
	else if ( a[l] > (b[r]+k) ) return -1;
	else assert(false);
}

int main ()
{
	scanf ( "%d%d%d", &n, &m, &k );
	for ( int i = 0 ; i < n ; ++i ) scanf ( "%d", a+i );
	for ( int i = 0 ; i < m ; ++i ) scanf ( "%d", b+i );
	sort ( a, a+n ); sort ( b, b+m );
	as = 0; bs = 0; ans = 0;
	while ( as < n && bs < m ) {
		switch ( ok( as, bs ) ) {
			case 0 : { ++ans; ++as; ++bs; break; }
			case 1 : { ++as; break; }
			case -1 : { ++bs; break; }
			default : { assert(false); break; }
		}
	}
	printf ( "%d\n", ans );

	return 0;
}
