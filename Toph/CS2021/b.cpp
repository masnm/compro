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

using ll = long long int;

vector<pair<int,int>> vp ( 4 );

void n () { puts("no"); }
void y () { puts("yes"); }

void solve ()
{
	for ( int i = 0 ; i < 4 ; ++i ) {
		scanf ( "%d%d", &vp[i].first, &vp[i].second );
	}
	debug() << imie(vp) ;
	sort ( vp.begin(), vp.end() );
	swap ( vp[2], vp[3] );
	debug() << imie(vp) ;
	for ( int i = 0 ; i < 4 ; ++i ) {
		for ( int j = i + 1 ; j < 4 ; ++j ) {
			if ( vp[i]==vp[j] ) return n();
		}
	}
	if ( ( ( vp[0].first==vp[1].first ) && ( vp[0].second!=vp[1].second )) &&
		( ( vp[1].second==vp[2].second ) && ( vp[1].first!=vp[2].first ) ) &&
		( ( vp[2].first==vp[3].first ) && ( vp[2].second!=vp[3].second )) &&
		( ( vp[3].second==vp[0].second ) && ( vp[3].first!=vp[0].first ) ) ) {
		return y();
	} else {
		return n();
	}
}

int main ()
{
	int t;
	scanf ( "%d", &t );
	while ( t-- ) solve();


	return 0;
}

