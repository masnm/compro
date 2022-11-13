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

string read_string ( void )
{
	static char ch[1000005];
	scanf ( "%s", ch );
	return string ( ch );
}

using ll = long long int;

vector<string> vs(9), bvs;
vector<bool> fine(4);

bool ok ( int tr, int tc, int br, int bc )
{
	bool what = true;
	for ( int i = tr + 1 ; i < br ; ++i ) {
		for ( int j = tc + 1 ; j < bc ; ++j ) {
			if ( vs[i][j] == '#' ) {
				what = false;
				break;
			}
		}
		if ( !what ) break;
	}
	if ( !what ) return false;
	int trc = 0, brc = 0, lcc = 0, rcc = 0;
	for ( int i = tr ; i <= br ; ++i )
		if ( vs[i][tc] == '#' ) {
			vs[i][tc] = '.';
			++ lcc;
			break;
		}
	for ( int i = tc ; i <= bc ; ++i )
		if ( vs[tr][i] == '#' ) {
			vs[tr][i] = '.';
			++trc;
			break;
		}
	for ( int i = tr ; i <= br ; ++i )
		if ( vs[i][bc] == '#' ) {
			vs[i][bc] = '.';
			++ rcc;
			break;
		}
	for ( int i = tc ; i <= bc ; ++i )
		if ( vs[br][i] == '#' ) {
			vs[br][i] = '.';
			++brc;
			break;
		}
	if ( trc == 1 && brc == 1 && lcc == 1 && rcc == 1 ) {
		return true;
	}
	return false;
}

inline void solve ( int _case )
{
	for ( auto& i : vs ) i = read_string ();
	int ans = 0;
	for ( int i = 0 ; i < 9 ; ++i ) {
		for ( int j = 0 ; j < 9 ; ++j ) {
			for ( int x = 1 ; x < 9 ; ++x ) {
				if ( x + i >= 9 || x + j >= 9 ) break;
				bvs = vs;
				if ( ok ( i, j, i+x, j+x ) ) {
					++ans;
				}
				vs = bvs;
			}
		}
	}
	printf ( "%d\n", ans );
}

int main ( void )
{
	int _t = 1;
//	scanf ( "%d" , &_t );
	for ( int i = 0 ; i < _t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ( i+1 );
	}


	return 0;
}

