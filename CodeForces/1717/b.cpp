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

string read_string ()
{
	static char ch[1000005];
	scanf ( "%s", ch );
	return string ( ch );
}

using ll = long long int;

const int nax = 505;
bool g[nax][nax];
int n, k, r, c;

void solve ()
{
	scanf ( "%d%d%d%d", &n, &k, &r, &c );
	--r; --c;
	for ( int i = 0 ; i < n ; ++i )
		for ( int j = 0 ; j < n ; ++j )
			g[i][j] = false;
	int cnt = 0;
	int sc = -1;
	for ( int i = 0 ; i < n ; ++i ) {
		cnt = i % k;
		for ( int j = 0 ; j < n ; ++j ) {
			if ( cnt == 0 ) g[i][j] = true;
			++cnt;
			cnt %= k;
			if ( g[i][j] && j==c ) sc = i;
		}
	}
	assert ( sc != -1 );
	debug() << imie(sc);
	sc -= r;
	if ( sc < 0 ) sc += n;
	assert ( sc >= 0 && sc < n );
	debug() << imie(sc);
	for ( int i = 0 ; i < n ; ++i ) {
		for ( int j = 0 ; j < n ; ++j )
			printf ( g[sc][j] ? "X" : "." );
		puts ( "" );
		++sc; sc %= n;
	}
}

int main ( int argc, char* argv[] )
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

