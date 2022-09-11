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

int n;
string s, ns, sl, sr;
vector<int> v, poses;

void fill_v ( void )
{
	int _b = 0;
	for ( int i = 0 ; i < n ; ++i ) {
		if ( s[i] == '(' ) ++_b;
		else --_b;
		v[i] = _b;
	}
}

void set_min_pos ( void )
{
	int mn = *min_element ( v.begin(), v.end() );
	for ( int i = 0 ; i < n ; ++i ) if ( v[i] == mn ) poses.eb ( i );
}

bool is_balanced ( void )
{
	int _b = 0;
	for ( int i = 0 ; i < n ; ++i ) {
		if ( ns[i] == '(' ) ++_b;
		else --_b;
		if ( _b < 0 ) return false;
	}
	return _b == 0;
}

int get_ans ( void )
{
	ns = s;
	if ( is_balanced() ) return 0;
	int ans = INT_MAX;
	for ( int pos : poses ) {
		sl = s.substr(0, pos+1);
		sr = s.substr(pos+1);
		ns = sr + sl;
		if ( is_balanced() ) {
			ans = min ( ans, pos + 1 );
			ans = min ( ans, n - ( pos + 1 ) );
		}
	}
	return ans;
}

void solve ()
{
	s = read_string();
	n = s.length();
	v.resize ( n );
	fill_v ();
	poses.clear();
	set_min_pos ();
	int ans = get_ans ();
	debug() << imie(s);
	if ( ans == INT_MAX ) puts ( "impossible" );
	else printf ( "%d\n", ans );
}

int main ( int argc, char* argv[] )
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

