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

ll n, k, a, b;

void odd ()
{
	b = k / ( n / 2LL );
	debug() << imie(b);
	printf ( "%lld\n", a );
}

void even ()
{
	a = k % n;
	if ( a == 0 ) a = n;
	printf ( "%lld\n", a );
}

void solve ()
{
	scanf ( "%lld%lld", &n, &k );
	if ( n & 1LL ) odd ();
	else even ();
}

int main ()
{
	n = 5;
	a = n, b = 1; int cnt = 0;
	for ( int i = 1 ; i < 100 ; ++i ) {
		if ( a == b ) {
			cerr << b << " ";
			++cnt;
			++b;
			if ( b == n + 1 ) b = 1;
		}
		--a; ++b;
		if ( a == 0 ) a = n;
		if ( b == n + 1 ) b = 1;
		if ( i % n == 0 ) debug() << imie(i/n) imie(cnt);
	}
	return 0;

	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

