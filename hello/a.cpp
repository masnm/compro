#include "bits/stdc++.h"
using namespace std;

using ll = long long int;

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

int p, c;
const int nax = 1000;

void solve ()
{
	list<int> lst;
	for ( int i = 1 ; i <= min(p, c) ; ++i ) {
		lst.push_back(i);
	}
	char cc, ch[3];
	int l;
	for ( int i = 0 ; i < c ; ++i ) {
		scanf ( "%s", ch );
		cc = ch[0];
		if ( cc == 'N' ) {
			int t = lst.front();
			printf ( "%d\n", lst.front() );
			lst.pop_front();
			lst.push_back(t);
		} else if ( cc == 'E' ) {
			scanf ( "%d", &l );
			lst.remove(l);
			lst.push_front(l);
		} else {
			assert ( false );
		}
	}
}

int main ()
{
	for ( int i = 1 ;  ; ++i ) {
		scanf ( "%d%d", &p, &c );
		if ( p == c && p == 0 ) break;
		printf ( "Case %d:\n", i );
		solve();
	}


	return 0;
}

