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
int tree[nax];
int tr, t, n;
vector<int> v, mp;
vector<pair<int,int>> vp;

void tree_add ( int ind )
{
	ind += tr;
	tree[ind] = 1;
	for ( int i = ind>>1 ; i > 0 ; i>>=1 )
		tree[i] = tree[i*2] + tree[(i*2)+1];
}

int tree_get ( int l, int r )
{
	l += tr;
	r += tr;
	int ret = 0;
	while ( l < r ) {
		if ( l&1 ) ret += tree[l++];
		if ( r&1 ) ret += tree[--r];
		l >>= 1; r >>= 1;
	}
	return ret;
}

int main ( void )
{
	scanf ( "%d", &n );
	v.resize ( n );
	for ( auto& i : v ) scanf ( "%d", &i );
	for ( int i = 0 ; i < n ; ++i ) {
		vp.eb ( v[i], i );
	}
	sort ( vp.begin(), vp.end() );
	tr = 1;
	while ( tr <= n ) tr <<= 1;
	mp.resize ( n );
	for ( int rep = 0 ; rep < n ; ++rep ) {
		int nind = int(lower_bound(vp.begin(), vp.end(), make_pair(v[rep],rep)) - vp.begin());
		tree_add ( nind );
		mp[nind] = v[rep];
		scanf ( "%d", &t );
		--t;
		int low = 0, high = n+1, mid, tar = t;
		while ( low < high ) {
			mid = low+(high-low)/2;
			int sm = tree_get ( low, mid + 1 );
			if ( sm > tar ) high = mid;
			else {
				low = mid + 1;
				tar -= sm;
			}
		}
		printf ( "%d\n", mp[low] );
	}

	return 0;
}

