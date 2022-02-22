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
string read_string ()
{
	static char ch[25];
	scanf ( "%s", ch );
	return string ( ch );
}

const vector<pair<int,int>> stps {
	{ -1, 0 }, { 0, -1 },
	{ +1, 0 }, { 0, +1 }
};

pair<int,int> operator+ ( pair<int,int>& l, pair<int,int>& r ) {
	return make_pair(l.F+r.F,l.S+r.S);
}

const int nax = 21;
vector<string> vs (nax);
vector<vector<bool>> v(nax, vector<bool>(nax));
int n, m;

int bfs ( pair<int,int> pl )
{
	int cnt = 0;
	queue<pair<int,int>> q; q.push ( pl );
	auto inside = [](pair<int,int>pos) {
		return (pos.F>-1&&pos.S>-1&&pos.F<m&&pos.S<n);
	};
	while ( !q.empty() ) {
		pair<int,int> cp = q.front(); q.pop();
		if ( v[cp.F][cp.S] ) continue;
		v[cp.F][cp.S] = true; ++cnt;
		for ( pair<int,int> st : stps ) {
			pair<int,int> nxt = cp+st;
			if ( inside(nxt) && !v[nxt.F][nxt.S] && vs[nxt.F][nxt.S] != '#' )
				q.push ( nxt );
		}
	}
	return cnt;
}

void solve ()
{
	scanf ( "%d%d", &n, &m );
	pair<int,int> pl;
	for ( int i = 0 ; i < m ; ++i )
		for ( int j = 0 ; j < n ; ++j )
			v[i][j] = false;
	for ( int i = 0 ; i < m ; ++i ) {
		vs[i] = read_string();
		for ( int j = 0 ; j < n ; ++j )
			if ( vs[i][j] == '@' )
				pl = {i,j};
	}
	int res = bfs ( pl );
	printf ( "%d\n", res );
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

