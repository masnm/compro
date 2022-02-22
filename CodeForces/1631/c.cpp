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

constexpr const int nax = 1<<16;
vector<pair<int,int>> vp ( nax );
pair<int,int> nd;
int n, k;

void zero ()
{
	int l = 0, r = n - 1;
	while ( l < r )
		printf ( "%d %d\n", l++, r-- );
}

void nmo ()
{
	if ( n == 4 ) { puts("-1"); return; }
	--k;
	int l = 0, r = n - 1, ind = 0;
	while ( l < r ) {
		if ( l == k || r == k )
			nd = make_pair ( l++, r-- );
		else
			vp[ind++] = make_pair ( l++, r-- );
	}
	if ( nd.F == k )
		swap ( vp[0].S, nd.S );
	else
		swap ( vp[0].S, nd.F );
	vp[ind++] = nd;
	swap ( vp[0].S, vp[2].S );
	for ( int i = 0 ; i < ind ; ++i )
		printf ( "%d %d\n", vp[i].F, vp[i].S );
}

void solve ()
{
	scanf ( "%d%d", &n, &k );
	if ( k == n-1 ) { return nmo(); }
	if ( k == 0 ) { return zero(); }
	int l = 0, r = n - 1, ind = 0;
	while ( l < r ) {
		if ( l == k || r == k )
			nd = make_pair ( l++, r-- );
		else
			vp[ind++] = make_pair ( l++, r-- );
	}
	if ( nd.F == k )
		swap ( vp[0].S, nd.S );
	else
		swap ( vp[0].S, nd.F );
	vp[ind++] = nd;
	for ( int i = 0 ; i < ind ; ++i )
		printf ( "%d %d\n", vp[i].F, vp[i].S );
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

