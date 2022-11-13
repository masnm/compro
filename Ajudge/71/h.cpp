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

const int nax = 1<<19;
bool lt[nax/2];
int tree[nax], th;
int n, m, op, l, r;

void print_tree ()
{
	for ( int i = 1 ; i < 2*th ; ++i ) {
		if ( __builtin_popcount(i) == 1 ) puts ("");
		printf ( "%d,%d ", lt[i], tree[i] );
	}
}

void tree_add ( int ci, int cl, int cr, int ol, int oor )
{
	if ( cr < ol || cl > oor ) return;
	if ( cl >= ol && cr <= oor ) {
		if ( cr - cl == 0 ) {
			tree[ci] ^= 1;
		} else {
			lt[ci] ^= true;
			tree[ci] = cr - cl + 1 - tree[ci*2] - tree[ci*2+1];
		}
	} else {
		int mid = (cl + cr) / 2;
		tree_add ( ci*2, cl, mid, ol, oor );
		tree_add ( ci*2+1, mid+1, cr, ol, oor );
		tree[ci] = tree[ci*2] + tree[ci*2+1];
	}
}

void push ( int ind, int low, int high )
{
	lt[ind] ^= 1;
	int _l = ind*2, _r = ind*2 + 1;
	int mid = (low + high) / 2;
	if ( _l == ind*2 ) {
		tree[_l] ^= true;
		tree[_r] ^= true;
		tree[ind] = tree[ind*2] + tree[ind*2+1];
	} else {
		int totl = mid - low + 1 - tree[_l];
		int totr = high - mid + 1 - tree[_r];
		tree[ind] = totl + totr;
		lt[_l] ^= true;
		lt[_r] ^= true;
	}
}

int tree_get ( int ci, int cl, int cr, int ol, int oor )
{
	if ( cr < ol || cl > oor ) return 0;
	if ( cl >= ol && cr <= oor ) {
		if ( cr - cl == 0 ) {
			return tree[ci];
		} else {
			if ( lt[ci] ) push ( ci, cl, cr );
			return tree[ci];
		}
	} else {
		int ret = 0;
		int mid = (cl + cr) / 2;
		ret += tree_get ( ci*2, cl, mid, ol, oor );
		ret += tree_get ( ci*2+1, mid+1, cr, ol, oor );
		return ret;
	}
}

int main ( void )
{
	scanf ( "%d%d", &n, &m );
	th = 1; while ( th <= n ) th <<= 1;
	for ( int i = 0 ; i < m ; ++i ) {
		scanf ( "%d%d%d", &op, &l, &r );
		--l; --r;
		if ( op == 0 ) {
			tree_add ( 1, 0, th-1, l, r );
			//debug() << imie(tree_get(1,0,th-1,0,th-1));
		} else if ( op == 1 ) {
			printf ( "%d\n", tree_get ( 1, 0, th-1, l, r ) );
		} else assert ( false );
		//print_tree ();
	}


	return 0;
}

