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

vector<int> c, s, f, q;

void solve ()
{
	q.clear();
	int n; scanf ( "%d", &n );
	s.resize ( n ); f.resize ( n ); c.resize ( n );
	for ( auto& i : s ) scanf ( "%d", &i );
	for ( auto& i : f ) scanf ( "%d", &i );
	int ct = 0, si = 0, qi = 0, ind;
	while ( true ) {
		while ( si < n && s[si] <= ct ) q.eb(si++);
		if ( qi >= int(q.size()) && si >= n ) break;
		if ( qi >= int(q.size()) ) { ct = max ( ct, s[si] ); continue; }
		ind = q[qi++];
		c[ind] = ct;
		ct = f[ind];
	}
	for ( int i = 0 ; i < n ; ++i ) {
		printf ( "%d ", f[i] - c[i] );
	}
	puts ( "" );
}

int main ()
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

