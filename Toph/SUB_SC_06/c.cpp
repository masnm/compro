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
	static char ch[25];
	scanf ( "%s", ch );
	return string ( ch );
}

string get_sec ( char a, char b )
{
	if ( a == '1' && b == '1' ) return "MPE";
	else if ( a == '1' && b == '2' ) return "MPE";
	else if ( a == '2' && b == '1' ) return "EEE";
	else if ( a == '3' && b == '1' ) return "TVE";
	else if ( a == '4' && b == '1' ) return "CSE";
	else if ( a == '4' && b == '2' ) return "CSE";
	else if ( a == '5' && b == '1' ) return "CEE";
	else if ( a == '6' && b == '1' ) return "BTM";
	else assert(false);
}

void solve ()
{
	string nm = read_string(), rol = read_string();
	printf ( "Name: %s\n", nm.c_str() );
	printf ( "Student id: %s\n", rol.c_str() );
	printf ( "Batch: 20%c%c\n", rol[0],rol[1] );
	printf ( "Department: %s\n", get_sec(rol[4],rol[5]).c_str() );
	printf ( "Section: %c\n", rol[6] );
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

