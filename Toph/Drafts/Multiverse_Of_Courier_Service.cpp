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

const int nax = 1000005;
vector<int> p, g[nax];
vector<bool> v(nax);
int mn, n;

void bfs ( int me )
{
	v[me] = true;
	for ( auto i : g[me] ) {
		if ( !v[i] ) {
			bfs ( i );
		}
	}
	mn = min ( mn, p[(me>=n?me-n:me)] );
}

int main ( int argc, char* argv[] )
{
	scanf ( "%d", &n );
	vector<pair<int,int>> va ( n ), vb ( n );
	for ( int i = 0 ; i < n ; ++i ) {
		va[i].second = i;
		scanf ( "%d", &va[i].first );
	}
	for ( int i = 0 ; i < n ; ++i ) {
		vb[i].second = i + n;
		scanf ( "%d", &vb[i].first );
	}
	p.resize ( n );
	for ( auto& i : p ) scanf ( "%d", &i );
	sort ( va.begin(), va.end() );
	sort ( vb.begin(), vb.end() );

	for ( int i = 0 ; i < n ; ++i ) {
		g[va[i].second].eb(vb[i].second);
		g[vb[i].second].eb(va[i].second);
	}
	// va.clear(); va.shrink_to_fit();
	// vb.clear(); vb.shrink_to_fit();

	for ( int i = 0 ; i < n ; ++i ) {
		g[i].eb ( i+n );
		g[i+n].eb(i);
	}

	vector<int> ans;
	int n2 = 2*n;
	for ( int i = 0 ; i < n2 ; ++i ) {
		if ( !v[i] ) {
			mn = p[(i>=n?i-n:i)];
			bfs ( i );
			ans.eb ( mn );
		}
	}
	sort ( ans.begin(), ans.end() );
	// debug() << imie(ans);
	ll fans = accumulate ( ans.begin(), ans.end(), 0LL );
	fans -= ans[0];
	fans += ( ll(ans[0]) * ll(ans.size()-1) );
	printf ( "%lld\n", fans );

	return 0;
}

