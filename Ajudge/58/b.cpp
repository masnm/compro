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

string read_string ()
{
	static char ch[1000005];
	scanf ( "%s", ch );
	return string ( ch );
}

using ll = long long int;

int n;
vector<int> v;

bool test ( ll k )
{
	int ini = 0;
	for ( int i = 0 ; i < n ; ++i ) {
		if ( v[i] - ini > k ) return false;
		if ( v[i] - ini == k ) k--;
	}
	return true;
}

void solve ()
{
	scanf ( "%d", &n );
	v.resize ( n );
	for ( auto& i : v ) scanf ( "%d", &i );
	for ( int i = n - 1 ; i > 0 ; --i )
		v[i] = v[i] - v[i - 1];
	ll mid, low = 1, high = 100000000000000005L;
	while ( low < high ) {
		mid = low + ( high - low ) / 2LL;
		if ( test ( mid ) ) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	printf ( "%lld\n", low );
}

int main ( int argc, char* argv[] )
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

