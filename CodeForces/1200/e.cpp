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

const int limit = 200005;

void solve ()
{
	int n, ans = limit, cnt = 0;
	scanf ( "%d", &n );
	queue<vector<int>> qvi;
	vector<int> v( 2*n + 2 ), t( 2*n + 2 );
	for ( int i = 2 ; i < 2*n + 2 ; ++i ) scanf ( "%d", &v[i] );
	v[0] = 0; v[1] = 0;
	qvi.push ( v );
	while ( ++cnt < limit ) {
		if ( is_sorted ( qvi.front().begin() + 2 , qvi.front().end() ) ) {
			ans = min ( ans, qvi.front()[0] );
		}
		if ( qvi.front()[1] != 1 ) {
			t = qvi.front();
			t[0] = qvi.front()[0] + 1;
			t[1] = 1;
			for ( int i = 2 ; i < 2*n + 2 ; i += 2 ) {
				swap ( t[i], t[i+1] );
			}
			qvi.push ( t );
		}
		if ( qvi.front()[1] != 2 ) {
			t = qvi.front();
			t[0] = qvi.front()[0] + 1;
			t[1] = 2;
			for ( int i = 2 ; i < n + 2 ; ++i ) {
				swap ( t[i], t[n+i] );
			}
			qvi.push ( t );
		}
		qvi.pop();
	}
	printf ( "%d\n", ans == limit ? -1 : ans );
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

