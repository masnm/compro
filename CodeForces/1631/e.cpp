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

int n;
vector<int> ar, v;

void simulate ()
{
	for ( int i = 0, j = 1, k = 2 ; k < n ; ++i, ++j, ++k ) {
		if ( v[i] == v[j] && v[i] == v[k] && v[i] == 0 &&
			ar[i] == ar[k] )
			v[j] = 1;
	}
}

void solve ()
{
	scanf ( "%d", &n );
	ar.assign(n,0);
	v.assign(n,0);
	for ( int i = 0 ; i < n ; ++i ) scanf ( "%d", &ar[i] );
	for ( int i = 0 ; i < 20 ; ++i ) simulate ();
	int sum = 0;
	for ( int i = 0 ; i < n ; ++i ) sum += v[i];
	printf ( "%d\n", sum );
	debug() << imie(ar);
	debug() << imie(v);
}

int main ()
{
	int t = 1;
//	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

