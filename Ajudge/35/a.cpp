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

void solve ()
{
	string s;
	cin >> s;
	char mx;
	while ( true ) {
		mx = '0';
		for ( int i = 0 ; i < (int)s.length() ; ++i ) {
			char c = s[i];
			if ( c == '9' && i == 0 ) continue;
			mx = max ( c, mx );
		}
		if ( mx < '5' ) break;
		char mns = '0' + '9' - mx ;
		for ( int i = 0 ; i < (int)s.length() ; ++i ) {
			char c = s[i];
			if ( c == '9' && i == 0 ) continue;
			if ( s[i] == mx ) s[i] = mns;
		}
	}
	while ( *s.begin() == '0' ) s.erase ( 0, 1 );
	assert ( s.length() != 0 );
	printf ( "%s", s.c_str() );
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

