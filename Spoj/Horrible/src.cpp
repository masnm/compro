#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
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

struct st {
	ll val; // normally some with update pending or not
	bool pu; // true means update pending
	ll pval; // value to add below
	st ( ll _val, bool _pu, ll _pval )
		: val(_val), pu(_pu), pval(_pval)
	{}
};

ll update ( vector<st>& tree, int me, int ms, int mf, int qs, int qf, ll val )
{
	if ( ms > qf || mf < qs ) return 0LL;
	if ( ms >= qs && mf <= qf ) {
		int rng = mf - ms + 1;
		if ( rng == 1 ) {
			tree[me].val += val;
		} else {
			tree[me].val += ( val * rng );
			tree[me].pu = true;
			tree[me].pval += val;
		}
		return ( val * rng );
	}
	int mid = ( ms + mf ) / 2;
	ll lrtn = update ( tree, 2*me, ms, mid, qs, qf, val );
	ll rrtn = update ( tree, 2*me+1, mid+1, mf, qs, qf, val );
	tree[me].val += ( lrtn + rrtn );
	return (lrtn + rrtn);
}

void take_care ( vector<st>& tree, int me, int ms, int mf, ll val )
{
	if ( ms == mf ) {
		tree[me].val += val;
	} else {
		int rng = mf - ms + 1;
		assert ( rng != 1 );
		tree[me].val += ( val * rng );
		tree[me].pu = true;
		tree[me].pval += val;
	}
}

ll sum ( vector<st>& tree, int me, int ms, int mf, int qs, int qf )
{
	if ( ms > qf || mf < qs ) return 0LL;
	if ( ms >= qs && mf <= qf ) {
		return tree[me].val;
	}
	int mid = ( ms + mf ) / 2;
	if ( tree[me].pu ) {
		tree[me].pu = false;
		take_care ( tree, 2*me, ms, mid, tree[me].pval );
		take_care ( tree, 2*me+1, mid+1, mf, tree[me].pval );
		tree[me].pval = 0;
	}
	return sum ( tree, 2*me, ms, mid, qs, qf ) + sum ( tree, 2*me+1, mid+1, mf, qs, qf );
}

void solve ()
{
	int n, c;
	scanf ( "%d%d", &n, &c );
	int nn = __builtin_popcount(n) == 1 ? n : ( 1 << ( 32 - __builtin_clz(n) ) );
	vector<st> tree ( 2 * nn, {0, false, 0} );
	int choice, p, q;
	ll v;
	for ( int cc = 0 ; cc < c ; ++cc ) {
		scanf ( "%d", &choice );
		if ( choice == 0 ) {
			scanf ( "%d%d%lld", &p, &q, &v );
			update ( tree, 1, 0, nn-1, p-1, q-1, v );
		} else {
			assert ( choice == 1 );
			scanf ( "%d%d", &p, &q );
			printf ( "%lld\n", sum ( tree, 1, 0, nn-1, p-1, q-1 ) );
			// debug start
			// for ( int i = 1 ; i < 2 * nn ; i += i ) {
			// 	for ( int j = i ; j < i + i ; ++j ) {
			// 		printf ( "%d{ %lld %d %lld } ", j, tree[j].val, tree[j].pu, tree[j].pval );
			// 	}
			// 	printf ( "\n" );
			// }
			// debug end
		}
	}
}

int main ( int argc, char** argv )
{
	int t;
	scanf ( "%d", &t );
	while ( t-- ) solve();

	puts("");
	return 0;
}
