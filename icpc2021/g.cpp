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

const int nax = 30005;
int n;
ll gt, mx, ans;
ll trhalf, flhalf;
ll trc, flc;
vector<pair<ll,int> > w;
vector<bool> col, vis;
vector<int> g[nax];
int u, v;

void input ()
{
	scanf ( "%d", &n );
	w.resize ( n );
	for ( int i = 0 ; i < n ; ++i ) {
		g[i].clear();
		scanf ( "%lld", &w[i].F );
		w[i].S = i;
	}
	for ( int i = 0 ; i < n - 1 ; ++i ) {
		scanf ( "%d%d", &u, &v );
		--u; --v;
		g[u].eb ( v );
		g[v].eb ( u );
	}
}

pair<int,bool> cp;
void colouring ( int ind )
{
	col.resize ( n );
	fill ( col.begin(), col.end(), false );
	vis.resize ( n );
	fill ( vis.begin(), vis.end(), false );
	queue<pair<int,bool> > q;
	q.push ( { ind, false } );
	vis[ind] = true;
	while ( !q.empty() ) {
		cp = q.front(); q.pop();
		cp.S ^= true ^ false;
		for ( auto i : g[cp.F] )
			if ( !vis[i] ) {
				vis[i] = true;
				q.push ( { i, cp.S } );
				col[i] = cp.S;
			}
	}
}

void cal_halfs ()
{
	trhalf = 0;
	flhalf = 0;
	trc = 0;
	flc = 0;
	for ( auto i : w ) {
		if ( col[i.S] == true ) trhalf += i.F, ++trc;
		else flhalf += i.F, ++flc;
	}
}

ll get ( int ind )
{
	ll nor = (w[ind].F * trc) - trhalf;
	ll abn = (w[ind].F * flc) - flhalf;
	if ( col[ind] == true ) {
		return nor - abn;
	} else {
		return abn - nor;
	}
}

void solve ()
{
	input ();
	colouring ( 0 );
	cal_halfs ();
	mx = LLONG_MIN;
	for ( int i = 0 ; i < n ; ++i ) {
		gt = get ( i );
		if ( gt > mx ) mx = gt, ans = i;
	}
	printf ( "%lld\n", ans + 1 );
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

