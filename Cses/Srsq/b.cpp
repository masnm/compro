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
const int INF = 1e9 + 5;

int main ()
{
	int n, q;
	scanf ( "%d%d", &n, &q );
	vector<int> v(n), b(n, INF);
	for ( int& i : v ) scanf ( "%d", &i );
	int sq = sqrt(n+.0) + 1;
	for ( int i = 0 ; i < n ; ++i )
		b[i/sq] = min ( b[i/sq], v[i] );
	while ( q-- ) {
		int sum = INF;
		int l, r;
		scanf ( "%d%d", &l, &r );
		--l; --r;
		debug() << imie(sq) imie(v);
		debug() << imie(n) imie(l) imie(r);
		int c_l = l / sq, c_r = r / sq;
		if (c_l == c_r)
			for (int i=l; i<=r; ++i)
				sum = min ( sum, v[i] );
		else {
			for (int i=l, end=(c_l+1)*sq-1; i<=end; ++i)
				sum = min ( sum, v[i] );
			for (int i=c_l+1; i<=c_r-1; ++i)
				sum = min ( sum, b[i] );
			for (int i=c_r*sq; i<=r; ++i)
				sum = min ( sum, v[i] );
		}
		printf ( "%d\n", sum );
	}

	return 0;
}

