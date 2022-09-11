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

struct tpl {
	tpl () = default;
	tpl ( int _r, int _g, int _b ) : ar { _r, _g, _b } {}
	int ar[3] = { 0, 0, 0 };
};
debug & operator << (debug & dd, tpl p) { dd << "(" << p.ar[0] << ", " << p.ar[1] << ", " << p.ar[2] << ")\n"; return dd; }

int n;
vector<tpl> v;
vector<tpl> dp;

void solve ()
{
	scanf ( "%d", &n );
	v.resize ( n );
	for ( auto& i : v )
		for ( int j = 0 ; j < 3 ; ++j )
			scanf ( "%d", &i.ar[j] );
	dp.resize ( n );
	const int inf = 1e9 + 5;
	for ( int i = 0 ; i < n ; ++i ) {
		dp[i] = tpl ( inf, inf, inf );
	}
	dp[0] = v[0];
	for ( int itr = 0 ; itr < n - 1 ; itr++ ) {
		for ( int i = 0 ; i < 3 ; ++i ) {
			for ( int j = 0 ; j < 3 ; ++j ) {
				if ( i == j ) continue;
				dp[itr+1].ar[j] = min ( dp[itr+1].ar[j], dp[itr].ar[i] + v[itr+1].ar[j] );
			}
		}
	}
	int mn = inf;
	for ( int i = 0 ; i < 3 ; ++i ) {
		mn = min ( mn, dp[n-1].ar[i] );
	}
	printf ( "%d\n", mn );
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

