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

struct st {
	int me, dis, pos;
	bool operator< ( st& r ) const {
		if ( dis == r.dis ) return pos < r.pos;
		else return dis < r.dis;
	}
};
debug & operator << (debug & dd, st p) { dd << "(" << p.me << ", " << p.dis << ", " << p.pos << ")"; return dd; }

const int nax = 1e5 + 5;
int n, k;
st ar[nax];

int get ( st& l, st& r )
{
	ll ret = l.pos * r.pos;
	ret -= ( k * (l.me|r.me) );
	return ret;
}

void solve ()
{
	scanf ( "%d%d", &n, &k );
	for ( int i = 0 ; i < n ; ++i ) {
		scanf ( "%d", &ar[i].me );
		ar[i].pos = i + 1;
		ar[i].dis = ar[i].pos - ar[i].me;
	}
	sort ( ar, ar+n );
	for ( int i = 0 ; i < n ; ++i )
		debug() << imie(ar[i]);
	printf ( "%d\n", get(ar[n-1], ar[n-2]) );
	debug();
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
