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

string read_string ( void )
{
	static char ch[1000005];
	scanf ( "%s", ch );
	return string ( ch );
}

using ll = long long int;

int n;
ll ans;
pair<int,int> l, r;
vector<pair<int,int>> vp;
vector<pair<int,int>> nvp;

void nope ()
{
	puts ( "-1" );
	return;
}

inline void solve ( int _case )
{
	(void) _case;
	scanf ( "%d", &n );
	vp.clear();
	int t;
	for ( int i = 0 ; i < n ; ++i ) {
		scanf ( "%d", &t );
		vp.eb ( t, t );
	}
	ans = 0;
	while ( vp.size() > 1 ) {
		nvp.clear();
		int csz = int(vp.size());
		for ( int i = 0 ; i < csz ; i += 2 ) {
			l = vp[i];
			r = vp[i+1];
			if ( l > r ) {
				++ans;
				swap ( l, r );
			}
			if ( l.S > r.F ) return nope();
			if ( r.F < l.S ) return nope();
			nvp.eb ( l.F, r.S );
		}
		vp = nvp;
	}
	printf ( "%lld\n", ans );
}

int main ( void )
{
	int _t = 1;
	scanf ( "%d" , &_t );
	for ( int i = 0 ; i < _t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ( i+1 );
	}


	return 0;
}

