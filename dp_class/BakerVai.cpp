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

const int nax = 105, inf = 1e7 + 5; 
ll dp[nax][nax][nax];
ll inn[nax][nax];
int n, m;

ll get ( int x1, int y1, int x2 )
{
	int y2 = x1 + y1 - x2;
	if ( x1 >= n || x2 >= n || y1 >= m || y2 >= m ) return -inf;
	if ( x1==x2 && y1==y2 ) {
		if ( x1==n-1 && y1==m-1 )
			return inn[x1][y1];
		else return -inf;
	}
	if ( dp[x1][y1][x2] != -1 ) return dp[x1][y1][x2];
	ll ta =        get ( x1 + 1, y1, x2 + 1 );
	ta = max ( ta, get ( x1 + 1, y1, x2 ) );
	ta = max ( ta, get ( x1, y1 + 1, x2 + 1 ) );
	ta = max ( ta, get ( x1, y1 + 1, x2 ) );
	ta += inn[x1][y1] + inn[x2][y2];
	dp[x1][y1][x2] = ta;
	return ta;
}

void solve ()
{
	scanf ( "%d%d", &n, &m );
	for ( int i = 0 ; i < n ; ++i )
		for ( int j = 0 ; j < m ; ++j )
			scanf ( "%lld", &inn[i][j] );
	for ( int i = 0 ; i < n ; ++i )
		for ( int j = 0 ; j < m ; ++j )
			for ( int k = 0 ; k < n ; ++k )
				dp[i][j][k] = -1;
	ll ans = get ( 0, 1, 1 );
	printf ( "%lld\n", ans + inn[0][0] );
}

int main ()
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

