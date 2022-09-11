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

#define left 0
#define left_up 1
#define up 2
#define none 3

vector<vector<int>> dp;
vector<vector<short>> dir;

string get_lcs ( string l, string r )
{
	dp.resize ( l.size() + 1 );
	dir.resize ( l.size() + 1 );
	for ( int i = 0 ; i <= int(l.size()) ; ++i ) {
		dp[i].resize ( r.size() + 1 );
		dir[i].resize ( r.size() + 1 );
	}
	for ( int i = 0 ; i <= int(l.size()) ; ++i ) {
		dp[i][0] = 0;
		dir[i][0] = none;
	}
	for ( int i = 0 ; i <= int(r.size()) ; ++i ) {
		dp[0][i] = 0;
		dir[0][i] = none;
	}
	for ( int i = 1 ; i < int(l.size()) ; ++i )
		for ( int j = 1 ; j < int(r.size()) ; ++j ) {
			if ( l[i-1] == r[j-1] ) {
				dp[i][j] = dp[i-1][j-1] + 1;
				dir[i][j] = left_up;
			} else {
				if ( dp[i-1][j] > dp[i][j-1] ) {
					dp[i][j] = dp[i-1][j];
					dir[i][j] = left;
				} else {
					dp[i][j] = dp[i][j-1];
					dir[i][j] = up;
				}
			}
		}
	string ans;
	pair<int,int> c = make_pair ( l.size(), r.size() );
	while ( dir[c.F][c.S] != none ) {
		if ( dir[c.F][c.S] == left ) c.F -= 1;
		else if ( dir[c.F][c.S] == up ) c.S -= 1;
		else if ( dir[c.F][c.S] == left_up ) {
			c.F -= 1; c.S -= 1;
			ans += l[c.F-1];
		}
	}
	reverse ( ans.begin(), ans.end() );
	return ans;
}

void solve ()
{
	string l = read_string(), r = read_string();
	string ans = get_lcs ( l, r );
	debug() << imie(ans);
}

int main ( int argc, char* argv[] )
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

