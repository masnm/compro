#include "bits/stdc++.h"
using namespace std;

using ll = long long int;

const int nax = 20005;
int th[nax];
vector<pair<int,int>> vp;
bool v[nax];

void clear ()
{
	vp.clear();
	for ( int i = 0 ; i < nax ; ++i ) th[i] = 0;
	for ( int i = 0 ; i < nax ; ++i ) v[i] = false;
}

void dfs ( const vector<vector<pair<int,int>>>& vv, int me )
{
	v[me] = true;
	for ( const pair<int,int>& e : vv[me] ) {
		if ( !v[e.first] )
			dfs ( vv, e.first );
	}
	int tc = 0;
	for ( const pair<int,int>& e : vv[me] ) {
		tc += th[e.first];
	}
	th[me] = tc + 1;
}

void ndfs ( const vector<vector<pair<int,int>>>& vv, int onl, int onr, int pv, int me )
{
	v[me] = true;
	for ( const vector<pair<int,int>>& e : vv[me] ) {
		thc -= th[e.first];
		if ( !v[e.first] && e.first != pv )
			ndfs ( vv, th[e.first], thc + 1, me, e.first );
		thc += th[e.first];
	}
}

void solve ()
{
	clear();
	int n, s, e, c;
	scanf ( "%d", &n );
	vector<vector<pair<int,int>>> vv ( n, vector<pair<int,int>>() );
	for ( int i = 0 ; i < n ; ++i ) {
		scanf ( "%d%d%d", &s, &e, &c );
		vv[s].emplace_back(e, c);
		vv[e].emplace_back(s, c);
	}
	int root = vv[0].first;
	dfs ( vv, root );
	for ( int i = 0 ; i < nax ; ++i ) v[i] = false;
	int thc = 0;
	for ( const pair<int,int>& e : vv[root] ) thc += th[e.first];
	ndfs ( vv, thc, 0, -1, root );
}

int main ()
{
	int t;
	scanf ( "%d", &t );
	for ( int i = 1 ; i <= t ; ++i ) {
		printf ( "Case %d: ", i );
		solve ();
	}



	return 0;
}

