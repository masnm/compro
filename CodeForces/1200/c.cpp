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

const int nax = 33;
//const int nax = 1e5 + 5;
int ar[nax];

void solve ()
{
	for ( int i = 0 ; i < nax ; ++i ) ar[i] = 0;
	int n, w, t;
	scanf ( "%d%d", &n, &w );
	for ( int i = 0 ; i < n ; ++i ) {
		scanf ( "%d", &t );
		++ar[(int)log2(t)];
	}
	int ans = 1, l, sm;
	while ( true ) {
		l = w;
		sm = 0;
		for ( int i = nax - 1 ; i > -1 ; --i ) {
			if ( ar[i] == 0 ) continue;
			t = ( 1 << i );
			while ( ar[i] > 0 && l >= t ) {
				l -= t;
				--ar[i];
			}
			sm += ar[i];
		}
		if ( sm == 0 ) break;
		++ans;
	}
	printf ( "%d\n", ans );
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

