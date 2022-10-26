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

string read_string ( void )
{
	static char ch[1000005];
	scanf ( "%s", ch );
	return string ( ch );
}

using ll = long long int;

struct tpl {
	int l = 0, r = 0, ind = -1;
	tpl () = default;
	tpl ( int _l, int _r, int _ind )
		: l(_l), r(_r), ind(_ind) {}
};
const int nax = 1e5 + 5;
const int mth = 1<<19;
int tree[mth], th;
int n, q;
vector<int> inds[nax], v, ind ( nax ), ol;
vector<tpl> vt;

inline void solve ( int _case )
{
	for ( int i = 0 ; i < n ; ++i ) inds[i].clear();
	scanf ( "%d%d", &n, &q );
	v.resize ( n );
	for ( int i = 0 ; i < n ; ++i ) {
		scanf ( "%d", &v[i] );
		inds[v[i]].eb ( i );
	}
	ol.clear();
	vt.resize ( q );
	for ( auto& i : vt ) scanf ( "%d%d", &i.F, i.S );
	sort ( vt.begin(), vt.end(), [](auto& l, auto& r) {
			return tie(l.l, l.r)<tie(r.l,r.r);
			});
	th = 1; while ( th <= n ) th <<= 1;
	for ( int i = 0 ; i < 2*th ; ++i ) tree[i] = 0;
	for ( int i = 0 ; i < nax ; ++i )
		if ( !inds[i].empty() ) {
			ind[i] = 0;
			int ta = inds[0] + th;
			tree[ta] = 1;
			for ( ta >>= 1 ; ta > 0 ; ta >>= 1 )
				tree[ta] = tree[ta*2] + tree[ta*2+1];
		}
	for ( int i = 0 ; i < vt[0].l ; ++i )
		if ( tree[i+th] == 1 )
			ol.eb ( v[i] );
	for ( auto& item : vt ) {
		for ( auto& i : ol ) {
			while ( ind[i] < inds[i].size && inds[i][ind[i]] <= 
		}
	}
}

int main ( void )
{
	int _t = 1;
	scanf ( "%d" , &_t );
	for ( int i = 0 ; i < _t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ( i+1 );
	}


	return 0;
}

