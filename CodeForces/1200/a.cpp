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

bool ar[105];

void solve ()
{
	int n;
	scanf ( "%d", &n );
	int a, b, c;
	scanf ( "%d%d%d", &a, &b, &c );
	string ss = read_string();
	int r = 0, p = 0, s = 0;
	for ( const char& ch : ss ) {
		if ( ch == 'R' ) ++r;
		else if ( ch == 'P' ) ++p;
		else ++s;
	}
	int win = 0, wina = 0, winb = 0, winc = 0;
	wina = min ( a, s );
	winb = min ( b, r );
	winc = min ( c, p );
	a -= wina;
	b -= winb;
	c -= winc;
	win = wina + winb + winc;
	if ( win >= ((n+1)/2) ) {
		for ( int i = 0 ; i < n + 2 ; ++i ) ar[i] = false;
		int idx = 0;
		for ( char& ch : ss ) {
			if ( ch == 'R' && winb > 0 ) {
				ar[idx] = true;
				-- winb;
				ch = 'P';
			} else if ( ch == 'P' && winc > 0 ) {
				ar[idx] = true;
				-- winc;
				ch = 'S';
			} else if ( ch == 'S' && wina > 0 ) {
				ar[idx] = true;
				-- wina;
				ch = 'R';
			}
			++idx;
		}
		idx = 0;
		for ( char& ch : ss ) {
			if ( !ar[idx] ) {
				if ( a > 0 ) {
					--a;
					ch = 'R';
				} else if ( b > 0 ) {
					--b;
					ch = 'P';
				} else {
					--c;
					ch = 'S';
				}
			}
			++idx;
		}
		puts ( "YES" );
		puts ( ss.c_str() );
	} else {
		puts ( "NO" );
	}
}

int main ()
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

