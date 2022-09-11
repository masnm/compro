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
vector<int> sz;
vector<string> vs;
unordered_map<string,bool> mp;

void solve ()
{
	scanf ( "%d", &n );
	sz.resize ( n );
	vs.resize ( n );
	for ( auto& i : vs ) i = read_string ();
	sort ( vs.begin(), vs.end(), [](auto& l, auto& r) { return l.size()<r.size(); } );
	for ( int i = 0 ; i < n ; ++i ) sz[i] = vs[i].length();
	sz.resize ( unique ( sz.begin(), sz.end() ) - sz.begin() );
	mp.clear();
	bool ans = true;
	for ( auto& i : vs ) {
		for ( auto j : sz ) {
			if ( j > int(i.length()) ) break;
			auto src = mp.find ( i.substr ( 0, j ) );
			if ( src != mp.end() ) {
				ans = false;
				break;
			}
		}
		if ( !ans ) break;
		mp[i] = true;
	}
	puts ( ans ? "YES" : "NO" );
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

