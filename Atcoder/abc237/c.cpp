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
	static char ch[1000006];
	scanf ( "%s", ch );
	return string ( ch );
}

bool pal ( string& s )
{
	int n = s.length();
	for ( int i = 0 ; i < n/2 ; ++i )
		if ( s[i] != s[n-i-1] )
			return false;
	return true;
}

int cn ( string& s )
{
	int cnt = 0;
	for ( int i = int(s.length()) - 1 ; i > -1 ; --i ) {
		if ( s[i] != 'a' )
			break;
		++cnt;
	}
	return cnt;
}

void solve ()
{
	string s = read_string();
	if ( pal ( s ) ) { puts ( "Yes" ); return; }

	int cntr = cn ( s );
	reverse ( s.begin(), s.end() );
	int cntl = cn ( s );
	reverse ( s.begin(), s.end() );

	debug() << imie(s) imie(cntl) imie(cntr);
	if ( cntl >= cntr ) {
		puts ( "No" ); return;
	} else {
		s = s.substr ( 0, int(s.length())-(cntr-cntl) );
	}
	debug() << imie(s);
	if ( pal ( s ) ) { puts ( "Yes" ); return; }
	puts ( "No" );
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

