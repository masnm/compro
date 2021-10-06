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
string read_string ()
{
	static char ch[105];
	scanf ( "%s", ch );
	return string ( ch );
}

void solve ()
{
	int n;
	scanf ( "%d", &n );
	string s = read_string ();
	bool ans = false;
	for ( int i = 0 ; i < n - 4 ; ++i ) {
		for ( int j = i + 1 ; j < n - 3 ; ++j ) {
			for ( int k = j + 1 ; k < n - 2 ; ++k ) {
				for ( int l = k + 1 ; l < n - 1 ; ++l ) {
					for ( int m = l + 1 ; m < n - 0 ; ++m ) {
						if ( j-i==k-j && k-j==l-k && l-k==m-l ) {
							if ( s[i]=='*'&&s[j]=='*'&&s[k]=='*'&&s[l]=='*'&&s[m]=='*' ) {
								ans = true;
							}
						}
					}
				}
			}
		}
	}
	if ( ans ) puts ( "yes" );
	else puts ( "no" );
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

