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

void special ( vector<ll> v )
{
	if ( v[0] == v[1] ) {
		if ( v[2] % 2LL == 0 ) puts ( "YES" );
		else puts ( "NO" );
	} else if ( v[1] == v[2] ) {
		if ( v[0] % 2LL == 0 ) puts ( "YES" );
		else puts ( "NO" );
	} else assert ( false );
}

void solve ()
{
	vector<ll> v ( 3 );
	for ( auto& i : v ) scanf ( "%lld", &i );
	sort ( v.begin(), v.end() );
	vector<ll> cv = v;
	cv.resize ( unique ( cv.begin(), cv.end() ) - cv.begin() );
	if ( cv.size() != size_t(3) ) return special ( v );
	ll need = v[0] + v[1];
	if ( v.back() == need ) puts ( "YES" );
	else puts ( "NO" );
}

int main ( int argc, char* argv[] )
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

