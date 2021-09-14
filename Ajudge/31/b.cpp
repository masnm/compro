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
char read_string ()
{
	static char ch[5];
	scanf ( "%s", ch );
	return ch[0];
}

const int nax = 100005;
vector<int> gn(nax), pig[nax];
int n, s, e, yc, nc;
char c;

void uni ()
{
	int sg = gn[s], eg = gn[e];
	if ( sg == eg ) return;
	if ( pig[sg].size() < pig[eg].size() ) swap ( sg, eg );
	for ( const int& i : pig[eg] ) {
		gn[i] = sg;
		pig[sg].eb(i);
	}
	pig[eg].clear();
}

void updt ()
{
	if ( gn[s] == gn[e] ) ++yc;
	else ++nc;
}

void solve ()
{
	scanf ( "%d", &n );
	assert ( n < nax );
	for ( int i = 0 ; i < nax ; ++i ) gn[i] = i;
	for ( int i = 0 ; i < nax ; ++i ) pig[i].clear(), pig[i].eb(i);
	yc = nc = 0;
	for ( int i = 0 ; i < n ; ++i ) {
		c = read_string ();
		scanf ( "%d%d", &s, &e );
		debug() << imie(c) imie(s) imie(e);
		if ( c == 'c' ) uni ();
		else if ( c == 'q' ) updt ();
		else assert ( false );
	}
	printf ( "%d %d\n", yc, nc );
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

