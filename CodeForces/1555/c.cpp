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

const int nax = 1e5 + 5;
int n;
ll in[2][nax];
ll ps[2][nax];

void solve ()
{
	scanf ( "%d", &n );
	for ( int j = 0 ; j < 2 ; ++j )
		for ( int i = 0 ; i < n ; ++i )
			scanf ( "%lld", &in[j][i] );
//	int x = 0, y = 0;
//	while ( y < n ) {
//		in[x][y] = 0;
//		if ( x == 1 ) {
//			++y;
//		} else if ( y == n - 1 ) {
//			++x;
//		} else {
//			if ( in[x+1][y] > in[x][y+1] )
//				++x;
//			else
//				++y;
//		}
//	}
//	for ( int j = 0 ; j < 2 ; ++j, fprintf ( stderr, "\n" ) )
//		for ( int i = 0 ; i < n ; ++i )
//			fprintf ( stderr, "%d ", in[j][i] );
	ll ba = LLONG_MAX;
	ps[0][0] = in[0][0];
	for ( int i = 1 ; i < n ; ++i ) ps[0][i] = ps[0][i-1] + in[0][i];
	ps[1][n-1] = in[1][n-1];
	for ( int i = n - 2 ; i > -1 ; --i ) ps[1][i] = ps[1][i+1] + in[1][i];
	for ( int i = 0 ; i < n ; ++i ) {
		ll tba = max ( ps[0][n-1] - ps[0][i], ps[1][0] - ps[1][i] );
		ba = min ( ba, tba );
	}
	printf ( "%lld\n", ba );
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

