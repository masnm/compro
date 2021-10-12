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

using ll = long long int;
string read_string ()
{
	static char ch[15];
	scanf ( "%s", ch );
	return string ( ch );
}

int val ( char a )
{
	int ans = -1;
	switch ( a ) {
		case 'Q': ans = 9; break;
		case 'R': ans = 5; break;
		case 'B': ans = 3; break;
		case 'N': ans = 3; break;
		case 'P': ans = 1; break;
		case 'K': ans = 0; break;
	}
	return ans;
}

void solve ()
{
	int a = 0, b = 0;
	for ( int i = 0 ; i < 8 ; ++i ) {
		string s = read_string();
		debug() << imie(s);
		for ( char c : s ) {
			if ( c >= 'a' && c <= 'z' )
				a += val ( c - 'a' + 'A' );
			else if ( c >= 'A' && c <= 'Z' )
				b += val ( c );
		}
		debug() << imie(a) imie(b);
	}
	if ( a == b ) puts ( "Draw" );
	else if ( a < b ) puts ( "White" );
	else puts ( "Black" );
}

int main ()
{
	int t = 1;
//	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

