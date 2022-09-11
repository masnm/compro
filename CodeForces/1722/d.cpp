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

string read_string ()
{
	static char ch[1000005];
	scanf ( "%s", ch );
	return string ( ch );
}

using ll = long long int;

string s;
vector<int> vp;

void solve ()
{
	int n; scanf ( "%d", &n );
	s = read_string ();
	vp.clear();
	char ck = 'L';
	for ( int rep = 0 ; rep < 2 ; ++rep ) {
		for ( int i = 0 ; i < n/2 ; ++i )
			if ( s[i] == ck )
				vp.eb ( i );
		reverse ( s.begin(), s.end() );
		ck = 'R';
	}
	sort ( vp.begin(), vp.end() );
	ll cnt = 0;
	for ( int i = 0 ; i < n ; ++i ) {
		if ( s[i] == 'L' ) cnt += i;
		else cnt += ( n - i - 1 );
	}
	int ind = 0;
	for ( int i = 0 ; i < n ; ++i ) {
		if ( ind < int(vp.size()) ) {
			cnt -= vp[ind];
			cnt += ( n - vp[ind] - 1 );
		}
		printf ( "%lld ", cnt );
		++ind;
	}
	puts ( "" );
}

int main ( int argc, char* argv[] )
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

