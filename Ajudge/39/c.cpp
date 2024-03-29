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

const int nax = 100005;
const int inf = 1000000007;
bool v[nax];
int ans[nax];

void solve ()
{
	for ( int i = 0 ; i < nax ; ++i ) ans[i] = inf;
	int s, e, n;
	scanf ( "%d%d", &s, &e );
	ans[s] = 0;
	v[s] = true;
	queue<int> q;
	q.push ( s );
	while ( !q.empty() ) {
		int cp = q.front(); q.pop();
		if ( cp == e ) break;
		n = cp * 2;
		if ( n < nax && !v[n] ) {
			v[n] = true;
			ans[n] = ans[cp] + 1;
			q.push(n);
		}
		n = cp - 1;
		if ( n > -1 && !v[n] ) {
			v[n] = true;
			ans[n] = ans[cp] + 1;
			q.push(n);
		}
	}
	printf ( "%d\n", ans[e] );
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

