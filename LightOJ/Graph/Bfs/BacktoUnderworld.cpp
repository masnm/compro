#include "bits/stdc++.h"
using namespace std;

using ll = long long int;

const int nax = 2e4 + 5;
int n, l, r;
vector<int> g[nax];
vector<bool> v(nax);

int bfs ( int me )
{
	vector<int> sm(2,0);
	queue<pair<int,int>> q;
	q.push ( make_pair(me, 0) );
	while ( !q.empty() ) {
		int cp = q.front().first, col = q.front().second;
		q.pop();
		if ( v[cp] ) continue;
		++sm[col]; v[cp] = true;
		for ( int i : g[cp] )
			if ( !v[i] )
				q.push ( make_pair(i,col^1) );
	}
	return max ( sm[0], sm[1] );
}

void solve ()
{
	scanf ( "%d", &n );
	for ( int i = 1 ; i < nax ; ++i )
		g[i].clear(), v[i] = false;
	for ( int i = 1 ; i <= n ; ++i ) {
		scanf ( "%d%d", &l, &r );
		g[l].emplace_back (r);
		g[r].emplace_back (l);
	}
	int ans = 0;
	for ( int i = 1 ; i < nax ; ++i )
		if ( g[i].size()>0 && !v[i] ) ans += bfs(i);
	printf ( "%d\n", ans );
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

