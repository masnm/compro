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

int n, q, si, ei;
vector<pair<int,int>> vp;
pair<int,int> s, b;

void solve ()
{
	scanf ( "%d%d", &n, &q );
	vp.resize ( n );
	for ( int i = 0 ; i < n ; ++i )
		scanf ( "%d%d", &vp[i].F, &vp[i].S );
	sort ( vp.begin(), vp.end() );
	ll ans = 0;
	while ( q-- ) {
		ans = 0;
		scanf ( "%d%d%d%d", &s.F, &s.S, &b.F, &b.S );
		s.F += 1; s.S += 1;
		auto src = lower_bound ( vp.begin(), vp.end(), s );
		if ( src != vp.end() ) debug() << imie(*src);
		si = src-vp.begin();
		src = lower_bound ( vp.begin(), vp.end(), b );
		if ( src != vp.end() ) debug() << imie(*src);
		ei = src-vp.begin();
		for (  ; si < ei ; ++si )
			ans += vp[si].F * vp[si].S;
		printf ( "%lld\n", ans );
		puts ( "" );
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

