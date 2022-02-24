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

const vector<pair<ll,ll>> vp {
	{ 6, 15 },
	{ 8, 20 },
	{ 10, 25 }
};

void operator+= ( pair<ll,ll>& a, pair<ll,ll> b )
{
	a.F += b.F;
	a.S += b.S;
}

ll get ( ll& a, ll sl, ll tm )
{
	if ( a <= sl ) {
		a = 0;
		return tm;
	}
	ll div = a / sl;
	a %= sl;
	return ( div * tm );
}

ll get ( ll rem )
{
	if ( rem == 0 ) return 0LL;
	ll crem = rem, ans = LLONG_MAX;
	for ( pair<ll,ll> p : vp ) {
		rem = crem;
		ll tt = get ( rem, p.F, p.S );
		ans = min ( ans, tt + get ( rem ) );
	}
	return ans;
}

void solve ()
{
	ll a; scanf ( "%lld", &a );
	ll ans = max ( 6LL, a+1 ) / 2 * 5;
	// ll ans = get(a);
	printf ( "%lld\n", ans );
}

int main ()
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

