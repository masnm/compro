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

constexpr const int nax = 10000005;
constexpr const ll sq = ll(sqrt(double(nax))) + 5,
		  dsq = ll(sqrt(sqrt(double(nax)))) + 5;
bool b[nax], v[nax];
// bitset<nax> b, v;
vector<int> ans ( nax, 0 );
ll ti;

void pre ()
{
	b[0] = b[1] = true;
	for ( int i = 2 ; i * i < nax ; ++i )
		if ( !b[i] )
			for ( int j = i * i ; j < nax ; j += i )
				b[j] = true;
	for ( int i = 0 ; i < sq ; ++i ) {
		for ( int j = 0 ; j < dsq ; ++j ) {
			ti = (i*i) + (j*j*j*j);
			if ( ti < nax ) v[ti] = true;
		}
	}
	int cnt = 0;
	for ( int i = 0 ; i < nax ; ++i ) {
		if ( (!b[i] == v[i]) && v[i] == true )
			++cnt;
		ans[i] = cnt;
	}
}

void solve ()
{
	int n;
	scanf ( "%d", &n );
	printf ( "%d\n", ans[n] );
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

