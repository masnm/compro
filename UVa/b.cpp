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

const int nax = 50010;
vector<int> mg(nax), pig[nax];
int n, m, s, t;

void clr ()
{
	for ( int i = 0 ; i < n+5 ; ++i ) mg[i] = i;
	for ( int i = 0 ; i < n+5 ; ++i ) pig[i].clear(), pig[i].eb(i);
}

void merge ()
{
	int gs = mg[s], gt = mg[t];
	if ( gs == gt ) return;
	if ( pig[gs] < pig[gt] ) swap ( gs, gt );
	for ( int& i : pig[gt] ) {
		pig[gs].eb(i);
		mg[i] = gs;
	}
	pig[gt].clear();
}

int main ()
{
	int cas = 0;
	while ( scanf ( "%d%d", &n, &m ) != EOF ) {
		if ( n == m && n == 0 ) break;
		clr();
		printf ( "Case %d: ", ++cas );
		for ( int i = 0 ; i < m ; ++i ) {
			scanf ( "%d%d", &s, &t );
			merge ();
		}
		int ans = 0;
		for ( int i = 0 ; i < n ; ++i ) {
			debug() << imie(pig[i]);
			ans += (pig[i].size()>0?1:0);
		}
		printf ( "%d\n", ans );
	}

	return 0;
}

