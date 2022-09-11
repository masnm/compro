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

struct tpl {
	tpl () = default;
	tpl ( int _i, int _j, int _us ) :
		i(_i), j(_j), us(_us) {}
	int i = 0;
	int j = 0;
	int us = 0;
};

const int dpr = 30, dpc = 200;
int n, h;
vector<int> f, d, t;
vector<vector<int>> dp( dpr, vector<int> ( dpc ) ); // [dpr][dpc];
vector<vector<tpl>> dir( dpr, vector<tpl> ( dpc ) ); // [dpr][dpc];

void solve ()
{
	scanf ( "%d%d", &n, &h );
	f.resize ( n );
	for ( auto& i : f ) scanf ( "%d", &i );
	d.resize ( n );
	for ( auto& i : d ) scanf ( "%d", &i );
	t.resize ( n - 1 );
	for ( auto& i : t ) scanf ( "%d", &i );
	t.eb ( 0 );
	for ( int i = 0 ; i < dpr ; ++i )
		for ( int j = 0 ; j < dpc ; ++j )
			dp[i][j] = -1;
	for ( int i = 0 ; i < dpr ; ++i )
		for ( int j = 0 ; j < dpc ; ++j )
			dir[i][j] = tpl { i, j, 0 };
	auto getval = [](int i, int j) {
		if ( j == 0 ) return 0;
		int val = f[i];
		int ret = 0;
		for ( int x = 0 ; x < j ; ++x ) {
			ret += val;
			val -= d[i];
			val = max ( 0, val );
		}
		return ret;
	};
	dp[0][h*12] = 0;
	for ( int pool = 0 ; pool < n ; ++pool )
		for ( int thave = 0 ; thave <= h*12 ; ++thave )
			if ( dp[pool][thave] != -1 )
				for ( int nt = 0 ; nt <= thave ; ++nt ) {
					int nval = dp[pool][thave] + getval ( pool, nt );
					int nth = thave - nt - t[pool];
					nth = max ( nth, 0 );
					if ( nval > dp[pool+1][nth] ) {
						dp[pool+1][nth] = nval;
						dir[pool+1][nth] = tpl { pool, thave, nt };
					}
				}
	int mx = 0;
	for ( int i = 0 ; i < dpr ; ++i )
		for ( int j = 0 ; j < dpc ; ++j )
			mx = max ( mx, dp[i][j] );
	vector<pair<int,int>> vp;
	for ( int i = 0 ; i < dpr ; ++i )
		for ( int j = 0 ; j < dpc ; ++j )
			if ( dp[i][j] == mx )
				vp.eb ( i, j );
	int ind = 0;
	vector<vector<int>> vvi ( vp.size() );
	for ( auto i : vp ) {
		while ( i != make_pair ( dir[i.F][i.S].i, dir[i.F][i.S].j ) ) {
			vvi[ind].eb ( dir[i.F][i.S].us );
			i = make_pair ( dir[i.F][i.S].i, dir[i.F][i.S].j );
		}
		ind++;
	}
	for ( auto& i : vvi ) reverse ( i.begin(), i.end() );
	sort ( vvi.begin(), vvi.end() );
	vector<int> ans = vvi.back();
	while ( int(ans.size()) < n ) ans.eb ( 0 );
	for ( int i = 0 ; i < n ; ++i ) {
		if ( i != 0 ) printf ( ", " );
		printf ( "%d", ans[i]*5 );
	}
	puts ( "" );
	printf ( "Number of fish expected: %d\n", mx );
}

int main ( int argc, char* argv[] )
{
	int tt = 1;
	scanf ( "%d" , &tt );
	for ( int i = 0 ; i < tt ; ++i ) {
		printf ( "Case %d:\n", i+1 );
		solve ();
	}


	return 0;
}

