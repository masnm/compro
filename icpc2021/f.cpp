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

string read_string ()
{
	static char ch[1000005];
	scanf ( "%s", ch );
	return string ( ch );
}

using ll = long long int;

struct C {
	C() = default;
	C ( int _x, int _y, ll _c ): x(_x), y(_y), c(_c) {}
	int x = 0;
	int y = 0;
	ll c = 0;
};
debug & operator << (debug & dd, C p) { dd << "(" << p.x << ", " << p.y << ", " << p.c << ")"; return dd; }

struct cell {
	cell() = default;
	cell ( bool _v, vector<C> _tun, bool _obs, int _cst ) :
		v(_v), tunnels(_tun), obs(_obs), cst(_cst) {}
	bool v = false;
	vector<C> tunnels;
	bool obs = false;
	ll cst = 0;
};
debug & operator << (debug & dd, cell c) {
	dd << "(" << c.v << ", " << c.tunnels << ", " << c.obs << ", " << c.cst << ")"; return dd; }

const int inf = 1e9 + 5;
const int nax = 50005;
int n, m;
int p, q;
int sx, sy, dx, dy;
int ux, uy, vx, vy;
ll w;
int bx, by;
vector<C> c;
vector<cell> grid[nax];

bool inside ( int _r, int _c )
{
	return ( _r>=0 && _r<n && _c>=0 && _c<m );
}

ll tc;
pair<int,int> cp, cpb;
pair<int,int> otd;
ll sssp ()
{
	priority_queue<pair<ll,pair<int,int> > > pq;
	pq.push ( { 0, { sx, sy } } );
	while ( !pq.empty () ) {
		tc = -1LL * pq.top().F;
		cp = pq.top().S;
		if ( cp.F == dx && cp.S == dy ) return tc;
		pq.pop();
		if ( grid[cp.F][cp.S].v ) continue;
		grid[cp.F][cp.S].v = true;
		for ( auto __c : grid[cp.F][cp.S].tunnels ) {
			otd = make_pair ( __c.x, __c.y );
			if ( grid[otd.F][otd.S].cst > tc + __c.c ) {
				grid[otd.F][otd.S].cst = tc + __c.c;
				pq.push ( { -1LL * grid[otd.F][otd.S].cst, otd } );
			}
		}
		cpb = cp;
		for ( auto __c : c ) {
			cp = cpb;
			while ( true ) {
				cp.F += __c.x; cp.S += __c.y;
				if ( !inside ( cp.F, cp.S ) ) break;
				if ( grid[cp.F][cp.S].obs ) break;
				if ( grid[cp.F][cp.S].cst > tc + __c.c ) {
					grid[cp.F][cp.S].cst = tc + __c.c;
					pq.push ( { -1LL * grid[cp.F][cp.S].cst, cp } );
				}
			}
		}
	}
	return -1LL;
}

void res_clr ( void )
{
	cell ce ( false, {}, false, inf );
	for ( int i = 0 ; i < n ; ++i ) {
		grid[i].resize ( m );
		fill ( grid[i].begin(), grid[i].end(), ce );
	}
}

void read ( void )
{
	scanf ( "%d%d%d%d", &n, &m, &p, &q );
	scanf ( "%d%d%d%d", &sx, &sy, &dx, &dy );
	--sx; --sy; --dx; --dy;
	c.clear();
	for ( int i = -1 ; i < 2 ; ++i )
		for ( int j = -1 ; j < 2 ; ++j ) {
			if ( i == 0 && j == 0 ) continue;
			C _c ( i, j, 0 );
			scanf ( "%lld", &_c.c );
			c.eb ( _c );
		}
	res_clr ();
	for ( int i = 0 ; i < p ; ++i ) {
		scanf ( "%d%d%d%d%lld", &ux, &uy, &vx, &vy, &w );
		--ux; --uy; --vx; --vy;
		grid[ux][uy].tunnels.eb ( vx, vy, w );
	}
	for ( int i = 0 ; i < q ; ++i ) {
		scanf ( "%d%d", &bx, &by );
		--bx; --by;
		grid[bx][by].obs = true;
	}
}

void solve ()
{
	read ();
	printf ( "%lld\n", sssp () );
}

int main ( int argc, char* argv[] )
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

