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
 
struct st {
	int d;
	int v;
};
 
void do_task ()
{
	string s, t; cin >> s >> t;
	int sl = s.length(), tl = t.length();
	vector<vector<st>> dp(sl+1, vector<st>(tl+1));
	for ( int i = 0 ; i < 1 ; ++i ) {
		for ( int j = 0 ; j < sl+1 ; ++j ) {
			dp[j][i] = { -1, 0 };
		}
		for ( int j = 0 ; j < tl+1 ; ++j ) {
			dp[i][j] = { -1, 0 };
		}
	}
	int left = 0, up = 1, cor = 2;
	for ( int i = 1 ; i < sl+1 ; ++i ) {
		for ( int j = 1 ; j < tl+1 ; ++j ) {
			if ( s[i-1] == t[j-1] ) {
				dp[i][j] = { cor, dp[i-1][j-1].v+1 };
			} else if ( dp[i][j-1].v > dp[i-1][j].v ) {
				dp[i][j] = { left, dp[i][j-1].v };
			} else {
				dp[i][j] = { up, dp[i-1][j].v };
			}
		}
	}
	// starting printing table
	cout << endl << "Printing Table" << endl;
	for ( int i = 0 ; i < sl+1 ; ++i ) {
		for ( int j = 0 ; j < tl+1 ; ++j ) {
			int dir = dp[i][j].d;
			int value = dp[i][j].v;
			if ( dir == left ) {
				cout << "←";
			} else if ( dir == up ) {
				cout << "↑";
			} else if ( dir == cor ) {
				cout << "↖";
			} else {
				cout << "⥀";
			}
			cout << value << " ";
		}
		cout << endl;
	}
	cout << endl;
	// end printing table
	string ans = "";
	int i = sl, j = tl, direction = dp[sl][tl].d;
	while ( direction != -1 ) {
		if ( direction == cor ) {
			ans += s[i-1];
			--i; --j;
		} else if ( direction == up ) {
			--i;
		} else {
			--j;
		}
		direction = dp[i][j].d;
	}
	reverse(ans.begin(), ans.end());
	cout << "The LCS is : " << ans << endl;
}
 
int main ()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
 
	prepare_lookup_table();
 
	do_task();
 
 
	return 0;
}
