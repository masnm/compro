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
vector<int> v, g[nax], inc[nax];
vector<bool> vis;

void bfs ( int me )
{
	queue<int> q;
	q.push ( me );
	while ( !q.empty() ) {
		int cp = q.front(); q.pop();
		if ( vis[cp] ) continue;
		vis[cp] = true;
		for ( auto i : g[cp] )
			if ( !vis[i] )
				q.push ( i );
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
	v.resize ( n );
	for ( int i = 0 ; i <= n ; ++i ) g[i].clear();
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
	// debug() << imie(v);
	// debug() << imie(1) imie(4) imie(get_min(1,4));
	// debug() << imie(1) imie(1) imie(get_min(1,1));
	bl = 0;
	for ( int i = 0 ; i < n ; ++i ) {
		if ( s[i] == '(' ) {
			++bl;
			inc[bl].eb(i);
		} else { // s[i] == ')'
			--bl;
			for ( auto val : inc[bl+1] ) {
				debug() << imie(get_min ( val, i ) ) imie(v[val] );
				if ( get_min ( val, i ) - (v[val] - 1) >= 0 ) {
					g[val].eb ( i );
					g[i].eb ( val );
				}
			}
		}
	}
	debug() << imie(s);
	for ( int i = 0 ; i < n ; ++i )
		debug() << imie(i) imie(g[i]);
	vis.resize ( n );
	fill ( vis.begin(), vis.end(), false );
	int cnt = 0;
	for ( int i = 0 ; i < n ; ++i ) {
		if ( !vis[i] ) {
			++cnt;
			bfs ( i );
		}
	}
	printf ( "%d\n", cnt );
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

