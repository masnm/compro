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

using ll = long long int;
string read_string ()
{
	static char ch[200005];
	scanf ( "%s", ch );
	return string ( ch );
}

bool ok ( const string& s )
{
	int b = 0;
	for ( char c : s ) {
		c == ')' ? --b : ++b;
		if ( b < 0 ) return false;
	}
	return b==0;
}

void shrink ( vector<int>& v, string& s )
{
	int len = v.size();
	int start = 1;
	vector<pair<int,int>> vp;
	while ( true ) {
		int pos = -1, pos2 = -1;
		for ( int i = start ; i < len ; ++i ) {
			if ( v[i] == 0 ) { pos = i; break; }
		}
		if ( pos == -1 ) break;
		for ( int i = pos+1 ; i < len ; ++i ) {
			if ( v[i] == 0 ) { pos2 = i; break; }
		}
		if ( pos2 == -1 ) break;
		vp.emplace_back(pos, pos2);
		start = pos2+1;
	}
	debug() << imie(vp.size() );
	reverse ( vp.begin(), vp.end() );
	for ( pair<int,int>& p : vp ) {
		debug() << imie(p.first) imie(p.second);
		s.erase ( p.first-1, p.second-p.first );
	}
}

void build ( vector<int>& v, string& s )
{
	int b = 0;
	v.clear();
	v.emplace_back(0);
	for ( char c : s ) {
		c == ')' ? --b : ++b;
		v.emplace_back(b);
	}
}

void solve()
{
	vector<int> v;
	string s = read_string();
	build ( v, s );
	shrink ( v, s );
	build ( v, s );
	int pos = -1;
	int mn = INT_MAX;
	for ( int i = 0 ; i < (int)v.size() ; ++i ) {
		if ( v[i] < mn ) {
			mn = v[i];
			pos = i;
		}
	}
	if ( pos != 0 ) {
		string ss = "";
		for ( int i = 0 ; i < pos ; ++i ) {
			ss += s[i];
		}
		s.erase(0, pos);
		s += ss;
	}
	bool fa = ok(s);
	if ( fa ) {
		printf ( "%d\n", min ( pos, (int)s.length()-pos ) );
	} else {
		puts ( "impossible" );
	}
	debug() << imie(s) imie(fa) imie(pos) imie(v);
}

int main ()
{
/*   /\
 * \/  \
 *      \
 */

	int t;
	scanf ( "%d" , &t );
	int i = 0;
	while ( t-- ) {
		printf ( "Case %d: ", ++i );
		solve();
	}

	return 0;
}

