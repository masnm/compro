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

string read_string ( void )
{
	static char ch[1000005];
	scanf ( "%s", ch );
	return string ( ch );
}

using ll = long long int;

int n;
vector<int> v, vc;

inline void solve ( int _case )
{
	scanf ( "%d", &n );
	v.resize ( n );
	for ( auto& i : v ) scanf ( "%d", &i );
	if ( is_sorted ( v.begin(), v.end() ) ) {
		debug() << imie(v);
		puts ( "0" );
		return;
	}
	vc = v;
	int l = 0, r = n-1, ans = 0;
	while ( l < r ) {
		while ( r > -1 && v[r] != 0 ) --r;
		while ( l < n && v[l] != 1 ) ++l;
		if ( r < 0 || l == n ) break;
		if ( l > r ) break;
		++ans;
		v[l] = 0; v[r] = 1;
		++l; --r;
	}
	v = vc;
	int ans2 = 0;
	bool fo = false;
	for ( int i = 0 ; i < n ; ++i ) {
		if ( !fo && v[i] == 1 ) fo = true;
		else if ( fo && v[i] == 0 ) {
			++ans2;
		}
	}
	debug() << imie(v);
	debug() << imie(ans) imie(ans2);
	printf ( "%d\n", min ( ans, ans2 ) );
}

int main ( void )
{
	int _t = 1;
	scanf ( "%d" , &_t );
	for ( int i = 0 ; i < _t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ( i+1 );
	}


	return 0;
}

/*


0
0
1
0
0
1
1
1
0
1
2
2
1
2
1
0



 */
