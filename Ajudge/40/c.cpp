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

struct st {
	int s, e, c;
	st ( int _s, int _e, int _c ) :
		s(_s), e(_e), c(_c) { }
};

const int nax = 105;
map<string,int> mp;
vector<st> vp;
vector<int> r(nax), gm[nax];

bool add ( int s, int e, int c )
{
	if ( r[s] == r[e] ) return false;
	int rs = r[s], re = r[e];
	if ( gm[rs].size() > gm[re].size() ) swap ( rs, re );
	for ( const int& i : gm[rs] ) {
		r[i] = re;
		gm[re].eb(i);
	}
	gm[rs].clear();
	return true;
}

string read_string ()
{
	static char ch[55];
	scanf ( "%s", ch );
	return string ( ch );
}

void solve ()
{
	mp.clear();
	vp.clear();
	for ( int i = 0 ; i < nax ; ++i ) r[i] = i;
	for ( int i = 0 ; i < nax ; ++i ) gm[i].clear(), gm[i].eb(i);
	int N = 0;
	int n, l, rr, c;
	scanf ( "%d", &n );
	string s;
	for ( int i = 0 ; i < n ; ++i ) {
		s = read_string ();
		auto search = mp.find(s);
		if ( search == mp.end() ) {
			l = N++;
			mp[s] = N - 1;
		} else {
			l = search->S;
		}
		s = read_string ();
		search = mp.find(s);
		if ( search == mp.end() ) {
			rr = N++;
			mp[s] = N - 1;
		} else {
			rr = search->S;
		}
		scanf ( "%d", &c );
		vp.eb ( l, rr, c );
	}
	sort ( vp.begin(), vp.end(), [&](const st& ss, const st& ee) { return ss.c < ee.c; } );
	assert ( N < nax );
	ll coast = 0;
	for ( const st& sst : vp )
		if ( add ( sst.s, sst.e, sst.c ) )
			coast += sst.c;
	bool ans = true;
	int rt = r[0];
	for ( int i = 0 ; i < N ; ++i )
		if ( r[i] != rt ) ans = false;
	if ( !ans ) {
		puts ( "Impossible" );
		return;
	}
	printf ( "%lld\n", coast );
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
