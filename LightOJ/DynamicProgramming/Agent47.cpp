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
	static char ch[20];
	scanf ( "%s", ch );
	return string ( ch );
}

string strget ( int n )
{
	string s = "";
	for ( int i = 0 ; i < n ; ++i )
		s += '1';
	return s;
}

struct tpl {
	int a, b;
	string s;
	tpl () : a(0), b(0), s("") {}
	tpl ( int _a, int _b, string _s ) :
		a(_a), b(_b), s(_s) {}
};
debug & operator << (debug & dd, tpl p) {
	dd << "(" << p.a << ", " << p.b << ", " << p.s << ")"; return dd;
}

void solve ()
{
	const int INF = 1e9;
	int n; scanf ( "%d", &n );
	vector<int> health ( n );
	for ( int& i : health ) scanf ( "%d", &i );
	vector<string> damage ( n );
	for ( auto& i : damage ) i = read_string ();
	vector<tpl> fst;
	fst.eb ( tpl{ 0, 0, strget(n) } );
	vector<pair<int,string>> snd;
	for ( int i = 0 ; i < n ; ++i ) {
		snd.resize ( 1<<n );
		for ( int j = 0 ; j < (1<<n) ; ++j ) snd[j].F = INF;
		for ( int j = 0 ; j < n ; ++j ) {
			int ind = (1<<j);
			for ( auto item : fst ) {
				if ( (item.a & ind) == 0 ) {
					int nind = item.a | ind;
					int nval = item.b + (health[j]/int(item.s[j]-'0')) + (health[j]%int(item.s[j]-'0')==0?0:1);
					if ( snd[nind].F > nval ) {
						snd[nind].F = nval;
						snd[nind].S = item.s;
						for ( int x = 0 ; x < n ; ++x )
							snd[nind].S[x] = max ( snd[nind].S[x], damage[j][x] );
					}
				}
			}
		}
		fst.clear();
		for ( int j = 0 ; j < (1<<n) ; ++j )
			if ( snd[j].F != INF ) {
				fst.eb ( tpl{ j, snd[j].F, snd[j].S } );
			}
	}
	printf ( "%d\n", fst.back().b );
}

int main ()
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

