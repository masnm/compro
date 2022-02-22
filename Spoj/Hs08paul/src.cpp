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

const int nax = 200000000;
const int bax = 1e7 + 5;
bitset<nax> b;
vector<int> v ( bax );

void pre ()
{
	b[0] = b[1] = true;
	for ( int i = 2 ; i * i < nax ; ++i )
		if ( !b[i] )
			for ( int j = i * i ; j < nax ; j += i )
				b[j] = true;
	int cnt = 0;
	for ( int i = 0 ; i < nax && cnt < bax ; ++i )
		if ( !b[i] ) {
			v[cnt] = i;
			++cnt;
		}
	debug() << imie(cnt);
}

void solve ()
{
	int n;
	scanf ( "%d", &n );
	printf ( "%d\n", v[--n] );
}

int main ()
{
	pre ();
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

