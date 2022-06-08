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

int n, N;
vector<int> par;
map<string,int> mp;

bool bfs ( string parent, string child )
{
	if ( mp.find ( parent ) == mp.end() ) return false;
	if ( mp.find ( child ) == mp.end() ) return false;
	int cld = mp.find ( child ) -> S;
	int prn = mp.find ( parent ) -> S;
	while ( true ) {
		if ( cld == -1 ) break;
		if ( cld == prn ) return true;
		cld = par[cld];
	}
	return false;
}

void solve ()
{
	N = 0;
	mp.clear(); mp["Main"] = N++;
	scanf ( "%d", &n );
	par.resize ( n + 1 ); for ( int i = 0 ; i < n + 1 ; ++i ) par[i] = -1;
	while ( n-- ) {
		//debug() << imie(par);
		string op = read_string ();
		if ( op[0] == '+' ) {
			string parent, child;
			parent = read_string(); parent = read_string();
			child = read_string(); child = read_string();
			auto ps = mp.find ( parent ); if ( ps == mp.end() ) mp[parent] = N++;
			auto cs = mp.find ( child ); if ( cs == mp.end() ) mp[child] = N++;
			par[mp.find(parent)->S] = mp.find(child)->S;
		} else if ( op[0] == '?' ) {
			string parent, child;
			parent = read_string();
			child = read_string(); child = read_string(); child = read_string(); child = read_string();
			child.pop_back(); child.pop_back();
			if ( bfs ( parent, child ) ) puts ( "yes" );
			else puts ( "no" );
			//debug() << imie(parent) imie(child);
		} else {
			assert ( false );
		}
	}
	//debug() << imie(mp);
}

int main ()
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
		printf ( "Case %d:\n", i+1 );
		solve ();
	}


	return 0;
}

