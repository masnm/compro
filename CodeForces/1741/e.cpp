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
vector<ll> v;
vector<vector<int>> vvi;
vector<bool> ts;

bool can_sl ( int ind )
{
	if ( ind == n ) return true;
	else if ( ind > n ) return false;
	if ( ts[ind] ) return false;
	if ( can_sl ( v[ind] + ind + 1 ) ) return true;
	else {
		for ( auto i : vvi[ind] )
			if ( can_sl ( i + 1 ) ) return true;
	}
	ts[ind] = true;
	return false;
}

inline void solve ( int _case )
{
	scanf ( "%d", &n );
	ts.resize ( n );
	fill ( ts.begin(), ts.end(), false );
	vvi.resize ( n );
	for ( auto& i : vvi ) i.clear();
	v.resize ( n );
	for ( auto& i : v ) scanf ( "%lld", &i );
	for ( int i = 0 ; i < n ; ++i )
		if ( v[i] <= i )
			vvi[i-v[i]].eb ( i );
	if ( can_sl ( 0 ) ) puts ( "YES" );
	else puts ( "NO" );
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

