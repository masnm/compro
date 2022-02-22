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

map<int,int> mp;
vector<int> ar(50, -1);

ll calculate ( int i ) {
	if ( i < 1 )
		assert(false);
	else if ( ar[i] != -1 )
		return ar[i];
	else if ( i & 1 ) {
		int dv = i / 2;
		ar[i] = calculate(dv)*calculate(dv+1)+2;
		return ar[i];
	} else {
		int dv = i / 2;
		ar[i] = calculate(dv)*calculate(dv)+1;
		return ar[i];
	}
}

void pre ()
{
	ar[1] = 1;
	for ( int i = 1 ; i < 50 ; ++i )
		calculate(i);
}

void solve ()
{
	int n;
	scanf("%d", &n );
	for ( int i = 1 ; i < 50 ; ++i ) {
		if ( ar[i] == n ) {
			printf("%d\n", i );
			return;
		}
	}
	assert(false);
}

int main ()
{
	pre();
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

