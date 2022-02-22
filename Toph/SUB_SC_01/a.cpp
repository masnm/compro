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
	static char ch[15];
	scanf ( "%s", ch );
	return string ( ch );
}

struct st {
	string logic;
	bool out, first;
	st () : logic(""), out(false),first(false) {}
	st ( string _f, bool _o, bool _fi ) :
		logic(_f), out(_o), first(_fi)
	{}
};
debug & operator << (debug & dd, st p) { dd << "(" << p.logic << ", " << p.out << ", " << p.first << ")"; return dd; }

const int nax = 1005;
int n, m, l, r;
vector<int> g[nax];
vector<string> vs;
vector<st> vst ( nax, {"", false, false} );

int main ()
{
	vs.clear();
	scanf ( "%d%d", &n, &m );
	assert ( n<= 1000 );
	vs.eb("Source");
	for ( int i = 0 ; i < n ; ++i )
		vs.eb(read_string());
	for ( int i = 0 ; i < n ; ++i )
		g[i].clear();
	for ( int i = 0 ; i < m ; ++i ) {
		scanf ( "%d%d", &l, &r );
		assert(l>=0 && l<=1000);
		assert(r>0 && r<=1000);
		g[l].eb(r);
	}
	vst[0] = { "Source", true, true };
	string inv = "Invert";
	for ( int i = 0 ; i < n ; ++i ) {
		for ( int x : g[i] ) {
			if ( !vst[x].first ) {
				vst[x].first = true;
				vst[x].out = ( vs[x]==inv ? !vst[i].out : vst[i].out );
			} else {
				if ( vs[x]=="And" ) { vst[x].out &= vst[i].out; }
				else if ( vs[x]=="Or" ) { vst[x].out |= vst[i].out; }
				else if ( vs[x]=="Xor" ) { vst[x].out ^= vst[i].out; }
			}
		}
	}
	for ( int i = 1 ; i <= n ; ++i ) {
		puts ( vst[i].out ? "1" : "0" );
	}

	return 0;
}

