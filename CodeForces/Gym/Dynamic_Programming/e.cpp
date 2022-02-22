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

void solve ()
{
	const ll INF = (1LL<<61) + 5;

	int n, m, x; scanf ( "%d%d%d", &n, &m, &x );

	vector<int> pos ( n ), key ( m );

	for ( int& i : pos ) scanf ( "%d", &i );
	for ( int& i : key ) scanf ( "%d", &i );

	sort ( pos.begin(), pos.end() );
	sort ( key.begin(), key.end() );

	vector<vector<ll>> dp ( n + 1, vector<ll> ( m + 1, INF ) );
	dp[0][0] = 0;

	for ( int i = 0 ; i <= n ; ++i ) {
		for ( int j = 0 ; j < m ; ++j ) {
			// don't take this person
			dp[i][j + 1] = min ( dp[i][j + 1], dp[i][j] );
			// take this person
			if ( i < n )
			dp[i + 1][j + 1] = min ( dp[i + 1][j + 1],
					max ( dp[i][j], ll(abs(pos[i] - key[j])) + abs(key[j] - x) ) );
		}
	}

	printf ( "%lld\n", dp[n][m] );
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

