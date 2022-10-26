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
	node () = default ;
	node ( int* _cnt ) {
		for ( int i = 0 ; i < 27 ; ++i )
			cnt[i] = _cnt[i];
	}
	int cnt[27];
	void clear () {
		for ( int i = 0 ; i < 27 ; ++i )
			cnt[i] = 0;
	}
};

const int nax = 1<<19;
int th;
node tree[nax];

void combine ( int l )
{
	for ( int i = 0 ; i < 27 ; ++i )
		tree[l].cnt[i] = tree[l*2].cnt[i] + tree[l*2+1].cnt[i];
}

void tree_up ( int l, char ch )
{
	l = l - 1 + th;
	tree[l].clear();
	tree[l].cnt[int(ch-'a')] = 1;
	for ( int i = l>>1 ; i > 0 ; i >>= 1 )
		combine ( i );
}

int tree_get ( int l, int r, int ch )
{
	l = l - 1 + th;
	r = r + th;
	int ret = 0;
	for (  ; l < r ; l >>= 1, r >>= 1 ) {
		if ( l & 1 ) ret += tree[l++].cnt[int(ch-'a')];
		if ( r & 1 ) ret += tree[--r].cnt[int(ch-'a')];
	}
	return ret;
}

int n, q, op, l, r;
char ch;
string s;

int main ( void )
{
	scanf ( "%d%d", &n, &q );
	s = read_string ();
	th = 1;
	while ( th <= n ) th <<= 1;
	for ( int i = 0 ; i < n ; ++i )
		tree[th+i].cnt[int(s[i]-'a')]++;
	for ( int i = th-1 ; i > 0 ; --i ) combine ( i );
	while ( q-- ) {
		scanf ( "%d%d", &op, &l );
		switch ( op ) {
			case 1:
				scanf ( " %c", &ch );
				tree_up ( l, ch );
				break;
			case 2:
				scanf ( "%d %c", &r, &ch );
				printf ( "%d\n", tree_get ( l, r, ch ) );
				break;
			default:
				assert ( false );
				break;
		}
	}

	return 0;
}

