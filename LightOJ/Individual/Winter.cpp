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

string read_string ()
{
	static char ch[1000005];
	scanf ( "%s", ch );
	return string ( ch );
}

using ll = long long int;

ll inf = 1e18+5;
int n, k, th;
vector<ll> v, dp, tr;
map<ll,ll> mp;

ll tree_get ( int s, int e )
{
	s += th; e += th;
	ll ret = LLONG_MAX;
	while ( s < e ) {
		if ( s & 1 ) ret = min ( ret, tr[s++] );
		if ( e & 1 ) ret = min ( ret, tr[--e] );
		s >>= 1; e >>= 1;
	}
	return (ret==LLONG_MAX?0:ret);
}

void tree_add ( int ind, ll val )
{
	ind += th;
	tr[ind] = val;
	ind >>= 1;
	while ( ind > 0 ) {
		tr[ind] = min ( tr[ind*2], tr[ind*2+1] );
		ind >>= 1;
	}
}

void solve ()
{
	mp.clear();
	scanf ( "%d%d", &n, &k );
	v.resize ( n );
	for ( auto& i : v ) scanf ( "%lld", &i );
	sort ( v.begin(), v.end() );
	th = 1;
	while ( th <= n ) th *= 2;
	tr.resize ( th * 2 );
	for ( int i = 0 ; i < 2*th ; ++i ) tr[i] = inf;
	dp.resize ( n + 1 );
	for ( auto& i : dp ) i = inf;
	dp[0] = 0;
	tree_add ( 0, 0 );
	for ( int i = 0 ; i < n ; ++i ) {
		int tar = v[i] - 2*k;
		auto x = lower_bound ( v.begin(), v.end(), tar );
		int index = int( x - v.begin() );
		ll tg = tree_get ( index, i-1 );
		if ( index < i-1 ) dp[i+1] = min ( dp[i+1], 1 + tg );
		if ( dp[i+1] != inf) tree_add ( i + 1, dp[i+1] );
	}
	if ( dp[n] == inf ) {
		printf ( "-1\n" );
	} else {
		printf ( "%lld\n", dp[n] );
	}
}

int main ( int argc, char* argv[] )
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
		printf ( "Case %d: ", i+1 );
		solve ();
	}

	return 0;
}

