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

const int nax = 5;
int n, m, q, x, y;
vector<vector<int>> g(nax,vector<int>(nax));

void solve ()
{
	scanf("%d%d", &n, &m );
	scanf ( "%d", &q );
	for ( int i = 0 ; i < nax ; ++i ) for ( int j = 0 ; j < nax ; ++j ) g[i][j] = 0;
	for ( int i = 0 ; i < q ; ++i ) {
		scanf ( "%d%d", &x, &y );
		--x; --y;
		g[x][y] = 1;
		if ( x > 0 ) g[x-1][y] ^= 0 ^ 1;
		if ( x < n - 1 ) g[x+1][y] ^= 0 ^ 1; 
		if ( y > 0 ) g[x][y-1] ^= 0 ^ 1; 
		if ( y < m - 1 ) g[x][y+1] ^= 0 ^ 1; 
	}
	for ( int i = 0 ; i < n ; ++i ) {
		for ( int j = 0 ; j < m ; ++j ) {
			printf ( g[i][j]==0 ? "O" : "X" );
		}
		puts("");
	}
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

