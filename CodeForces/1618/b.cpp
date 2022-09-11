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
vector<string> vs;

void solve ()
{
	scanf ( "%d", &n );
	vs.resize ( n - 2 );
	for ( auto& i : vs ) i = read_string ();
	string prev = vs[0];
	bool found = false;
	for ( int i = 1 ; i < n - 2 ; ++i ) {
		if ( prev[1] != vs[i][0] ) {
			found = true;
			string s = ""; s += prev[1]; s += vs[i][0];
			vs.insert ( vs.begin()+i, s );
			break;
		}
		prev = vs[i];
	}
	debug() << imie(found);
	debug() << imie(vs);
	if ( !found ) {
		string s = vs.end()[-1];
		reverse ( s.begin(), s.end() );
		vs.eb ( s );
		for ( auto& i : vs ) printf ( "%c", i[0] );
		printf ( "%c\n", vs.end()[-1][1] );
	} else {
		for ( auto& i : vs ) printf ( "%c", i[0] );
		printf ( "%c\n", vs.end()[-1][1] );
	}
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

