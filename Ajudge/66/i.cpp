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
ll tree[nax], val, gt;
int n, q, th, op, ind;

inline void solve ( int _case )
{
	scanf ( "%d%d", &n, &q );
	th = 1; while ( th <= n ) th <<= 1;
	for ( int i = 0 ; i < 2*th ; ++i ) tree[i] = 0;
	for ( int i = 0 ; i < n ; ++i ) scanf ( "%lld", &tree[i+th] );
	for ( int i = th - 1 ; i > 0 ; --i ) tree[i] = tree[i*2] + tree[i*2+1];
	while ( q-- ) {
		scanf ( "%d%d", &op, &ind );
		ind += th;
		switch ( op ) {
			case 1:
				printf ( "%lld\n", tree[ind] );
				tree[ind] = 0;
				for ( ind >>= 1 ; ind > 0 ; ind >>= 1 )
					tree[ind] = tree[ind*2] + tree[ind*2+1];
				break;
			case 2:
				scanf ( "%lld", &val );
				tree[ind] += val;
				for ( ind >>= 1 ; ind > 0 ; ind >>= 1 )
					tree[ind] = tree[ind*2] + tree[ind*2+1];
				break;
			case 3:
				scanf ( "%lld", &val );
				gt = 0;
				val += th + 1;
				for ( ; ind < val ; ind >>= 1, val >>= 1 ) {
					if ( ind & 1 ) gt += tree[ind++];
					if ( val & 1 ) gt += tree[--val];
				}
				printf ( "%lld\n", gt );
				break;
			default:
				assert ( false );
				break;
		}
	}
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

