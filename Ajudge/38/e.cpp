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
	static char ch[100005];
	scanf ( "%s", ch );
	return string ( ch );
}

void solve ()
{
	string s = read_string ();
	int len = s.length ();
	vector<int> va, vb;
	for ( int i = 0 ; i < len - 1 ; ++i ) {
		if ( s[i] == 'A' && s[i+1] == 'B' ) va.eb(i);
		else if ( s[i] == 'B' && s[i+1] == 'A' ) vb.eb(i);
	}
	if ( va.empty () || vb.empty () ) {
		puts ( "NO" );
	} else if ( *(vb.end()-1) - *va.begin() > 1 ) {
		puts ( "YES" );
	} else if ( *(va.end()-1) - *vb.begin() > 1 ) {
		puts ( "YES" );
	} else {
		puts ( "NO" );
	}
	debug() << imie(va);
	debug() << imie(vb);
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

