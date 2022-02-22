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

int main ()
{
	ll n, sum = 0LL;
	scanf ( "%lld", &n );
	ll ar[100005];
	for ( ll i = 0 ; i < n ; ++i ) {
		scanf ( "%lld", &ar[i] );
		sum += ar[i];
	}
	if ( sum % n ) {
		puts("No");
		return 0;
	} else {
		puts("Yes");
		return 0;
	}
	ll am = sum / n;
	assert ( am * n == sum );
	ll mp = -1, mv = -1;
	for ( ll i = 0 ; i < n ; ++i )
		if ( ar[i] > mv ) {
			mv = ar[i];
			mp = i;
		}
	bool ans = true;
	ll ind = mp + 1; if ( ind >= n ) ind = 0;



	return 0;
}

