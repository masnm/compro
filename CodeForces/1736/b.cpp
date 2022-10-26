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
vector<ll> a, b;

ll lcm ( ll _a, ll _b ) { return ( _a*_b ) / __gcd ( _a, _b ); }

inline void solve ( int _case )
{
	(void) _case;
	scanf ( "%d", &n );
	a.resize ( n );
	for ( auto& i : a ) scanf ( "%lld", &i );
	b.resize ( n + 1 );
	b[0] = b[n] = -1;
	for ( int i = 0 ; i < n - 1 ; ++i )
		b[i+1] = lcm ( a[i], a[i+1] );
	debug() << imie(a);
	debug() << imie(b);
	b[0] = a[0]; b[n] = a[n-1];
	debug() << imie(a);
	debug() << imie(b);
	for ( int i = 0 ; i < n ; ++i )
		if ( __gcd ( b[i], b[i+1] ) != a[i] ) {
			puts ( "NO" );
			return;
		}
	puts ( "YES" );
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

/*
 *  x y z
 * p q r s
 */
