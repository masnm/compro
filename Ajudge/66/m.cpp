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

struct node {
	node () = default;
	node ( int _fm, int _sm ) : fm(_fm), sm(_sm) {}
	int fm = 0;
	int sm = 0;
};

node none;
const int nax = 1<<19;
node tree[nax];
int th, n, t, q, x, y;
string op;

node get_max ( node& l, node& r )
{
	node no = l;
	int nxt = r.fm;
	for ( int i = 0 ; i < 2 ; ++i ) {
		if ( nxt > no.fm ) {
			if ( no.fm > no.sm ) {
				no.sm = no.fm;
				no.fm = nxt;
			} else {
				no.fm = nxt;
			}
		} else if ( nxt > no.sm ) {
			no.sm = nxt;
		}
		nxt = r.sm;
	}
	return no;
}

void input_build ( void )
{
	for ( int i = 0 ; i < n ; ++i ) {
		scanf ( "%d", &tree[i+th].fm );
		tree[i+th].sm = -1;
	}
	for ( int i = th - 1 ; i > 0 ; --i ) {
		tree[i] = get_max ( tree[2*i], tree[2*i+1] );
	}
}

void update ()
{
	int ind = th + x - 1;
	tree[ind].fm = y;
	for ( int i = ind>>1 ; i > 0 ; i>>=1 ) {
		tree[i] = get_max ( tree[i*2], tree[i*2+1] );
	}
}

void querry ()
{
	--x; x += th; y += th;
	node ans;
	for (  ; x < y ; x>>=1, y>>=1 ) {
		if ( x&1 ) ans = get_max ( ans, tree[x++] );
		if ( y&1 ) ans = get_max ( ans, tree[--y] );
	}
	printf ( "%d\n", ans.fm + ans.sm );
}

int main ( void )
{
	scanf ( "%d", &n );
	th = 1;
	while ( th <= n ) th <<= 1;
	for ( int i = 0 ; i < th+1 ; ++i ) tree[i] = none;
	input_build ();
	scanf ( "%d", &q );
	while ( q-- ) {
		op = read_string();
		if ( op == "U" ) {
			scanf ( "%d%d", &x, &y );
			update ();
		} else if ( op == "Q" ) {
			scanf ( "%d%d", &x, &y );
			querry ();
		} else {
			assert ( false );
		}
	}

	return 0;
}

