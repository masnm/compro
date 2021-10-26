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
	int s, e;
	float c;
	st ( int _s, int _e, float _c ) :
		s(_s), e(_e), c(_c) {}
	st () : s(0), e(0), c(0.0) {}
};
debug & operator << (debug & dd, st p) { dd << "(" << p.s << ", " << p.e << ", " << p.c << ")"; return dd; }

vector<pair<float,float>> vp;
vector<st> vs;
const int nax = 105;
vector<int> rt(nax), gm[nax];

void clr ()
{
	for ( int i = 0 ; i < nax ; ++i ) rt[i] = i;
	for ( int i = 0 ; i < nax ; ++i ) gm[i].clear(), gm[i].eb(i);
}

bool add ( int s, int e )
{
	if ( rt[s] == rt[e] )
		return false;
	int rs = rt[s], re = rt[e];
	if ( gm[rs].size() < gm[re].size() ) swap ( rs, re );
	for ( const int& i : gm[rs] ) {
		rt[i] = re;
		gm[re].eb(i);
	}
	gm[rs].clear();
	return true;
}

float calcul ( int n )
{
	clr();
	sort ( vs.begin(),
		vs.end(),
		[&](const st& lll, const st& rr)
		{ return lll.c < rr.c; }
	     );
	float ans = 0;
	for ( const st& x : vs )
		if ( add ( x.s, x.e ) )
			ans += x.c;
	return ans;
}

void solve ()
{
	vp.clear();
	vs.clear();
	int n;
	scanf ( "%d", &n );
	float x, y;
	for ( int i = 0 ; i < n ; ++i ) {
		scanf ( "%f%f", &x, &y );
		vp.eb(x,y);
	}
	for ( int i = 0 ; i < n ; ++i ) {
		for ( int j = i + 1 ; j < n ; ++j ) {
			float xx = abs ( vp[i].F - vp[j].F );
			float yy = abs ( vp[i].S - vp[j].S );
			float dis = (xx*xx) + (yy*yy);
			dis = sqrt ( dis );
			vs.eb(i,j,dis);
		}
	}
	float ans = calcul ( n );
	printf ( "%.2f\n", ans );
}

int main ()
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		if ( i != 0 ) puts ("");
		solve ();
	}


	return 0;
}

