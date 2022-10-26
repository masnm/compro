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

struct node {
	node () = default;
	node ( int _z, ll _zc, int _o, ll _oc ) : z(_z), zc(_zc), o(_o), oc(_oc) {}
	int z = -1;
	ll zc = 0;
	int o = -1;
	ll oc = 0;
};
debug & operator << (debug & dd, node p) { dd << "(" << p.z << ", " << p.zc << ")"; return dd; }

const int nax = 10000005;
vector<node> trie(nax);
int N = 0;
ll n;
ll mxbits = 35;
vector<ll> v;

void trie_insert ( ll in )
{
	int cur = 0;
	for ( int i = mxbits ; i > -1 ; --i ) {
		if ( in & (1LL<<i) ) {
			if ( trie[cur].o == -1 ) trie[cur].o = ++N;
			trie[cur].oc += 1;
			cur = trie[cur].o;
		} else {
			if ( trie[cur].z == -1 ) trie[cur].z = ++N;
			trie[cur].zc += 1;
			cur = trie[cur].z;
		}
	}
}

ll trie_get_sum ( ll in, int cur, int bit )
{
	if ( bit == -1 ) return 0;
	ll tsum = 0;
	if ( trie[cur].z != -1 ) {
		if ( in & (1LL<<bit) ) tsum += trie[cur].zc;
		else tsum += trie_get_sum ( in, trie[cur].z, bit-1 );
	}
	if ( trie[cur].o != -1 ) {
		if ( (in & (1LL<<bit)) == 0 ) tsum += trie[cur].oc;
		else tsum += trie_get_sum ( in, trie[cur].o, bit-1 );
	}
	return tsum;
}

int main ( void )
{
	scanf ( "%lld", &n );
	v.resize ( n );
	for ( auto& i : v ) scanf ( "%lld", &i );
	assert ( trie[0].z == -1 );
	for ( auto i : v ) trie_insert ( i );
	assert ( N < nax );
	ll ans = 0;
	for ( auto i : v ) {
		ll t = trie_get_sum ( i, 0, mxbits );
		ans += t;
	}
	printf ( "%lld\n", ans/2 );

	return 0;
}

