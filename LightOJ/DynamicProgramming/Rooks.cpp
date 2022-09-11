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

const int nax = 33;
int n, k;
vector<bool> row(nax), col(nax);

int get_ans ( int cnt )
{
	if ( cnt >= k ) return 1;
	int ans = 0;
	for ( int i = 0 ; i < n ; ++i )
		for ( int j = 0 ; j < n ; ++j )
			if ( !row[i] && !col[j] ) {
				row[i] = col[j] = true;
				ans += get_ans ( cnt+1 );
				row[i] = col[j] = false;
			}
	return ans;
}

void solve2 ()
{
	for ( int i = 0 ; i < n ; ++i ) row[i] = false;
	for ( int i = 0 ; i < n ; ++i ) col[i] = false;
	scanf ( "%d%d", &n, &k );
	if ( k > n ) { puts ( "0" ); return; }
	printf ( "%d\n", get_ans ( 0 ) );
}

void solve3 ()
{
	scanf ( "%d%d", &n, &k );
	if ( k > n ) { puts ( "0" ); return; }
	int ans = 0;
	for ( int i = 0 ; i < (1<<n) ; ++i ) {
		if ( __builtin_popcount(i) != k ) continue;
		for ( int j = 0 ; j < (1<<n) ; ++j ) {
			if ( __builtin_popcount(j) != k ) continue;
			ans += k;
		}
	}
	printf ( "%d\n", ans );
}

int aans ( int nrow, int ncol, int cnt )
{
	if ( cnt >= k ) return 1;
	int ans = 0;
	for ( int i = 0 ; i < n ; ++i ) {
		for ( int j = 0 ; j < n ; ++j ) {
			if ( !row[i] && !col[j] ) {
				row[i] = col[j] = true;
				ans += aans ( i+1, j+1, cnt+1 );
				row[i] = col[j] = false;
			}
		}
	}
	return ans;
}

void solve ()
{
	scanf ( "%d%d", &n, &k );
	if ( k > n ) { puts ( "0" ); return; }
	printf ( "%d\n", aans ( 0, 0, 0 ) );
}

int main ( int argc, char* argv[] )
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

