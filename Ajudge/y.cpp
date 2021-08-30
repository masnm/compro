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

const int nax = 10005;
const int inf = 1e9 + 5;
vector<pair<int,int>> g[nax];
map<string,int> mp;
int dp[nax];
int n, p, sn, en, c, r;
string s, e;

void clr ()
{
	mp.clear();
	for ( int i = 0 ; i < nax ; ++i ) g[i].clear();
}

string read_string ()
{
	static char ch[15];
	scanf ( "%s", ch );
	return string ( ch );
}

int sssp ()
{
	priority_queue<pair<int,int>> pq;
	dp[sn] = 0;
	pq.push ( { 0, sn } );
	int ti, tc;
	while ( !pq.empty() ) {
		ti = pq.top().S; tc = abs ( pq.top().F ); pq.pop();
		if ( ti == en ) return dp[ti];
		if ( dp[ti] < tc ) continue;
		for ( const pair<int,int>& stp : g[ti] ) {
			if ( dp[stp.F] > dp[ti] + stp.S ) {
				dp[stp.F] = dp[ti] + stp.S;
				pq.push ( { -dp[stp.F], stp.F } );
			}
		}
	}
	assert ( false );
}

void solve ()
{
	clr();
	scanf ( "%d", &n );
	for ( int x = 0 ; x < n ; ++x ) {
		s = read_string();
		mp[s] = x + 1;
		scanf ( "%d", &p );
		for ( int i = 0 ; i < p ; ++i ) {
			scanf ( "%d%d", &en, &c );
			g[x+1].eb( en, c );
		}
	}
	scanf ( "%d", &r );
	while ( r-- ) {
		s = read_string ();
		e = read_string ();
		sn = mp[s];
		en = mp[e];
		for ( int i = 0 ; i < nax ; ++i ) dp[i] = inf;
		printf ( "%d\n", sssp () );
	}
}

int main ()
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

