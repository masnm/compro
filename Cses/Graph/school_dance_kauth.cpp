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

const int nax = 505;
vector<int> g[nax];
vector<bool> used ( nax, false );
vector<int> mt ( nax, -1 );
int n, m, e, l, r;

bool try_kauth ( int me )
{
	if ( used[me] ) return false;
	used[me] = true;
	for ( const int& x : g[me] )
		if ( mt[x] == -1 || try_kauth ( mt[x] ) ) {
			mt[x] = me;
			return true;
		}
	return false;
}

int main ()
{
	scanf ( "%d%d%d", &n, &m, &e );
	for ( int i = 0 ; i < e ; ++i ) {
		scanf ( "%d%d", &l, &r );
		--l;  --r;
		g[l].eb(r);
		//g[r].eb(l);
	}

	for ( int i = 0 ; i < n ; ++i ) {
		used.assign ( nax, false );
		try_kauth ( i );
	}
	vector<pair<int,int>> vi;
	for ( int i = 0 ; i < m ; ++i )
		if ( mt[i] != -1 )
			vi.eb(mt[i]+1, i+1);
	printf ( "%d\n", (int)vi.size() );
	for ( const pair<int,int>& i : vi )
		printf ( "%d %d\n", i.F, i.S );

	return 0;
}
