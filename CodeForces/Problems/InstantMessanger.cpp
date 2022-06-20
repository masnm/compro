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

char read_string ()
{
	static char ch[15];
	scanf ( "%s", ch );
	return char ( ch[0] );
}

const int sq = 275;
const int nax = 5e4 + 5;
vector<int> g[nax], memo(nax), degree(nax);
vector<bool> heavy(nax), online(nax);
int n, m, q, o, t, l, r, sum;

void update_online ()
{
	scanf ( "%d", &o );
	for ( int i = 0 ; i < o ; ++i ) {
		scanf ( "%d", &t );
		online[t] = true;
	}
}

void update_graph ()
{
	for ( int i = 0 ; i < m ; ++i ) {
		scanf ( "%d%d", &l, &r );
		g[l].eb(r); g[r].eb(l);
		degree[l]++; degree[r]++;
	}
}

void initial_heavy ()
{
	for ( int i = 0 ; i <= n ; ++i ) {
		if ( degree[i] > sq ) {
			heavy[i] = true;
			memo[i] = 0;
			for ( auto x : g[i] )
				if ( online[x] ) memo[i]++;
		}
	}
}

void handle_querry ()
{
	while ( q-- ) {
		char op = read_string ();
		switch ( op ) {
			case 'O':
				scanf ( "%d", &t ); online[t] = true;
				for ( auto i : g[t] ) if ( heavy[i] ) memo[i]++;
				break;
			case 'F':
				scanf ( "%d", &t ); online[t] = false;
				for ( auto i : g[t] ) if ( heavy[i] ) memo[i]--;
				break;
			case 'A':
				scanf ( "%d%d", &l, &r );
				g[l].eb(r); g[r].eb(l);
				degree[l]++; degree[r]++;
				if ( !heavy[l] && degree[l] > sq ) {
					heavy[l] = true; memo[l] = 0;
					for ( auto i : g[l] ) if ( online[i] ) ++memo[l];
				}
				if ( !heavy[r] && degree[r] > sq ) {
					heavy[r] = true; memo[r] = 0;
					for ( auto i : g[r] ) if ( online[i] ) ++memo[r];
				}
				break;
			case 'D':
				scanf ( "%d%d", &l, &r );
				for ( auto i = g[l].begin() ; i != g[l].end() ; ++i ) {
					if ( *i == r ) {
						g[l].erase ( i );
						break;
					}
				}
				for ( auto i = g[r].begin() ; i != g[r].end() ; ++i ) {
					if ( *i == l ) {
						g[r].erase ( i );
						break;
					}
				}
				degree[l]--; degree[r]--;
				if ( degree[l] < sq ) heavy[l] = false;
				if ( degree[r] < sq ) heavy[r] = false;
				break;
			case 'C':
				scanf ( "%d", &t );
				if ( heavy[t] ) printf ( "%d\n", memo[t] );
				else {
					sum = 0;
					for ( auto i : g[t] ) if ( online[i] ) ++sum;
					printf ( "%d\n", sum );
				}
				break;
			default:
				assert(false); break;
		}
	}
}

void solve ()
{
	for_each ( memo.begin(), memo.end(), [](auto& i) { i = 0; } );
	for_each ( heavy.begin(), heavy.end(), [](auto && i) { i = false; } );
	for_each ( online.begin(), online.end(), [](auto && i) { i = false; } );
	for_each ( degree.begin(), degree.end(), [](auto & i) { i = 0; } );
	for ( int i = 0 ; i < nax ; ++i ) g[i].clear();
	scanf ( "%d%d%d", &n, &m, &q );
	update_online ();
	update_graph ();
	initial_heavy ();
	handle_querry ();
}

int main ()
{
	int tt = 1;
//	scanf ( "%d" , &tt );
	for ( int i = 0 ; i < tt ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

