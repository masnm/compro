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
	int n; scanf ( "%d", &n );
	vector<int> ans;
	int t;
	for ( int i = 0 ; i < ((2*n)-1) ; ++i ) {
		if ( ans.empty() ) { scanf ( "%d", &t ); ans.eb(t); continue; }
		int ns = ( i >= n ? n - (i-n + 1) : i+1 );
		vector<int> nxt ( ns ), nans ( ns, 0 );
		for ( int& j : nxt ) scanf ( "%d", &j );
		if ( int(ans.size()) < ns ) {
			for ( int _i = 0 ; _i < int(ans.size()) ; ++_i ) {
				nans[_i] = max ( nans[_i], ans[_i] + nxt[_i] );
				nans[_i+1] = max ( nans[_i+1], ans[_i] + nxt[_i+1] );
			}
		} else {
			for ( int _i = 0 ; _i < int(ans.size()) ; ++_i ) {
				if ( _i < ns ) nans[_i] = max ( nans[_i], ans[_i] + nxt[_i] );
				if ( _i > 0 ) nans[_i-1] = max ( nans[_i-1], ans[_i] + nxt[_i-1] );
			}
		}
		ans = nans;
	}
	assert ( ans.size() == 1 );
	printf ( "%d\n", *ans.begin() );
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

