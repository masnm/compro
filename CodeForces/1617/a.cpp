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
	static char ch[105];
	scanf ( "%s", ch );
	return string ( ch );
}

int a = 0, b = 0, c = 0;

void doa ( string& s )
{
	int pos = 0;
	for ( int i = 0 ; i < (int)s.length() ; ++i ) {
		if ( s[i] == 'b' ) {
			pos = i;
			break;
		}
	}
	while ( c-- ) s[pos++] = 'c';
	while ( b-- ) s[pos++] = 'b';
	printf ( "%s\n", s.c_str() );
}

void solve ()
{
	string s = read_string (), t = read_string ();
	sort ( s.begin(), s.end() );
	if ( s.find("a")==string::npos || s.find("b")==string::npos || s.find("c")==string::npos ) {
		printf ( "%s\n", s.c_str() );
		return;
	}
	a = 0; b = 0; c = 0;
	for ( char& x : s ) {
		if ( x == 'a' ) ++a;
		if ( x == 'b' ) ++b;
		if ( x == 'c' ) ++c;
	}
	if ( t == "abc" ) doa ( s );
	else printf ( "%s\n", s.c_str() );
}

int main ()
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

