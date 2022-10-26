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

int main ( void )
{
	scanf ( "%d", &n );
	int low = 1;
	int high = n;
	while ( low < high ) {
		if ( high - low == 1 ) {
			printf ( "! %d", low );
			fflush ( stdout );
			string s = read_string ();
			if ( s == ":)" ) return 0;
			printf ( "! %d", high );
			fflush ( stdout );
			s = read_string ();
			assert ( s == ":)" );
		}
		int mid = low + (high-low)/2;
		int ans[3];
		for ( int x = 0 ; x < 3 ; ++x ) {
			printf ( "? %d ", mid - low + 1 );
			for ( int i = low ; i <= mid ; ++i ) {
				printf ( "%d ", i );
			}
			fflush ( stdout );
			string s = read_string();
			if ( s == "YES" ) ans[x] = 1;
			else ans[x] = 0;
		}
		if ( ans[0] == ans[1] && ans[0] == ans[2] ) {
			if ( ans[0] == 1 ) {
				high = mid;
			} else {
				low = mid + 1;
			}
		} else if ( ans[0] == ans[1] ) {
			if ( ans[0] == 1 ) high = mid;
			else low = mid + 1;
		} else if ( ans[1] == ans[2] ) {
			if ( ans[1] == true ) high = mid;
			else low = mid + 1;
		}
	}
	printf ( "! %d", low );

	return 0;
}
/*
 [...............] [...............]
 */
