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
	int a, b, c, d, e;
	st () : a(0), b(0), c(0), d(0), e(0) {}
	st ( int _a, int _b, int _c, int _d, int _e ) :
		a(_a), b(_b), c(_c), d(_d), e(_e) {}
};
debug & operator << (debug & dd, st p) { dd << "(" << p.a << ", "<< p.b << ", "<< p.c << ", "<< p.d << ", " << p.e << ")"; return dd; }

const int nax = 50005;

vector<st> v ( nax );

int cmp ( st& l, st& r )
{
	int lc = 0, rc = 0;
	lc += l.a < r.a; rc += r.a < l.a;
	lc += l.b < r.b; rc += r.b < l.b;
	lc += l.c < r.c; rc += r.c < l.c;
	lc += l.d < r.d; rc += r.d < l.d;
	lc += l.e < r.e; rc += r.e < l.e;
	if ( lc > 2 && lc > rc ) return 1;
	if ( rc > 2 && rc > lc ) return 2;
	return -1;
}

void solve ()
{
	int n; scanf ( "%d", &n );
	for ( int i = 0 ; i < n ; ++i ) {
		scanf ( "%d%d%d%d%d", &v[i].a, &v[i].b, &v[i].c, &v[i].d, &v[i].e );
	}
	int ind = 0;
	for ( int i = 1 ; i < n ; ++i ) {
		int res = cmp ( v[ind], v[i] );
		if ( res == 2 ) ind = i;
	}
	debug() << imie(ind);
	debug() << imie(v[ind]);
	for ( int i = 0 ; i < n ; ++i ) {
		if ( i == ind ) continue;
		if ( cmp ( v[ind], v[i] ) != 1 ) {
			puts ( "-1" );
			return;
		}
	}
	printf ( "%d\n", ind+1 );
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

