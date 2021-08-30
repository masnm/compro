#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

struct BIT {
	ll n1, n2;
	vector<ll> b1, b2;
	BIT ( ll _n ) : n1(_n+1), n2(_n+1)
	{
		b1.assign ( n1, 0 );
		b2.assign ( n2, 0 );
	}
	void add1 ( ll ind, ll x )
	{
		for ( ++ind ; ind < n1 ; ind += ( ind & ( -ind ) ) )
			b1[ind] += x;
	}
	void add2 ( ll ind, ll x )
	{
		for ( ++ind ; ind < n1 ; ind += ( ind & ( -ind ) ) )
			b2[ind] += x;
	}
	void range_add ( ll l, ll r, ll x )
	{
		add1 ( l, x );
		add1 ( r+1, -x );
		add2 ( l, x*(l-1) );
		add2 ( r+1, -x*r );
	}
	ll sum1 ( ll ind )
	{
		ll total = 0;
		for ( ++ind ; ind > 0 ; ind -= ( ind & ( -ind ) ) )
			total += b1[ind];
		return total;
	}
	ll sum2 ( ll ind )
	{
		ll total = 0;
		for ( ++ind ; ind > 0 ; ind -= ( ind & ( -ind ) ) )
			total += b2[ind];
		return total;
	}
	ll prefix_sum ( ll ind )
	{
		return sum1 ( ind ) * ind - sum2 ( ind );
	}
	ll sum ( ll l, ll r )
	{
		return prefix_sum ( r ) - prefix_sum ( l-1 );
	}
};

void solve ()
{
	int n, c;
	scanf ( "%d%d", &n, &c );
	ll t, p, q, v;
	BIT bit ( n );
	for ( int cc = 0 ; cc < c ; ++cc ) {
		scanf ( "%lld", &t );
		if ( t == 0LL ) {
			scanf ( "%lld%lld%lld", &p, &q, &v );
			bit.range_add ( p-1, q-1, v );
		} else {
			scanf ( "%lld%lld", &p, &q );
			printf ( "%lld\n", bit.sum ( p-1, q-1 ) );
		}
	}
}

int main ( int argc, char** argv )
{
	int t;
	scanf ( "%d", &t );
	for ( int tt = 0 ; tt < t ; ++tt ) {
		solve ();
	}
	
	puts("");
	return 0;
}
