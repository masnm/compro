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

const int shift = 502;
const int nax = 1005;
vector<int> g[nax];
int cost[nax][nax];
vector<bool> v ( nax );
vector<int> pre ( nax );
int n, m, k, l, r;

void clear_cost ()
{
	for ( int i = 0 ; i < nax ; ++i )
		for ( int j = 0 ; j < nax ; ++j )
			cost[i][j] = 0;
}

void prepare ( int source, int sink )
{
	assert ( n < source && n < sink );
	assert ( m < source && m < sink );
	clear_cost ();
	for ( int i = 0 ; i < n ; ++i ) {
		g[source].eb(i);
		cost[source][i] = 1;
		//g[i].eb(source);
		//cost[i][source] = 1;
	}
	for ( int i = shift ; i < shift+m ; ++i ) {
		g[i].eb(sink);
		cost[i][sink] = 1;
		//g[sink].eb(i);
		//cost[sink][i] = 1;
	}
}

int bfs ( int source, int sink )
{
	v[source] = true;
	queue<pair<int,int>> q;
	q.push({source,1000000});
	while ( !q.empty() ) {
		int cp = q.front().F; int cs = q.front().S;
		q.pop();
		for ( const int& i : g[cp] ) {
			if ( cost[cp][i] > 0 && !v[i] ) {
				pre[i] = cp;
				v[i] = true;
				if ( i == sink )
					return min(cost[cp][i],cs);
				q.push({i,min(cost[cp][i],cs)});
			}
		}
	}
	return 0;
}

int max_flow ( int source, int sink )
{
	int mflow = 0;
	while ( true ) {
		v.assign(nax, false);
		int tflow = bfs ( source, sink );
		if ( tflow == 0 ) break;
		mflow += tflow;
		int now = sink, cur;
		while ( now != source ) {
			cur = pre[now];
			cost[cur][now] -= tflow;
			assert(cost[cur][now] > -1 );
			cost[now][cur] += tflow;
			now = cur;
		}
	}
	return mflow;
}

int main ()
{
	scanf ( "%d%d%d", &n, &m, &k );
	int source = shift - 1, sink = nax-1;
	prepare ( source, sink );
	for ( int i = 0 ; i < k ; ++i ) {
		scanf ( "%d%d", &l, &r );
		--l; --r; r += shift;
		g[l].eb(r);
		cost[l][r] = 1;
		g[r].eb(l);
		cost[r][l] = 1;
	}

	int flow = max_flow ( source, sink );
	(void)flow;

	//printf ( "%d\n", flow );

	vector<pair<int,int>> vpi;
	for ( int i = 0 ; i < n ; ++i )
		for ( const int& x : g[i] )
			if ( cost[i][x] == 0 )
				vpi.eb(i+1,x-shift+1);
	sort(vpi.begin(), vpi.end());
	vpi.resize(unique(vpi.begin(), vpi.end())- vpi.begin());
	printf ( "%zd\n", vpi.size() );
	vector<bool> _a(nax, false), _b(nax, false);
	for ( const pair<int,int>& i : vpi )
			printf ( "%d %d\n", i.F, i.S );
	//debug() << imie(vpi);

	return 0;
}
