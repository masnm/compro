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

const int nax = 1005, ncn = 55;
const ll mod = 100000007;
vector<ll> coin, cnt;
ll memo[nax][ncn];
int n, k;

ll rec ( ll rem, int ind )
{
	if ( ind >= int(coin.size()) ) return 0;
	if ( memo[rem][ind] != -1 ) return memo[rem][ind];
	ll ans = 0;
	ll i = coin[ind];
	for ( int j = 1 ; j <= cnt[ind] ; ++j ) {
		if ( rem < (i * j) ) continue;
		else if ( rem == (i * j) ) ans += 1;
		else {
			ans += rec ( rem - (i * j), ind + 1 );
		}
	}
	ans += rec ( rem, ind + 1 );
	memo[rem][ind] = ans % mod;
	return memo[rem][ind];
}

void solve ()
{
	scanf ( "%d%d", &n, &k );
	coin.resize(n);
	cnt.resize(n);
	for ( ll& i : coin ) scanf ( "%lld\n", &i );
	for ( ll& i : cnt ) scanf ( "%lld\n", &i );
	memset ( memo, -1, sizeof memo );
	ll ans = rec(k,0);
	printf ( "%lld\n", ans );
}

int main ()
{
	int tt = 1;
	scanf ( "%d", &tt );
	for ( int i = 0 ; i < tt ; ++i ) {
		printf ( "Case %d: ", i+1 );
		solve ();
	}

	return 0;
}
