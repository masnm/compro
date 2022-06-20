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

using ll = long long int;

const int nax = 210;
int n, m;
vector<int> v, w;
vector<pair<int,int>> g[nax];
vector<bool> is(nax);
vector<int> pre(nax);
vector<int> q;

void update ( int l, int r, int c )
{
	for ( auto& i : g[l] ) {
		if ( i.F == r ) {
			i.S += c;
			break;
		}
	}
}

void solve ()
{
	scanf ( "%d", &n); v.resize ( n );
	for ( auto& i : v ) scanf ( "%d", &i );
	scanf ( "%d", &m ); w.resize ( m );
	for ( auto& i : w ) scanf ( "%d", &i );
	for ( int i = 0 ; i < nax ; ++i ) g[i].clear();
	for ( int i = 0 ; i < n ; ++i ) {
		for ( int j = 0 ; j < m ; ++j ) {
			if ( w[j] % v[i] == 0 ) {
				g[i+1].eb(j+102,1);
				g[j+102].eb(i+1,0);
			}
		}
	}
	for ( int i = 1 ; i <= n ; ++i ) g[0].eb(i,1),g[i].eb(0,0);
	for ( int i = 0 ; i < m ; ++i )
			g[i+102].eb(209,1), g[209].eb(i+102,0);
	// start flow at 0 target 209
	int ans = 0;
	while ( true ) {
		for_each ( is.begin(), is.end(), [](auto && i) { i = false; } );
		for_each ( pre.begin(), pre.end(), [](int &i) { i = -1; } );
		q.clear();
		int par = 0, tar = 209; is[par] = true; q.eb(par);
		bool found = false;
		for ( int i = 0 ; i < int(q.size()) ; ++i ) {
			if ( q[i] == tar ) { found = true; break; }
			for ( auto& x : g[q[i]] ) {
				if ( !is[x.F] && x.S > 0 ) {
					is[x.F] = true;
					q.eb(x.F);
					pre[x.F] = q[i];
				}
			}
		}
		if ( !found ) break;
		int me = 209, up, down;
		while ( me != 0 ) {
			up = pre[me]; down = me; me = pre[me];
			update ( down, up, 1 );
			update ( up, down, -1 );
			// update me and pre[me]
		}
		++ans;
	}
	printf ( "%d\n", ans );
	//for ( int i = 0 ; i < nax ; ++i ) {
	//	for ( auto& j : g[i] ) {
	//		if ( j.S != 0 ) cout << i << " " << j.F << " " << j.S << endl;
	//	}
	//}
}

int main ()
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

