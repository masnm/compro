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
ll ar[nax], t, mx;
int n, q;

void solve ()
{
	scanf ( "%d", &n );
	priority_queue<pair<ll,int>> pq;
	for ( int i = 0 ; i < n ; ++i ) {
		scanf ( "%lld", &t );
		pq.push ( { t, i } );
	}
	scanf ( "%d", &q );
	scanf ( "%lld", &t );
	mx = t;
	pair<ll,int> pr;
	while ( pq.top().F >= mx ) {
		pr = pq.top();
		pq.pop();
		pr.F %= mx;
		pq.push ( pr );
	}
	for ( int i = 1 ; i < q ; ++i ) {
		scanf ( "%lld", &t );
		mx = t;
		while ( pq.top().F >= mx ) {
			pr = pq.top();
			pq.pop();
			pr.F %= mx;
			pq.push ( pr );
		}
	}
	while ( !pq.empty() ) {
		pr = pq.top(); pq.pop();
		ar[pr.S] = pr.F;
	}
	for ( int i = 0 ; i < n ; ++i ) {
		if ( i != 0 ) printf ( " " );
		printf ( "%lld", ar[i] );
	}
}

int main ()
{
	int tt = 1;
	scanf ( "%d" , &tt );
	for ( int i = 0 ; i < tt ; ++i ) {
		if ( i != 0 ) printf ( "\n" );
		printf ( "Case %d:\n", i+1 );
		solve ();
	}


	return 0;
}

