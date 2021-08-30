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

void solve ()
{
	double u, ul, dl, di;
	scanf ( "%lf%lf%lf", &u, &ul, &dl );
	double ans = DBL_MAX;
	for ( double i = 0 ; i <= ul ; i += 1.0 ) {
		double x = sqrt ( (dl*dl) + (i*i) );
		double ds = u-i;
		double y = sqrt ( (ul*ul) + (ds*ds) );
		x += (y/2.0);
		if ( ans > x ) ans = x, di = i;
	}
	for ( double i = di - 1.0 ; i <= di + 1.0 ; i += 0.001 ) {
		double x = sqrt ( (dl*dl) + (i*i) );
		double ds = u-i;
		double y = sqrt ( (ul*ul) + (ds*ds) );
		x += (y/2.0);
		if ( ans > x ) ans = x, di = i;
	}
	double x = sqrt ( (dl*dl) + (di*di) );
	double ds = u-di;
	double y = sqrt ( (ul*ul) + (ds*ds) );
	double ans_s = x + y;
	printf ( "%.9lf\n", x + y );
}

int main ()
{
	int t;
	scanf ( "%d", &t );
	while ( t-- ) solve();


	puts("");
	return 0;
}

