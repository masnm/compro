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
	int n, k;
	scanf ( "%d%d", &n, &k );
	vector<int> v(n), fq(n);
	vector<pair<int,int>> vp;
	for ( int& i : v ) scanf ( "%d", &i );
	for ( int& i : v ) --i;
	for ( int i : v ) ++fq[i];
	for ( int i = 0 ; i < n ; ++i )
		if ( fq[i] != 0 ) vp.eb ( fq[i], i );
	int it = max_element ( vp.begin(), vp.end() ) - vp.begin();
	debug() << imie(vp[it]);
}

int main ()
{
	int _t;
	scanf ( "%d", &_t );
	while ( _t-- ) solve();

	return 0;
}

