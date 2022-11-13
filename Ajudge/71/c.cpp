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
	tpl () = default;
	tpl ( int _l, int _r, int _ind, int _ans )
		: l(_l), r(_r), ind(_ind), ans(_ans) {}
	int l = 0, r = 0, ind = 0, ans = 0;
};

const int nax = 1e5 + 5;
const int mth = 1<<19;
int tree[mth], th;
int n, q;
vector<int> v, nxt, pn;
vector<tpl> vt;
vector<bool> is_val;

void tree_build ()
{
	th = 1; while ( th <= n ) th <<= 1;
	for ( int i = 1 ; i < 2*th ; ++i )
		tree[i] = 0;
}

int tree_get ( int l, int r )
{
	l += th; r += th + 1;
	int ret = 0;
	for ( ; l < r ; l >>= 1, r >>= 1 ) {
		if ( l&1 ) ret += tree[l++];
		if ( r&1 ) ret += tree[--r];
	}
	return ret;
}

void tree_set ( int ind, int val )
{
	ind += th;
	tree[ind] = val;
	for ( ind >>= 1 ; ind > 0 ; ind >>= 1 )
		tree[ind] = tree[2*ind] + tree[2*ind+1];
}

inline void solve ( int _case )
{
	scanf ( "%d%d", &n, &q );
	v.resize ( n );
	for ( auto& i : v ) scanf ( "%d", &i );
	nxt.resize ( n );
	fill ( nxt.begin(), nxt.end(), -1 );
	pn.resize ( nax );
	fill ( pn.begin(), pn.end(), -1 );
	for ( int i = n - 1 ; i > -1 ; --i ) {
		nxt[i] = pn [ v[i] ];
		pn [ v[i] ] = i;
	}
	tree_build ();
	sort ( v.begin(), v.end() );
	v.resize ( unique ( v.begin(), v.end() ) - v.begin() );
	is_val.resize ( n );
	fill ( is_val.begin(), is_val.end(), false );
	for ( auto& i : v ) {
		tree_set ( pn[i], 1 );
		is_val[pn[i]] = true;
	}
	vt.resize ( q );
	for ( int i = 0 ; i < q ; ++i ) {
		scanf ( "%d%d", &vt[i].l, &vt[i].r );
		--vt[i].l; --vt[i].r;
		vt[i].ind = i;
	}
	sort ( vt.begin(), vt.end(), [](auto& l, auto& r) {
			return tie ( l.l, l.r ) < tie ( r.l, r.r );
			} );
	int ind = 0, qi = 0;
	while ( true ) {
		if ( ind >= n ) break;
		if ( qi >= q ) break;
		for ( int i = ind ; i < vt[qi].l ; ++i ) {
			if ( is_val[i] ) {
				is_val[i] = false;
				tree_set ( i, 0 );
				if ( nxt[i] != -1 ) {
					tree_set ( nxt[i], 1 );
					is_val [ nxt[i] ] = true;
				}
			}
		}
		ind = vt[qi].l;
		vt[qi].ans = tree_get ( vt[qi].l, vt[qi].r );
		++qi;
	}
	sort ( vt.begin(), vt.end(), [](auto& l, auto& r) {
			return l.ind < r.ind;
			} );
	for ( auto& i : vt )
		printf ( "%d\n", i.ans );
}

int main ( void )
{
	int _t = 1;
	scanf ( "%d" , &_t );
	for ( int i = 0 ; i < _t ; ++i ) {
		printf ( "Case %d:\n", i+1 );
		solve ( i+1 );
	}


	return 0;
}

