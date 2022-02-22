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

const int nax = 1e5 + 5;
int n, l, r, addi, revi;
vector<int> g[nax], pt(nax), ver(nax), psq;
vector<pair<int,int>> add ( nax ), rev ( nax );
bool v[nax], v2[nax];

int bfs_get ( int _l, bool* _v )
{
	queue<int> q; int cp = -1;
	q.push ( _l );
	while ( !q.empty() ) {
		cp = q.front(); q.pop();
		_v[cp] = true;
		for ( int i : g[cp] )
			if ( !_v[i] )
				q.push ( i );
	}
	assert ( cp != -1 );
	return cp;
}

void erase ( vector<int>& _v, int val )
{
	int ind = -1;
	for ( int i = 0 ; i < (int)_v.size() ; ++i )
		if ( _v[i] == val ) {
			ind = i;
			break;
		}
	_v.erase ( _v.begin() + ind );
}

void get_ready ()
{
	psq.clear();
	queue<pair<int,int>> q; q.push ( { l, -1 } );
	while ( !q.empty() ) {
		int cp = q.front().F, pr = q.front().S, cnt = 0;
		q.pop();
		if ( v[cp] ) continue;
		psq.eb ( cp );
		v[cp] = true; pt[cp] = pr;
		for ( int i : g[cp] ) {
			if ( !v[i] ) {
				q.push ( { i, cp } );
				++cnt;
			}
		}
		ver[cp] = cnt;
	}
}

void solve ()
{
	scanf ( "%d", &n );
	addi = 0; revi = 0;
	for ( int i = 1 ; i <= n ; ++i )
		g[i].clear(), v[i] = false, pt[i] = -1, ver[i] = 0;
	for ( int i = 0 ; i < n - 1 ; ++i ) {
		scanf ( "%d%d", &l, &r );
		g[l].eb(r); g[r].eb(l);
	}
	get_ready ();
	for ( int i = int(psq.size()) - 1 ; i > -1 ; --i ) {
		int cp = psq[i];
		if ( ver[cp] == 2 ) {
			if ( pt[cp] != -1 ) {
				erase ( g[cp], pt[cp] );
				erase ( g[pt[cp]], cp );
				--ver[pt[cp]];
				rev[revi++] = { cp, pt[cp] };
				// add to remove
			}
		} else if ( ver[cp] > 2 ) {
			if ( pt[cp] != -1 ) {
				erase ( g[cp], pt[cp] );
				erase ( g[pt[cp]], cp );
				--ver[pt[cp]];
				rev[revi++] = { cp, pt[cp] };
				// add to remove
			}
			while ( g[cp].size() > 2 ) {
				int ccp = g[cp].back();
				erase ( g[cp], ccp );
				erase ( g[ccp], cp );
				--ver[ccp];
				rev[revi++] = { cp, ccp };
				// add to remove
			}
		}
	}
	for ( int i = 1 ; i <= n ; ++i ) v[i] = false, v2[i] = false;
	int cur_end = bfs_get ( l, v );
	for ( int i = 1 ; i <= n ; ++i ) {
		if ( !v[i] ) {
			int tend = bfs_get ( i, v );
			int oend = bfs_get ( tend, v2 );
			add[addi++] = { cur_end, tend };
			cur_end = oend;
		}
	}
	assert ( addi == revi );
	printf ( "%d\n", addi );
	for ( int i = 0 ; i < addi ; ++i )
		printf ( "%d %d %d %d\n", rev[i].F, rev[i].S, add[i].F, add[i].S );
}

int main ()
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}

	return 0;
}
