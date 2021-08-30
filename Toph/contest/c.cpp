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

ll power ( ll a, ll b, ll md )
{
	ll result = 1;
	while ( b > 0 ) {
		if ( b&1 ) result = (result * a) % md;
		a = (a * a) % md;
		b /= 2;
	}
	return result;
}

using ll = long long int;
ll a, b, n, m, mod;

void solve ()
{
	scanf ( "%lld%lld%lld%lld%lld", &a, &b, &n, &m, &mod );
	debug() << imie(a) imie(b) imie(n) imie(m) imie(mod);
	ll rp = power(a,n) - 1LL;
	rp /= (a - 1);
	--rp;
	rp %= mod;
	rp = ( b * rp ) % mod;
}

int main ()
{
	ll t;
	scanf ( "%lld", &t );
	while ( t-- ) solve();


	puts("");
	return 0;
}

