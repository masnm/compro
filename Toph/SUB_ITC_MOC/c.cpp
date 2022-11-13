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

const int nax = 1000005;
bool p[nax];
vector<int> vi, pr;
vector<pair<int,int>> vp;

inline void pre ()
{
	for ( int i = 2 ; i * i < nax ; ++i )
		if ( !p[i] )
			for ( int j = i * i ; j < nax ; j += i )
				p[j] = true;
	for ( int i = 2 ; i < nax ; ++i )
		if ( !p[i] )
			pr.eb ( i );
}

int main ( void )
{
	pre ();
	ll n;
	scanf ( "%lld", &n );
	ll bn = n;
	for ( auto i : pr ) {
		while ( n%i == 0 ) {
			vi.eb ( i );
			n /= i;
		}
	}
	if ( n != 1 ) vi.eb ( n );
	int prev = -1, cnt = 0;
	for ( auto i : vi ) {
		if ( i != prev ) {
			vp.eb ( prev, cnt );
			prev = i;
			cnt = 1;
		} else {
			cnt++;
		}
	}
	vp.eb ( prev, cnt );
	int sz = vp.size ();
	printf ( "%lld = ", bn );
	for ( int i = 0 ; i < sz ; ++i ) {
		if ( i == 0 ) continue;
		if ( i != 1 ) printf ( " * " );
		printf ( "%d ^ %d", vp[i].F, vp[i].S );
	}


	return 0;
}

