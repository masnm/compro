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

vector<int> a, b, va, vb;
int n, m;

void solve ()
{
	scanf ( "%d", &n ); a.resize(n);
	for ( int& i : a ) scanf ( "%d", &i );
	scanf ( "%d", &m ); b.resize(m);
	for ( int& i : b ) scanf ( "%d", &i );
	sort ( a.begin(), a.end() ); sort ( b.begin(), b.end() );
	va.assign ( n, 0 ); vb.assign ( m, 0 );
	int ind = -1;
	for ( int x : a ) {
		++ind;
		for ( int i = 1 ; i <= 100 ; ++i ) {
			if ( x*i > 100 ) break;
			auto src = lower_bound ( b.begin(), b.end(), x*i );
			if ( src != b.end() && *src == x*i ) {
				va[ind] = 1;
				vb[src-b.begin()] = 1;
			}
		}
	}
	printf ( "%d\n", min ( accumulate(va.begin(), va.end(),0), accumulate(vb.begin(), vb.end(), 0)));
}

int main ()
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}
