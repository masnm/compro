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
	static char ch[25];
	scanf ( "%s", ch );
	return string ( ch );
}

int get ( string& s )
{
	if ( s.length() == 0 ) return 0;
	char c = s.back()-'0';
	s.pop_back();
	return c;
}

void solve ( int x )
{
	string a = read_string(), s = read_string();
	string b = "";
	bool ans = true;
	while ( true ) {
		if ( s.length() < a.length() ) ans = false;
		if ( s.length() == 0 && a.length() == 0 ) break;
		if ( s.length() == 0 && a.length() != 0 ) ans = false;
		int _a = get ( a );
		int _s = get ( s );
		if ( _s < _a ) {
			if ( s.length() == 0 ) ans = false;
			_s += 10 * get ( s );
		}
		if ( _s > 18 ) ans = false;
		if ( _s < _a ) ans = false;
		b += (char)(_s - _a + '0');
	}
	if ( ans ) {
		while ( b.length() > 0 && b.back() == '0' )
			b.pop_back();
		assert ( b.length() != 0 );
		reverse ( b.begin(), b.end() );
		printf ( "%s\n", b.c_str() );
	} else puts("-1");
}

int main ()
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ( i );
	}


	return 0;
}

