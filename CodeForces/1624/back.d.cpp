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
string read_string ()
{
	static char ch[200005];
	scanf ( "%s", ch );
	return string ( ch );
}

void solve ()
{
	ll n, k; scanf ( "%lld%lld", &n, &k );
	vector<ll> v ( 27, 0 );
	string s = read_string ();
	for ( char c : s ) ++v[int(c-'a')];
	ll sum = 0;
	for ( ll& i : v ) {
		if ( i & 1LL ) {
			sum += i - 1; i = 1;
		} else {
			sum += i; i = 0;
		}
	}
	ll ars = accumulate ( v.begin(), v.end(), 0 );
	ll ans = sum/k;
	if ( ars >= k && !(ans&1LL) ) ++ans;
	ans = max ( ans, 1LL );
	printf ( "%lld\n", ans );
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

