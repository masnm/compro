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

const int nax = 1<<19;
pair<int,int> tree[nax];
int n, th;
string s;
vector<ll> v;
vector<pair<int,int>> vp;

inline void solve ( int _case )
{
	scanf ( "%d", &n );
	s = read_string ();
	v.resize ( n );
	for ( auto& i : v ) scanf ( "%lld", &i );
	th = 1;
	while ( th <= n ) th <<= 1;
	for ( int i = 0 ; i < 2*th ; ++i ) tree[i] = {INT_MAX, INT_MAX};
	for ( int i = 0 ; i < n ; ++i ) {
		tree[th+i] = {v[i], i};
	}
	for ( int i = th-1 ; i > 0 ; --i ) tree[i] = min ( tree[i*2], tree[i*2+1] );
	vp.clear();
	char prev = 'o';
	int cnt = 1;
	for ( int i = 0 ; i < n ; ++i ) {
		if ( s[i] != prev ) {
			if ( prev == '1' ) {
				vp.eb ( i-cnt, i-1 );
			}
			prev = s[i];
			cnt = 1;
		} else {
			++cnt;
		}
	}
	if ( prev == '1' ) {
		vp.eb ( n-cnt, n-1 );
	}
	for ( auto& item : vp ) {
		if ( item.F == 0 ) continue;
		if ( s[item.F-1] == '1' ) continue;
		pair<int,int> mn = {INT_MAX, INT_MAX};
		int l = item.F, r = item.S;
		l += th; r += th + 1;
		while ( l < r ) {
			if ( l&1 ) mn = min ( mn, tree[l++] );
			if ( r&1 ) mn = min ( mn, tree[--r] );
			l >>= 1; r >>= 1;
		}
		if ( mn.F <= v[item.F-1] ) {
			s[item.F-1] = '1';
			s[mn.S] = '0';
		}
	}
	ll ans = 0;
	for ( int i = 0 ; i < n ; ++i )
		if ( s[i] == '1' )
			ans += v[i];
	printf ( "%lld\n", ans );
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

