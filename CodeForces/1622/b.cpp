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

void solve ()
{
	int n; scanf ( "%d", &n );
	vector<int> v ( n );
	for ( auto& i : v ) scanf ( "%d", &i );
	string s = read_string ();
	vector<pair<int,int>> nu, up;
	for ( int i = 0 ; i < n ; ++i ) {
		if ( s[i] == '1' )
			up.eb ( v[i], i );
		else
			nu.eb ( v[i], i );
	}
	sort ( up.begin(), up.end() );
	sort ( nu.begin(), nu.end() );
	int start = 1;
	for ( auto& i : nu ) i.F = start++;
	for ( auto& i : up ) i.F = start++;
	sort ( up.begin(), up.end(), [](auto& i, auto& j) {
			return tie(i.S,i.F) < tie(j.S,j.F); } );
	sort ( nu.begin(), nu.end(), [](auto& i, auto& j) {
			return tie(i.S,i.F) < tie(j.S,j.F); } );
	up.insert ( up.end(), nu.begin(), nu.end() );
	sort ( up.begin(), up.end(), [](auto& i, auto& j) {
		return tie(i.S,i.F) < tie(j.S,j.F); } );
	for ( auto i : up ) {
		printf ( "%d ", i.F );
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

