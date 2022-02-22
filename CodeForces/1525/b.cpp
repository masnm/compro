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

const int nax = 55;
vector<int> v(nax);
int n;

void solve ()
{
	scanf ( "%d", &n );
	for ( int i = 0 ; i < n ; ++i )
		scanf ( "%d", &v[i] );
	bool is = is_sorted ( v.begin(), v.begin()+n );
	if ( is ) {
		puts ( "0" );
		return;
	}
	if ( v[0] == 1 && v[n-1] == n ) {
		puts ( "1" );
	} else if ( v[0] == n && v[n-1] == 1 ) {
		puts ( "3" );
	} else if ( v[0] == n || v[n-1] == 1 ) {
		puts ( "2" );
	} else if ( v[0] == 1 || v[n-1] == n ) {
		puts ( "1" );
	} else {
		puts ( "2" );
	}
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

