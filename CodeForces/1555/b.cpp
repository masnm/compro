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

double W, H, xa, ya, xb, yb, w, h;

bool fits ()
{
	double wi = xb - xa + w;
	double hi = yb - ya + h;
	if ( wi<=W && max(h,yb-ya)<=H ) return true;
	if ( hi<=H && max(w,xb-xa)<=W ) return true;
	return false;
}

double get ()
{
	double mx = DBL_MAX;
	double tw = W-w, th = H-h;
	debug() << imie(tw) imie(th);
	if ( !(((xb-xa)<=tw) && ((yb-ya)<=th)) ) return mx;
	double l = abs(tw-xb), r = abs(th-yb);
	return sqrt((l*l)+(r*r));
}

void shift ()
{
	double a = W-xb, b = H-yb;
	xb = W-xa; yb = H-ya;
	xa = a; ya = b;
}

void flip ()
{
	double td = H - yb, bd = ya;
	ya = td; yb = H - bd;
}

double ga ()
{
	double ne = h - ( H - yb );
	if ( ne < 0 ) ne = 0;
	debug() << imie(h) imie(H) imie(yb) imie(ne);
	if ( ya < ne ) return DBL_MAX;
	if ( W < w ) return DBL_MAX;
	return ne;
}

void solve ()
{
	scanf ( "%lf%lf", &W, &H );
	scanf ( "%lf%lf%lf%lf", &xa, &ya, &xb, &yb );
	scanf ( "%lf%lf", &w, &h );
	if ( !fits() ) {
		puts ( "-1" );
		return;
	}
	double ans = DBL_MAX;
	for ( int rep = 0 ; rep < 2 ; ++rep ) {
		ans = min ( ans, ga() );
		shift ();
		ans = min ( ans, ga() );
		shift ();
		swap ( W, H );
		swap ( w, h );
		swap ( xa, ya );
		swap ( xb, yb );
	}
	//double ans = get ();
	//shift ();
	//ans = min ( ans, get() );
	//shift ();
	//flip ();
	//ans = min ( ans, get() );
	//shift ();
	//ans = min ( ans, get() );
	if ( ans == DBL_MAX ) {
		puts ( "-1" );
		return;
	}
	printf ( "%lf\n", ans );
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

