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

const int nax = 1e5 + 5;
vector<pair<int,int>> vp ( nax );
vector<int> g[nax];
int n, l, r, root;

void solve ()
{
	scanf ( "%d", &n );
	for ( int i = 0 ; i < n ; ++i ) {
		scanf ( "%d%d", &l, &r );
		vp[i + 1] = {l, r};
		if ( l != -1 ) {
			g[l].eb (i + 1);
		} else {
			root = i + 1;
		}
	}
	vector<int> ans;
	for ( int i = 1 ; i <= n ; ++i ) {
		if ( i == root ) continue;
		vector<int> clds;
		bool ok = true;
		for ( int j : g[i] )
			if ( vp[j].S == 0 )
				ok = false;
		if ( ok && vp[i].S != 0 ) {
			ans.eb ( i );
			int tp = vp[i].F;
			for ( int j : g[i] ) {
				vp[j].F = tp;
				g[tp].eb ( j );
			}
			g[i].clear();
		}
	}
	if ( ans.empty() ) puts ( "-1" );
	else
		for ( int i : ans ) printf ( "%d ", i );
}

int main ()
{
	int t = 1;
//	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

