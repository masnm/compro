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

vector<int> a, b;

void solve ()
{
	int n; scanf ( "%d", &n );
	a.resize ( n ); b.resize ( n );
	for ( auto& i : a ) scanf ( "%d", &i );
	for ( auto& i : b ) scanf ( "%d", &i );
	for ( int i = 0 ; i < n ; ++i ) {
		if ( b[i] > a[i] ) {
			puts ( "NO" );
			return;
		}
	}
	bool fixed = false; int val = -1;
	for ( int i = 0 ; i < n ; ++i ) {
		if ( b[i] == 0 ) continue;
		fixed = true;
		val = a[i] - b[i];
		break;
	}
	if ( !fixed ) { puts ( "YES" ); return; }
	for ( int i = 0 ; i < n ; ++i ) {
		a[i] -= val;
		a[i] = max ( 0, a[i] );
		if ( a[i] != b[i] ) {
			puts ( "NO" );
			return;
		}
	}
	puts ( "YES" );
	// for ( int i = 0 ; i < n ; ++i ) {
	// 	if ( b[i] > a[i] ) { puts ( "NO" ); return; }
	// 	if ( b[i] == 0 && !fixed ) continue;
	// 	if ( b[i] == 0 && fixed && a[i] > val ) { puts ( "NO" ); return; }
	// 	else if ( b[i] == 0 ) continue;
	// 	if ( !fixed ) {
	// 		fixed = true;
	// 		val = a[i] - b[i];
	// 	} else if ( a[i] - b[i] != val ) {
	// 		puts ( "NO" ); return;
	// 	}
	// }
	// puts ( "YES" );
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

