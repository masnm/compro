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
int n, q, _l, _r, msz;
int arr[nax];

struct stree {
	const int inf = 1e9 + 5;
	vector<int> vi;
	int n, sq, st;
	stree ( int* ar, int _n, int& rsz ) {
		n = _n; st = 1; sq = 1;
		while ( st < _n ) st <<= 1, ++sq;
		vi = vector<int> ( st * 2, inf );
		for ( int i = 0 ; i < _n ; ++i ) vi[st+i] = ar[i];
		for ( int i = st - 1 ; i > -1 ; --i ) vi[i] = min ( vi[i*2], vi[i*2+1] );
		rsz = st;
	}
	int get ( int ms, int mf, int me, int l, int r )
	{
		if ( mf < l || ms > r ) return inf;
		if ( ms >= l && mf <= r ) return vi[me];
		int mid = (ms + mf) / 2;
		return min(get(ms, mid, 2*me, l, r), get(mid+1, mf, 2*me+1, l, r));
	}
};

int main ()
{
	scanf ( "%d", &n );
	for ( int i = 0 ; i < n ; ++i ) scanf ( "%d", &arr[i] );
	stree tr ( arr, n, msz );
	scanf ( "%d", &q );
	for ( int i = 0 ; i < q ; ++i ) {
		scanf ( "%d%d", &_l, &_r );
		++_l; ++_r;
		printf ( "%d\n", tr.get(1,msz,1,_l,_r));
	}

	return 0;
}
