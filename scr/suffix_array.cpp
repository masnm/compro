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

int n;
string s, t;
vector<pair<int,int>> vp;
vector<int> vi, nvi;

int main ( void )
{
	s = read_string ();
	n = s.length();
	t = s;
	sort ( t.begin(), t.end() );
	t.resize ( unique ( t.begin(), t.end() ) - t.begin() );
	vp.resize ( n );
	nvi.resize ( n );
	vi.resize ( n );
	for ( int i = 0 ; i < n ; ++i )
		vi[i] = int( lower_bound ( t.begin(), t.end(), s[i] ) - t.begin() );

	for ( int blk = 1 ; blk <= n*2 ; blk *= 2 ) {
		vp.resize ( n );
		for ( int i = 0 ; i < n ; ++i ) {
			vp[i] = { vi[i], (i+blk>=n)?-1:vi[i+blk] };
		}
		sort ( vp.begin(), vp.end() );
		vp.resize ( unique ( vp.begin(), vp.end() ) - vp.begin() );
		for ( int i = 0 ; i < n ; ++i ) {
			nvi[i] = int( lower_bound ( vp.begin(), vp.end(), make_pair( vi[i], (i+blk>=n)?-1:vi[i+blk] ) ) - vp.begin() );
		}
		vi = nvi;
	}
	vp.resize(n);
	for ( int i = 0 ; i < n ; ++i ) vp[i] = { vi[i], i };
	sort ( vp.begin(), vp.end() );
	for ( auto i : vp )
		printf ( "%d\n", i.S );

	return 0;
}

