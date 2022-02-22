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
using ll = long long int;

int main ()
{
	int n, m, t;
	scanf ( "%d%d", &n, &m );
	map<int,int> mp;
	for ( int i = 0 ; i < n ; ++i ) {
		scanf ( "%d", &t );
		++mp[t];
	}
	bool x = false;
	map<int,int>::iterator it = mp.begin(), src;
	for ( int i = 0 ; i < m ; ++i ) {
		x = false;
		scanf ( "%d", &t );
		if ( mp.empty() ) { puts("-1"); continue; }
		src = mp.lower_bound(t);
		if ( src->first > t ) {
			if ( src == it ) {
				puts ( "-1" );
				x = true;
			} else --src;
		}
		if ( !x ) {
			t = src->first;
			printf ( "%d\n", t );
			--mp[t];
			if ( mp[t] == 0 )
				mp.erase(t);
		}
		it = mp.begin();
	}

	return 0;
}
