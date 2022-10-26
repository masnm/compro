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

int n;
vector<ll> v, cnt;
vector<pair<ll,ll>> vp;

inline void solve ( int _case )
{
	scanf ( "%d", &n );
	v.resize ( n );
	cnt.resize ( n );
	for ( auto& i : v ) scanf ( "%lld", &i );
	if ( n == 1 ) {
		if ( v[0] % 2 == 0 ) puts ( "0" );
		else puts ( "-1" );
		return;
	}
	pair<ll,ll> p = make_pair(0,0);
	vp.resize ( n );
	fill ( vp.begin(), vp.end(), p );
	for ( int i = 0 ; i < n ; ++i ) {
		ll cur = v[i];
		for ( ll j = 32 ; j > -1 ; --j ) {
			ll val = 1LL << j;
			if ( val >= cur ) {
				val -= cur;
				vp[i].F += j;
			}
		}
		vp[i].S = n-i;
		cnt[i] = vp[i].F;
	}
	for ( auto& i : vp ) i.F *= ( ll(n) - i.S + 1LL );
	sort ( vp.begin(), vp.end() );
	int ind = 0;
	while ( ind < n && v[ind] == 1 ) ++ind;
	if ( ind == n ) { puts ( "1" ); return; }
	ll mc = LLONG_MAX;
	for ( int i = 0 ; i < n ; ++i ) {
		mc = min ( mc, ll(__builtin_ctzll ( v[i] )) );
	}
	debug() << imie(v) imie(mc);
	if ( mc > n ) { puts ( "0" ); return; }
	int ans = 0;
	for ( auto& i : vp ) {
		mc += i.F;
		++ans;
		if ( mc > n ) {
			printf ( "%d\n", ans );
			return;
		}
	}
	puts ( "-1" );
}

int main ( void )
{
	int _t = 1;
	scanf ( "%d" , &_t );
	for ( int i = 0 ; i < _t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ( i+1 );
	}


	return 0;
}

