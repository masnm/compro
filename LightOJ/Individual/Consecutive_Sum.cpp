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
	node ( int _one, int _zero ) : one(_one), zero(_zero) {}
	int one = -1;
	int zero = -1;
};

const int max_size = 1000000;
vector<node> tree(max_size);
int mn, mx, n, root = 0, _next = 0, nn, _prev;

void trie_add ( int in )
{
	int nnum, cur = root;
	for ( int i = 30 ; i > -1 ; --i ) {
		nnum = in & (1<<i);
		if ( nnum == 0 ) {
			if ( tree[cur].zero == -1 ) tree[cur].zero = ++_next;
			cur = tree[cur].zero;
		} else {
			if ( tree[cur].one == -1 ) tree[cur].one = ++_next;
			cur = tree[cur].one;
		}
	}
}

int trie_get_max ( int in )
{
	if ( _next < 30 ) return in;
	int nnum, cur = root, ret = 0;
	for ( int i = 30 ; i > -1 ; --i ) {
		nnum = in & (1<<i);
		if ( nnum == 0 ) {
			if ( tree[cur].one != -1 ) {
				ret |= (1<<i);
				cur = tree[cur].one;
			} else {
				cur = tree[cur].zero;
			}
		} else {
			if ( tree[cur].zero != -1 ) {
				cur = tree[cur].zero;
			} else {
				ret |= (1<<i);
				cur = tree[cur].one;
			}
		}
	}
	return ret;
}

int trie_get_min ( int in )
{
	if ( _next < 30 ) return in;
	int nnum, cur = root, ret = 0;
	for ( int i = 30 ; i > -1 ; --i ) {
		nnum = in & (1<<i);
		if ( nnum == 0 ) {
			if ( tree[cur].zero != -1 ) {
				cur = tree[cur].zero;
			} else {
				ret |= (1<<i);
				cur = tree[cur].one;
			}
		} else {
			if ( tree[cur].one != -1 ) {
				ret |= (1<<i);
				cur = tree[cur].one;
			} else {
				cur = tree[cur].zero;
			}
		}
	}
	return ret;
}

inline void solve ( int _case )
{
	(void) _case;
	fill ( tree.begin(), tree.end(), node{-1,-1} );
	root = 0; _next = 0;
	scanf ( "%d", &n );
	_prev = 0;
	// first num;
	scanf ( "%d", &nn );
	trie_add ( nn );
	trie_add ( 0 );
	_prev = nn;
	mn = nn; mx = nn;
	for ( int i = 1 ; i < n ; ++i ) {
		scanf ( "%d", &nn );
		_prev ^= nn;
		debug() << imie(mn) imie(mx);
		mx = max ( mx, _prev ^ trie_get_max ( _prev ) );
		mn = min ( mn, _prev ^ trie_get_min ( _prev ) );
		debug() << imie(mn) imie(mx);
		trie_add ( _prev );
	}
	printf ( "%d %d\n", mx, mn );
}

int main ( void )
{
	int _t = 1;
	scanf ( "%d" , &_t );
	for ( int i = 0 ; i < _t ; ++i ) {
		printf ( "Case %d: ", i+1 );
		solve ( i+1 );
	}


	return 0;
}

