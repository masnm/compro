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

vector<int> p;

struct dsu {
	int n;
	vector<int> gi;
	vector<vector<int>> gm;
	void init ( int _n )
	{
		n = _n;
		gi.resize ( n );
		iota ( gi.begin(), gi.end(), 0 );
		gm.resize ( n );
		for ( int i = 0 ; i < n ; ++i ) {
			gm[i].clear();
			gm[i].eb ( i );
		}
	}
	void add ( int l, int r )
	{
		int gl = gi[l], gr = gi[r];
		if ( gl == gr ) return;
		if ( gm[gl] > gm[gr] ) swap ( gl, gr );
		for ( auto i : gm[gl] ) {
			gm[gr].eb ( i );
			gi[i] = gr;
		}
		gm[gl].clear();
		gm[gl].shrink_to_fit();
	}
	bool done ()
	{
		return gm[gi[0]].size() == size_t(n);
	}
};

int main ( int argc, char* argv[] )
{
	int n; scanf ( "%d", &n );
	vector<pair<int,int>> va ( n ), vb ( n );
	for ( int i = 0 ; i < n ; ++i ) {
		va[i].second = i;
		scanf ( "%d", &va[i].first );
	}
	for ( int i = 0 ; i < n ; ++i ) {
		vb[i].second = i;
		scanf ( "%d", &vb[i].first );
	}
	p.resize ( n );
	for ( auto& i : p ) scanf ( "%d", &i );
	sort ( va.begin(), va.end() );
	sort ( vb.begin(), vb.end() );
	for ( int i = 0 ; i < n ; ++i ) {
		va[i].first = vb[i].second;
	}
	vb.clear(); vb.shrink_to_fit();
	dsu d;
	d.init ( 2*n );
	for ( int i = 0 ; i < n ; ++i ) d.add ( va[i].first, va[i].second + n );
	for ( int i = 0 ; i < n ; ++i ) d.add ( i, i + n );
	ll ans = 0;
	vector<bool> v ( n );
	int cgi = d.gi[0], cmin = INT_MAX;
	for ( auto x : d.gm[cgi] ) cmin = min ( cmin, p[(x>=n?x-n:x)] );
	vector<int> vans; vans.eb ( cmin );
	assert ( cmin != INT_MAX );
	for ( int i = 0 ; i < n ; ++i ) {
		if ( d.gi[i] != cgi ) {
			int tdi = INT_MAX;
			for ( auto x : d.gm[d.gi[i]] ) tdi = min ( tdi, p[(x>=n?x-n:x)] );
			assert ( tdi != INT_MAX );
			for ( auto x : d.gm[d.gi[i]] ) d.gi[x] = cgi;
			// d.add ( d.gm[cgi][0], d.gm[d.gi[i]][0] );
			vans.eb ( tdi );
			// ans += cmin;
			// ans += tdi;
			// cgi = d.gi[0];
			// cmin = min ( cmin, tdi );
		}
	}
	sort ( vans.begin(), vans.end() );
	ans = accumulate ( vans.begin(), vans.end(), 0LL );
	ans -= ( vans[0] );
	ans += ( ll(vans[0]) * ll(vans.size()-1) );
	printf ( "%lld", ans );

	return 0;
}

