#include "bits/stdc++.h"
using namespace std;

using ll = long long int;

struct st {
	bool u, r, b, l;
	st ( bool _u, bool _r, bool _b, bool _l )
	: u(_u), r(_r), b(_b), l(_l)
	{}
};

string read_string ()
{
	static char ch[105];
	scanf ( "%s", ch );
	return string ( ch );
}

const int nax = 105;
vector<vector<st>> bl ( nax, vector<st>(nax, {false,false, false,false}) );
//st bl[nax][nax];
bool v[nax][nax];
int r, c;

void clear ()
{
	for ( int i = 0 ; i < nax ; ++i ) for ( int j = 0 ; j < nax ; ++j ) v[i][j] = false;
	//for ( int i = 0 ; i < nax ; ++i ) for ( int j = 0 ; j < nax ; ++j ) bl.u=bl.r=bl.b=bl.l=false;
	for ( int i = 0 ; i < nax ; ++i ) for ( int j = 0 ; j < nax ; ++j ) bl[i][j]={false, false, false, false};
}

bool inside ( int row, int col )
{
	return ( row > -1 && row < r-1 && col > -1 && col < c-1 );
}

bool af ( int sr, int sc, int er, int ec )
{
	// 0, 1, 0, 2
	if ( sc == ec ) {
		if ( sr > er ) { // left
			return !bl[sr][sc].r;
		} else {
			return !bl[er][ec].r;
		}
	} else if ( sr == er ) {
		if ( sc > ec ) { // up
			return !bl[sr][sc].b;
		} else {
			return !bl[er][ec].b;
		}
	} else {
		assert ( false );
	}
}

const vector<pair<int,int>> stp {
	{ 1, 0 }, { 0, 1 },
	{ -1, 0 }, { 0, -1},
	{ 0, 1 }, { 1, 0 },
	{ 0, -1}, { -1, 0 }
};

void bfs ( int row, int col )
{
//	cerr << "Here " << row << " " << col << endl;
	queue<pair<int,int>> qu;
	qu.push({row,col});
	int ni, nj, cf, cs;
	while ( !qu.empty() ) {
		pair<int,int> cp = qu.front(); qu.pop();
		cf = cp.first; cs = cp.second;
		if ( v[cf][cs] ) continue;
//		cerr << cf << " " << cs << endl;
		v[cf][cs] = true;
		for ( const pair<int,int>& ns : stp ) {
			ni = cf+ns.first; nj = cs+ns.second;
			if ( inside ( ni, nj ) && af ( cf, cs, ni, nj ) && !v[ni][nj] ) {
				qu.push ( {ni, nj} );
			}
		}
	}
}

bool accessible ( int row, int col )
{
	return !bl[row][col].r;
}

void solve ()
{
	clear ();
	scanf ( "%d%d", &r, &c );
	string s;
	for ( int i = 0 ; i < r ; ++i ) {
		s = read_string ();
		for ( int j = 0 ; j < c ; ++j ) {
			if ( s[j] == 'R' ) {
				bl[i][j].r = true;
				bl[i][j+1].l = true;
			} else if ( s[j] == 'D' ) {
				bl[i][j].b = true;
				bl[i+1][j].u = true;
			} else if ( s[j] == 'B' ) {
				bl[i][j].r = true;
				bl[i][j+1].l = true;
				bl[i][j].b = true;
				bl[i+1][j].u = true;
			} else if ( s[j] == 'N' ) {
			}
		}
	}
	for ( int i = 0 ; i < c-1 ; ++i ) {
		if ( accessible( 0, i ) ) {
			bfs ( 0, i );
		}
	}
	int ans = 0;
#warning maybe speedup
	for ( int i = 0 ; i < nax ; ++i ) {
		for ( int j = 0 ; j < nax ; ++j ) {
			if ( v[i][j] ) ++ans;
		}
	}
	printf ( "%d\n", ans );
}

int main ()
{
	int t;
	scanf ( "%d", &t );
	for ( int i = 1 ; i <= t ; ++i ) {
		printf ( "Case %d: ", i );
		solve();
	}
//	for ( int i = 0 ; i < 3 ; ++i ) {
//		for ( int j = 0 ; j < 3 ; ++j ) {
//			cerr << bl[i][j].u << bl[i][j].r << bl[i][j].b << bl[i][j].l << " ";
//		}
//		cerr << endl;
//	}
//	for ( int i = 0 ; i < r - 1 ; ++i ) {
//		cerr << boolalpha << accessible ( i, 0 ) << endl;
//	}


	return 0;
}

