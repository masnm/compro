#include "bits/stdc++.h"
using namespace std;

#define sim template <class c
#define ris return *this
#define dor > debug &operator<<
#define eni( x )                                                               \
	sim > typename enable_if<sizeof dud<c> ( 0 ) x 1, debug &>::type           \
		  operator<< ( c i ) {
sim > struct rge {
		c b, e;
};
sim > rge<c> range ( c i, c j ) {
	return rge<c>{ i, j };
}
sim > auto dud ( c *x ) -> decltype ( cerr << *x, 0 );
sim > char dud ( ... );
struct debug {
#ifdef LOCAL
		~debug () {
			cerr << endl;
		}
		eni ( != ) cerr << boolalpha << i;
		ris;
} eni ( == ) ris << range ( begin ( i ), end ( i ) );
}
sim, class b dor ( pair<b, c> d ) {
	ris << "(" << d.first << ", " << d.second << ")";
}
sim dor ( rge<c> d ) {
	*this << "[";
	for ( auto it = d.b; it != d.e; ++it )
		*this << ", " + 2 * ( it == d.b ) << *it;
	ris << "]";
}
#else
		sim dor ( const c & ) {
			ris;
		}
#endif
}
;
#define imie( ... ) " [" << #__VA_ARGS__ ": " << ( __VA_ARGS__ ) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y <<
// ")"; return dd; }

#define F  first
#define S  second
#define eb emplace_back

using ll = long long int;

const int nax = 1e5 + 5;
vector<int> g[nax];
int dp[nax];
bool v[nax];

int dfs ( int me ) {
	int ans = -1;
	for ( const int &i : g[me] ) {
		if ( !v[i] ) {
			v[i] = true;
			ans = max ( ans, dfs ( i ) );
		}
	}
	for ( const int &i : g[me] ) {
		ans = max ( ans, dp[i] );
	}
	dp[me] = 1 + max ( dp[me], ans );
	return dp[me];
}

int main () {
	int n, m;
	scanf ( "%d%d", &n, &m );
	int s, e;
	while ( m-- ) {
		scanf ( "%d%d", &s, &e );
		--s;
		--e;
		g[s].eb ( e );
	}
	for ( int i = 0; i < n; ++i ) {
		if ( !v[i] ) {
			v[i] = true;
			dfs ( i );
		}
	}
	int ans = -1;
	for ( int i = 0; i < n; ++i ) {
		ans = max ( ans, dp[i] );
	}
	printf ( "%d\n", --ans );

	return 0;
}
