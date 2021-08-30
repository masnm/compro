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

using ll = long long int;
string read_string ()
{
	static char ch[200005];
	scanf ( "%s", ch );
	return string ( ch );
}

bool ok ( const string& s )
{
	int b = 0;
	for ( char c : s ) {
		c == ')' ? --b : ++b;
		if ( b < 0 ) return false;
	}
	return b==0;
}

void solve()
{
	vector<int> v;
	string s = read_string();
	bool fa = false;
	int len = s.length();
	int ans = INT_MAX;
	string bkp = s;
	for ( int rep = 0 ; rep < 2 ; ++rep ) {
		for ( int i = 0 ; i < len ; ++i ) {
			if ( ok(s) ) {
				ans = min ( ans, i );
				fa = true;
			}
			if ( rep ) {
				char cb = s.end()[-1];
				s.pop_back();
				s.insert ( s.begin(), cb );
			} else {
				char cb = s[0];
				s.erase(0,1);
				s += cb;
			}
			debug() << imie(s);
		}
			debug() << imie("secnd");
		s = bkp;
	}
	if ( fa ) {
		printf ( "%d\n", ans);
	} else {
		puts ( "impossible" );
	}
}

int main ()
{
/*   /\
 * \/  \
 *      \
 */

	int t;
	scanf ( "%d" , &t );
	int i = 0;
	while ( t-- ) {
		printf ( "Case %d: ", ++i );
		solve();
	}

	return 0;
}

