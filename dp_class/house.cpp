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
	int n;
	scanf ( "%d", &n );
	const int INF = 1e8 + 5;
	vector<vector<int>> vvi ( n, vector<int>(3) ), dp ( n, vector<int>(3, INF ) );
	for ( auto& i : vvi )
		for ( auto& j : i )
			scanf ( "%d", &j );
	dp[0] = vvi[0];
	for ( int i = 1 ; i < n ; ++i ) {
		for ( int j = 0 ; j < 3 ; ++j ) {
			for ( int k = 0 ; k < 3 ; ++k ) {
				if ( j != k )
					dp[i][j] = min ( dp[i][j], dp[i-1][k] + vvi[i][j] );
			}
		}
	}
	printf ( "%d\n", *min_element(dp.back().begin(), dp.back().end()) );
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

