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

int n, q;
vector<ll> v, ps, mx;

inline void solve ( int _case )
{
	scanf ( "%d%d", &n, &q );
	v.resize ( n );
	for ( auto& i : v ) scanf ( "%lld", &i );
	ps.resize ( n );
	ps[0] = v[0];
	for ( int i = 1 ; i < n ; ++i ) ps[i] = ps[i-1] + v[i];
	mx.resize ( n );
	ll cmx = 0;
	for ( int i = 0 ; i < n ; ++i ) {
		cmx = max ( cmx, v[i] );
		mx[i] = cmx;
	}
	for ( int qu = 0 ; qu < q ; ++qu ) {
		ll t; scanf ( "%lld", &t );
		auto it = upper_bound ( mx.begin(), mx.end(), t );
		int ind = -1;
		if ( it == mx.end() ) ind = n-1;
		else ind = int(it-mx.begin()-1);
		printf ( "%lld ", ind==-1?0:ps[ind] );
	}
	puts ( "" );
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

