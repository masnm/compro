#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long double ld;
typedef long long int ll;
typedef unsigned long long ull;

template<typename T> void chmax ( T& a, T b ) { if ( a < b ) a = b; }
template<typename T> void chmin ( T& a, T b ) { if ( a > b ) a = b; }

void prepare_lookup_table ()
{
}

const ll queen = INT_MAX;

void print ( vector<vector<int>>& v )
{
	for ( auto& i : v ) {
		for ( auto& j : i ) {
			cout << (j==queen?'Q':'.') << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void downgrade ( vector<vector<int>>& v, int x, int y, int n )
{
	for ( ll i = 0 ; i < n ; ++i ) {
		if ( v[x][i] != queen ) --v[x][i];
		if ( v[i][y] != queen ) --v[i][y];
	}
	for ( ll i = 1 ; i <= n ; ++i ) {
		if ( x+i < n && y+i < n ) {
			--v[x+i][y+i];
		} else {
			break;
		}
	}
	for ( ll i = 1 ; i <= n ; ++i ) {
		if ( x-i > -1 && y-i > -1 ) {
			--v[x-i][y-i];
		} else {
			break;
		}
	}
	for ( ll i = 1 ; i <= n ; ++i ) {
		if ( x-i > -1 && y+i < n ) {
			--v[x-i][y+i];
		} else {
			break;
		}
	}
	for ( ll i = 1 ; i <= n ; ++i ) {
		if ( x+i < n && y-i > -1 ) {
			--v[x+i][y-i];
		} else {
			break;
		}
	}
}

void upgrade ( vector<vector<int>>& v, int x, int y, int n )
{
	for ( ll i = 0 ; i < n ; ++i ) {
		if ( v[x][i] != queen ) ++v[x][i];
		if ( v[i][y] != queen ) ++v[i][y];
	}
	for ( ll i = 1 ; i <= n ; ++i ) {
		if ( x+i < n && y+i < n ) {
			++v[x+i][y+i];
		} else {
			break;
		}
	}
	for ( ll i = 1 ; i <= n ; ++i ) {
		if ( x-i > -1 && y-i > -1 ) {
			++v[x-i][y-i];
		} else {
			break;
		}
	}
	for ( ll i = 1 ; i <= n ; ++i ) {
		if ( x-i > -1 && y+i < n ) {
			++v[x-i][y+i];
		} else {
			break;
		}
	}
	for ( ll i = 1 ; i <= n ; ++i ) {
		if ( x+i < n && y-i > -1 ) {
			++v[x+i][y-i];
		} else {
			break;
		}
	}
}

bool solve ( vector<vector<int>>& v, int ind, int& n )
{
	if ( ind == n ) {
		cout << "Found solution :) " << endl;
		return true;
	}
	for ( ll i = 0 ; i < n ; ++i ) {
		if ( !v[ind][i] ) {
			v[ind][i] = queen;
			upgrade ( v, ind, i, n );

			cout << "Going to row " << ind+1 << endl;
			print ( v );

			bool ans = solve ( v, ind+1, n );
			if ( ans ) {
				return true;
			}

			downgrade ( v, ind, i, n );
			v[ind][i] = 0;
		}
	}
	print ( v );
	cout << "Failed in row " << ind+1 << " . So, " << endl;
	cout << "Back tracking." << endl << endl;
	return false;
}

void do_task ()
{
	int n; cin >> n;
	vector<vector<int>> v(n, vector<int>(n,0));
	if ( solve ( v, 0, n ) ) {
		print ( v );
	} else {
		cout << "No solution." << endl;
	}
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	prepare_lookup_table();

	int t = 1;
	for ( int i = 1 ; i <= t ; ++i ) {
		//cout << "Case " << i << ": " ;
		do_task();
	}


	return 0;
}
// resize-pane -L 30 
