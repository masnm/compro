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
int tree[nax], th;
int n, x, q, cmn;
string s;
vector<int> v;

int get_sum ( int l, int r )
{
	l += th; r += th + 1;
	int ret = 0;
	while ( l < r ) {
		if ( l&1 ) ret += tree[l++];
		if ( r&1 ) ret += tree[--r];
		l >>= 1; r >>= 1;
	}
	return ret;
}

inline void solve ( int _case )
{
	scanf ( "%d%d", &n, &q );
	v.resize ( n );
	for ( auto& i : v ) scanf ( "%d", &i );
	cmn = n + q;
	th = 1; while ( th <= cmn ) th <<= 1;
	for ( int i = 0 ; i < 2*th ; ++i ) tree[i] = 0;
	for ( int i = 0 ; i < n ; ++i ) tree[th+i] = 1;
	for ( int i = th - 1 ; i > 0 ; --i ) tree[i] = tree[i*2] + tree[i*2+1];
	while ( q-- ) {
		s = read_string ();
		if ( s == "c" ) {
			int t; scanf ( "%d", &t );
			int low = 0, high = n-1, mid;
			while ( low < high ) {
				mid = low + (high-low)/2;
				int val = get_sum ( 0, mid );
				if ( val < t ) low = mid + 1;
				else high = mid;
			}
			if ( get_sum ( 0, low ) == t ) {
				printf ( "%d\n", v[low] );
				int ind = low + th;
				tree[ind] = 0;
				for ( ind >>= 1 ; ind > 0 ; ind >>= 1 )
					tree[ind] = tree[ind*2] + tree[ind*2+1];
			} else {
				puts ( "none" );
			}
		} else if ( s == "a" ) {
			int t; scanf ( "%d", &t );
			v.eb ( t ); ++n;
			int ind = n - 1 + th;
			tree[ind] = 1;
			for ( ind >>= 1 ; ind > 0 ; ind >>= 1 )
				tree[ind] = tree[ind*2] + tree[ind*2+1];
		} else assert ( false );
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

