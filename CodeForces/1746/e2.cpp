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
string s, p;

void quer ( int l, int h )
{
	cout << "? " << h-l+1 << " ";
	for ( int i = l ; i <= h ; ++i )
		cout << i << " ";
	cout << endl;
	cout.flush ();
	cin >> s;
}

int main ( void )
{
	scanf ( "%d", &n );
	int low = 1, high = n, mid;
	while ( high - low > 1 ) {
		quer ( low, high );
		mid = low + (high - low) / 2;
		if ( s == "NO" ) {
			quer ( low, mid );
			if ( s == "YES" ) high = mid;
			else low = mid + 1;
		} else {
			quer ( low, mid );
			p = s;
			quer ( low, mid );
			if ( p == s ) {
				if ( s == "YES" ) high = mid;
				else low = mid + 1;
			}
		}
	}
	cout << "! " << low;
	cout << endl;
	cout.flush ();
	cin >> s;
	if ( s == ":)" ) return 0;
	cout << "! " << high;
	cout << endl;
	cout.flush ();
	cin >> s;

	return 0;
}
