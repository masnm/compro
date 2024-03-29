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

void solve ()
{
	int n, k, t, tc = 0;
	scanf ( "%d%d", &n, &k );
	vector<int> v ( n ), w ( n, 0 );
	for ( int i = 0 ; i < n ; ++i ) scanf ( "%d", &v[i] );
	for ( int i = 0 ; i < n ; ++i ) {
		scanf ( "%d", &t );
		if ( t == 0 ) w[i] = v[i];
		else tc += v[i];
	}
	int sum = 0, mx = INT_MIN;
	for ( int i = 0 ; i < k ; ++i ) sum += w[i];
	mx = max ( mx, sum );
	for ( int i = k ; i < n ; ++i ) {
		sum += w[i];
		sum -= w[i-k];
		mx = max ( mx, sum );
	}
	printf ( "%d\n", mx + tc );
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

