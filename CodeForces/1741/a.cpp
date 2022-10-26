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

string a, b;

int get_code ( char _a )
{
	if ( _a == 'S' ) return 1;
	if ( _a == 'M' ) return 2;
	if ( _a == 'L' ) return 3;
	assert ( false );
}

bool my_less ( char _a, char _b )
{
	int l = get_code ( _a ), r = get_code ( _b );
	if ( l < r ) return true;
	else return false;
}

inline void solve ( int _case )
{
	a = read_string (); b = read_string ();
	if ( a == b ) {
		puts ( "=" );
		return;
	}
	if ( my_less ( a.back(), b.back() ) ) {
		puts ( "<" );
		return;
	}
	if ( my_less ( b.back(), a.back() ) ) {
		puts ( ">" );
		return;
	}
	assert ( a.back() == b.back() );
	if ( a.back() == 'L' ) {
		if ( a.length() > b.length() ) {
			puts ( ">" );
		} else {
			puts ( "<" );
		}
	} else {
		if ( a.length() < b.length() ) {
			puts ( ">" );
		} else {
			puts ( "<" );
		}
	}
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

