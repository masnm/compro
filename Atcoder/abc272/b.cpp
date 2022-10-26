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

inline void solve ( int _case )
{
	int n, m, k; scanf ( "%d%d", &n, &m );
	vector<int> v;
	vector<vector<bool>> vvb ( n, vector<bool>(n) );
	for ( int i = 0 ; i < m ; ++i ) {
		scanf ( "%d", &k );
		v.resize ( k );
		for ( auto& i : v ) scanf ( "%d", &i );
		for ( auto& i : v ) --i;
		for ( int x = 0 ; x < k ; ++x )
			for ( int y = x + 1 ; y < k ; ++y ) {
				vvb[v[x]][v[y]] = vvb[v[y]][v[x]] = true;
			}
	}
	for ( int i = 0 ; i < n ; ++i )
		for ( int j = 0 ; j < n ; ++j )
			if ( i != j && !vvb[i][j] ) {
				printf ( "No" );
				return;
			}
	printf ( "Yes" );
}

int main ( void )
{
	int _t = 1;
//	scanf ( "%d" , &_t );
	for ( int i = 0 ; i < _t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ( i+1 );
	}


	return 0;
}

