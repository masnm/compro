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

map<int, bool> mp;

void solve ()
{
	int n;
	scanf ( "%d", &n );
	vector<int> a ( n ), b ( n - 1 ), c ( n - 2 );
	for ( int i = 0 ; i < n ; ++i ) scanf ( "%d", &a[i] );
	for ( int i = 0 ; i < n - 1 ; ++i ) scanf ( "%d", &b[i] );
	for ( int i = 0 ; i < n - 2 ; ++i ) scanf ( "%d", &c[i] );
	sort ( a.begin(), a.end() );
	sort ( b.begin(), b.end() );
	sort ( c.begin(), c.end() );
	bool printed = false;
	for ( int i = 0 ; i < n - 1 ; ++i ) {
		if ( b[i] != a[i] ) {
			printed = true;
			printf ( "%d\n", a[i] );
			break;
		}
	}
	if ( !printed ) printf ( "%d\n", a.back() );
	printed = false;
	for ( int i = 0 ; i < n - 2 ; ++i ) {
		if ( b[i] != c[i] ) {
			printed = true;
			printf ( "%d\n", b[i] );
			break;
		}
	}
	if ( !printed ) printf ( "%d\n", b.back() );
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

