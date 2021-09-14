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

const ll mod = 1000000007;
ll pr[11];
ll ans = 0, sum;
ll ar[11];
ll tc[11];
ll n, l;

void pre ()
{
	pr[1] = 1;
	for ( ll i = 2 ; i < 11 ; ++i ) {
		pr[i] = pr[i-1] * i;
		pr[i] %= mod;
	}
}

void consider ()
{
	sum = 0;
	for ( int i = 0 ; i < n ; ++i ) sum += tc[i];
	if ( sum == l ) ++ans;
	if ( ans >= mod ) ans -= mod;
}

void recar ( int ssf, int ind )
{
	if ( ssf > l ) return;
	if ( ind == n ) {
		return consider();
	}
	for ( int i = 0 ; i <= ar[ind] ; ++i ) {
		if ( ssf + i > l ) break;
		tc [ ind ] = i;
		recar ( ssf + i, ind + 1 );
	}
}

void solve ()
{
	scanf ( "%lld%lld", &n, &l );
	for ( int i = 0 ; i < n ; ++i ) scanf ( "%lld", &ar[i] );
	recar ( 0, 0 );
	ans *= pr[n];
	ans %= mod;
	printf ( "%lld", ans );
}

int main ()
{
	pre ();
	int t = 1;
//	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

