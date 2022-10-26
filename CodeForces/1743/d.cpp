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
string s;

int main ( void )
{
	scanf ( "%d", &n );
	s = read_string ();
	reverse ( s.begin(), s.end() );
	while ( s.size() > 0 && s.back() == '0' )
		s.pop_back();
	if ( s.empty() ) {
		puts ( "0" );
		return 0;
	}
	reverse ( s.begin(), s.end() );
	int ind = 0;
	n = s.length();
	while ( ind < n && s[ind] == '1' ) ++ind;
	if ( ind == n ) {
		puts ( s.c_str() );
		return 0;
	}
	int cnt = 0, bind = ind;
	while ( ind < n && s[ind] == '0' ) ++ind, ++cnt;
	if ( ind >= n ) {
		for ( int i = 0 ; i < n ; ++i ) printf ( "%c", '1' );
		return 0;
	}
	int shift = bind - cnt + 1;
	shift = min ( shift, cnt );
	for ( int i = 0 ; i < n ; ++i ) {
		char c = s[i];
		if ( i-shift > -1 ) c = max ( c, s[i-shift] );
		printf ( "%c", c );
	}

	return 0;
}

