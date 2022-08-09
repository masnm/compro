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

int main ( void )
{
	string s = "abcd";
	debug() << imie(s);
	s.erase ( s.begin()+1 );
	debug() << imie(s);

	return 0;
}

int main2 ( int argc, char* argv[] )
{
	string in = read_string ();
	int tlen; scanf ( "%d", &tlen );
	string ans;
	for ( auto c : in ) if ( c >= 'a' && c <= 'z' ) ans += c;
	int ind = 0;
	for ( int i = 0 ; i < int(in.length()) ; ++i ) {
		if ( in[i] == '?' && int(ans.length()) > tlen ) {
		} else if ( in[i] == '*' ) {
		}
	}
	if ( int(ans.length()) == tlen ) printf ( "%s\n", ans.c_str() );
	printf ( "Impossible" );

	return 0;
}

