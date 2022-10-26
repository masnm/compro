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
int tree[nax], th;
vector<pair<ll,ll>> vp;
vector<ll> cc, v;
int cn, n, q, l, r, x;

void tree_add ( int _l, int _r )
{
	_l += th; _r += th + 1;
	while ( _l < _r ) {
		if ( _l&1 ) tree[_l++] += 1;
		if ( _r&1 ) tree[--_r] += 1;
		_l >>= 1; _r >>= 1;
	}
}

int get_sum ( int ind )
{
	ind += th;
	int sum = 0;
	for ( ; ind > 0 ; ind >>= 1 )
		sum += tree[ind];
	return sum;
}

inline void solve ( int _case )
{
	scanf ( "%d%d", &n, &q );
	vp.resize ( n );
	for ( auto& i : vp ) scanf ( "%lld%lld", &i.F, &i.S );
	v.resize ( q );
	for ( auto& i : v ) scanf ( "%lld", &i );
	cc.clear();
	for ( auto& i : vp ) cc.eb ( i.F ), cc.eb ( i.S );
	for ( auto& i : v ) cc.eb ( i );
	sort ( cc.begin(), cc.end () );
	cc.resize ( unique ( cc.begin(), cc.end() ) - cc.begin() );
	cn = cc.size ();
	th = 1;
	while ( th <= cn ) th <<= 1;
	for ( int i = 0 ; i < th*2 ; ++i ) tree[i] = 0;
	for ( auto& i : vp ) {
		l = int(lower_bound ( cc.begin(), cc.end(), i.F ) - cc.begin() );
		r = int(lower_bound ( cc.begin(), cc.end(), i.S ) - cc.begin() );
		tree_add ( l, r );
	}
	for ( auto& i : v ) {
		x = int(lower_bound ( cc.begin(), cc.end(), i ) - cc.begin() );
		printf ( "%d\n", get_sum(x) );
	}
}

int main ( void )
{
	int _t = 1;
	scanf ( "%d" , &_t );
	for ( int i = 0 ; i < _t ; ++i ) {
		printf ( "Case %d:\n", i+1 );
		solve ( i+1 );
	}


	return 0;
}

