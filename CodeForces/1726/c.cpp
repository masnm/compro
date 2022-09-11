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

const int nax = 200005;
int tree[1<<20];
int td;
int n;
string s;
vector<int> v, inc[nax];
vector<pair<int,int>> sel;
int parent[nax], _size[nax];

void make_set ( int _v )
{
	parent[_v] = _v;
	_size[_v] = 1;
}

int find_set ( int _v )
{
	if (_v == parent[_v]) return _v;
	return parent[_v] = find_set(parent[_v]);
}

void union_sets ( int a, int b )
{
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (_size[a] < _size[b])
			swap(a, b);
		parent[b] = a;
		_size[a] += _size[b];
	}
}

int get_min ( int l, int r )
{
	l += td; r += td + 1;
	int ret = INT_MAX;
	while ( l < r ) {
		if ( l & 1 ) ret = min ( ret, tree[l++] );
		if ( r & 1 ) ret = min ( ret, tree[--r] );
		l >>= 1;
		r >>= 1;
	}
	assert ( ret != INT_MAX );
	return ret;
}

inline void solve ( int _case )
{
	(void) _case;
	scanf ( "%d", &n ); n *= 2;
	sel.clear();
	v.resize ( n );
	for ( int i = 0 ; i <= n ; ++i ) inc[i].clear();
	s = read_string();
	int bl = 0;
	for ( int i = 0 ; i < n ; ++i ) {
		if ( s[i] == '(' ) ++bl;
		else --bl;
		v[i] = bl;
	}
	td = 1; while ( td < n ) td <<= 1;
	for ( int i = 0 ; i < td*2 ; ++i ) tree[i] = 0;
	for ( int i = 0 ; i < n ; ++i ) tree[td+i] = v[i];
	for ( int i = td-1 ; i > -1 ; --i ) tree[i] = min ( tree[i*2], tree[i*2+1] );
	bl = 0;
	for ( int i = 0 ; i < n ; ++i ) {
		if ( s[i] == '(' ) {
			++bl;
			inc[bl].eb(i);
		} else { // s[i] == ')'
			--bl;
			sel.eb ( bl, i );
		}
	}
	for ( int i = 0 ; i <= n ; ++i ) make_set ( i );
	for ( auto i : sel ) {
		for ( auto val : inc[i.F+1] ) {
			if ( val <= i.S && get_min ( val, i.S ) - (v[val] - 1) >= 0 ) {
				union_sets ( val, i.S );
			}
		}
	}
	set<int> st;
	for ( int i = 0 ; i < n ; ++i ) st.insert ( find_set(i) );
	printf ( "%d\n", int(st.size()) );
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

