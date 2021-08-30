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

using ll = long long int;

const int nax = 205;
const ll inf = 1e15 + 5;
ll fc[3];
pair<int,int> bst, sbst, tbst;
int r, c;
char mz[nax][nax];
ll dp[nax][nax];
bool v[nax][nax];

const vector<pair<int,int>> stp {
	{ -1, 0 }, { 0, -1 },
	{ 1, 0 }, { 0, 1 }
};

bool inside ( int ni, int nj )
{
	return ( ni > -1 && ni <= r && nj > -1 && nj <= c );
}

void bfs ( int si, int ei, char tgt )
{
	dp[si][ei] = 0LL;
	int ni, nj;
	queue<pair<int,int>> q;
	q.push ( { si, ei } );
	while ( !q.empty() ) {
		pair<int,int> cp = q.front(); q.pop();
		if ( tgt != 'P' && mz[cp.first][cp.second] == '*' && !v[cp.first][cp.second] ) {
			if ( dp[bst.first][bst.second] > dp[cp.first][cp.second] ) {
				fc[0] = dp[cp.first][cp.second];
				bst = cp;
			} else if ( dp[sbst.first][sbst.second] > dp[cp.first][cp.second] ) {
				fc[1] = dp[cp.first][cp.second];
				sbst = cp;
			}
			v[cp.first][cp.second] = true;
			continue;
		} else if ( tgt == 'P' && mz[cp.first][cp.second] == '*' && !v[cp.first][cp.second] ) {
			if ( dp[tbst.first][tbst.second] > dp[cp.first][cp.second] ) {
				fc[2] = dp[cp.first][cp.second];
				tbst = cp;
			}
			v[cp.first][cp.second] = true;
			continue;
		}
		if ( v[cp.first][cp.second] ) continue;
		v[cp.first][cp.second] = true;
		if ( mz[cp.first][cp.second] == tgt ) break;
		for ( const pair<int,int>& st : stp ) {
			ni = cp.first + st.first;
			nj = cp.second + st.second;
			if ( inside ( ni, nj ) && !v[ni][nj] && mz[ni][nj] != '#' ) {
				dp[ni][nj] = dp[cp.first][cp.second] + 1LL;
				q.push ( { ni, nj } );
			}
		}
	}
}

void solve ()
{
	scanf ( "%d%d", &r, &c );
	int bs = -1, be = -1, ds = -1, de = -1;
	for ( int i = 0 ; i < r ; ++i ) {
		scanf ( "%s", mz[i] );
		for ( int j = 0 ; j < c ; ++j ) {
			if ( mz[i][j] == 'P' )
				bs = i, be = j;
			if ( mz[i][j] == 'D' )
				ds = i, de = j;
		}
	}
	//
	dp[nax-1][nax-1] = inf;
	bst = sbst = tbst = { nax-1, nax-1 };
	fc[0] = fc[1] = fc[2] = inf;
	//
	ll ans = inf;
	for ( int i = 0 ; i < nax ; ++i ) for ( int j = 0 ; j < nax ; ++j ) v[i][j] = false;
	bfs ( bs, be, 'D' );
	if ( v[ds][de] ) ans = min ( ans, dp[ds][de] );
	for ( int i = 0 ; i < nax ; ++i ) for ( int j = 0 ; j < nax ; ++j ) v[i][j] = false;
	bfs ( ds, de, 'P' );
	int ci = nax, cj = nax;
	auto ok = [&] ( int i, int j )
	{
		if ( bst.first == i && j == bst.second ) return false;
		if ( sbst.first == i && j == sbst.second ) return false;
		if ( tbst.first == i && j == tbst.second ) return false;
		return true;
	};
	bool found = false;
	for ( int i = 0 ; i < r ; ++i ) {
		for ( int j = 0 ; j < c ; ++j ) {
			if ( found ) break;
			if ( mz[i][j] == '*' && ok ( i, j ) ) {
				found = true;
				ci = i;
				cj = j;
			}
		}
		if ( found ) break;
	}
	if ( bst == tbst && found ) {
		ans = min ( ans, fc[0] + fc[2] + 2LL );
	}
	if ( bst != tbst ) {
		ans = min ( ans, fc[0] + fc[2] + 1LL );
	}
	if ( sbst != tbst ) {
		ans = min ( ans, fc[1] + fc[2] + 1LL );
	}
	if ( bst == tbst ) {
		ans = min ( ans, fc[1] + fc[2] + 1LL );
	}
	if ( sbst == tbst ) {
		ans = min ( ans, fc[0] + fc[2] + 1LL );
	}

	if ( ans == inf ) {
		puts ( "impossible" );
	} else {
		printf ( "%lld\n", ans );
	}
	for ( int i = 0 ; i < r ; ++i ) debug() << imie(i) imie(mz[i]);
	debug() << imie(bs) imie(be) imie(ds) imie(de);
	debug() << imie(bst) imie(sbst) imie(tbst);
	debug() << imie(ci) imie(cj);
}

int main ()
{
	int t;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

