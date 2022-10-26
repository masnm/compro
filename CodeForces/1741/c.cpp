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
vector<ll> v;

ll get_ans ( int ind )
{
	int ans = ind + 1;
	ll tars = 0;
	for ( int i = 0 ; i < ind + 1 ; ++i ) tars += v[i];
	int st = ind + 1;
	ll ts = 0;
	for ( int i = st ; i < n ; ++i ) {
		ts += v[i];
		if ( ts == tars ) {
			ans = max ( ans, i - st + 1 );
			st = i + 1;
			ts = 0;
		} else if ( ts > tars ) {
			return LLONG_MAX;
		}
	}
	if ( ts != 0 ) return LLONG_MAX;
	return ans;
}

inline void solve ( int _case )
{
	scanf ( "%d", &n );
	v.resize ( n );
	for ( auto& i : v ) scanf ( "%lld", &i );
	ll ans = LLONG_MAX;
	for ( int i = 0 ; i < n ; ++i ) {
		ans = min ( ans, get_ans ( i ) );
	}
	printf ( "%lld\n", ans==LLONG_MAX?n:ans );
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

