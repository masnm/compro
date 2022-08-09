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

struct P {
	P () = default;
	P ( int _s, int _c, ll _m ) : start(_s), cover(_c), money(_m) { }
	int start = 0;
	int cover = 0;
	ll money = 0;
};
debug & operator << (debug & dd, P p)
{
	dd << "(" << p.start << ", " << p.cover << ", " << p.money << ")";
	return dd;
}

int n, mx, th;
vector<P> v;
vector<ll> tr;

ll tree_get ( int l, int r )
{
	l += th; r += th;
	ll ret = 0;
	while ( l < r ) {
		if ( l & 1 ) ret = max ( ret, tr[l++] );
		if ( r & 1 ) ret = max ( ret, tr[--r] );
		l >>= 1; r >>= 1;
	}
	return ret;
}

void tree_add ( int ind, ll val )
{
	ind += th;
	tr[ind] = val;
	ind >>= 1;
	while ( ind > 0 ) {
		tr[ind] = max ( tr[ind*2], tr[ind*2+1] );
		ind >>= 1;
	}
}

void solve ()
{
	mx = -1;
	scanf ( "%d", &n );
	v.resize ( n );
	for ( auto& i : v ) {
		scanf ( "%d%d%lld", &i.start, &i.cover, &i.money );
		mx = max ( mx, i.start + i.cover + 16 );
	}
	sort ( v.begin(), v.end(), []( auto& l, auto& r ) {
			return l.start < r.start;
			// return ( l.start + l.cover ) < ( r.start + r.cover );
			} );
	th = 1;
	while ( th <= mx ) th <<= 1;
	tr.resize ( th*2 );
	for ( auto& i : tr ) i = 0LL;
	for ( auto& i : v ) {
		ll got = tree_get ( 0, i.start-1 );
		got += i.money;
		if ( got > tr[i.start+i.cover] )
			tree_add ( i.start+i.cover, got );
	}
	printf ( "%lld\n", tr[1] );
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

