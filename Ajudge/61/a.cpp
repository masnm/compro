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

string read_string ( void )
{
	static char ch[1000005];
	scanf ( "%s", ch );
	return string ( ch );
}

using ll = long long int;

map<pair<ll,ll>,ll> mp;
ll md = 1000;

ll solve ( ll _n, ll _m )
{
	auto src = mp.find ( {_n, _m} );
	if ( src != mp.end() ) return src->S;
	ll ans;
	if ( _n == 1 ) {
		ans = _m + _m;
	} else if ( _n > 1 && _m == 1 ) {
		ans = 2;
	} else if ( _n > 1 && _m > 1 ) {
		ans = solve ( _n-1, solve ( _n, _m - 1 ) );
	} else {
		assert ( false );
	}
	ans %= md;
	mp[{_n, _m}] = ans;
	return ans;
}

int main ( void )
{
	//freopen("ackerman.in", "r", stdin);
	//freopen("ackerman.out", "w", stdout);
	ll t; scanf ( "%lld", &t );
	ll n = 105, m = 105;
	md = t*101;
	int cn = 1;
	while ( true ) {
		scanf ( "%lld %lld", &n, &m );
		if ( n == m && n == 0 ) break;
		printf ( "Case %d: ", cn );
		if ( t != 1 ) printf ( "%lld\n", solve ( n, m )%t );
		else printf ( "%d\n", 0 );
		++cn;
	}

	return 0;
}

