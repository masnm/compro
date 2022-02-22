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

bool test ( ll a, ll b, ll c )
{
	if ( b - a == c - b ) return true;
	ll dif, tar;
	// making a
	dif = c - b; tar = b - dif;
	if ( tar >= a && tar % a == 0 )
		return true;
	// making c
	dif = b - a; tar = b + dif;
	if ( tar >= c && tar % c == 0 )
		return true;
	// making b
	tar = ((c - a) / 2) + a;
	debug() << imie(a) imie(b) imie(c) imie(tar);
	if ( tar>=a&&tar<=c && (tar - a == c - tar) && (tar >= b) && (tar%b == 0 ) )
		return true;
	return false;
}

void solve ()
{
	ll a, b, c;
	scanf ( "%lld%lld%lld", &a, &b, &c );
	bool ans = test ( a, b, c );
	if ( ans ) { puts ( "YES" ); return; }
	swap ( a, c );
	ans = test ( a, b, c );
	if ( ans ) { puts ( "YES" ); return; }
	puts ( "NO" );
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

