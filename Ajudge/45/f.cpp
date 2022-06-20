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

const vector<vector<int>> vvi {
	{ 2, 5 },
	{ 5, 0 },
	{ 7, 5 },
	{ 0, 0 }
};

vector<int> pos;
vector<bool> vb(30);
string s;
int ans;

int get_ans ( vector<int> num )
{
	for ( auto& i : num ) {
		i += int('0');
	}
	string gn = s;
	int cnt = 0;
	for ( auto i : num ) {
		for ( auto j : gn ) {
			if ( i == int(j) ) {
				gn.erase ( find ( gn.begin(), gn.end(), char(i) ) );
				cnt ++;
				break;
			}
		}
	}
	if ( cnt != int(num.size()) )
		return INT_MAX;
	gn = s;
	pos.clear();
	reverse ( gn.begin(), gn.end() );
	reverse ( num.begin(), num.end() );
	fill ( vb.begin(), vb.end(), false );
	for ( auto i : num ) {
		for ( int j = 0 ; j < int(gn.size()) ; ++j ) {
			if ( !vb[j] && int(gn[j]) == i ) {
				pos.eb ( j );
				vb[j] = true;
				break;
			}
		}
	}
	sort ( pos.begin(), pos.end() );
	int ta = 0;
	ta += pos[0]-0;
	ta += pos[1]-1;
	debug() << imie(pos);
	debug() << imie(gn);
	for ( auto p : pos ) {
		for ( int i = p ; i > 0 ; --i )
			swap ( gn[i], gn[i-1] );
		debug() << imie(gn);
	}
	debug() << imie("End");
	assert ( gn.back() != '0' );
	return ta;
}

/*
 * 0 1 2 3 4 5
 *   ^   ^
 *   1   2
 */

int main ()
{
	ans = INT_MAX;
	s = read_string ();
	for ( auto item : vvi ) {
		ans = min ( ans, get_ans ( item ) );
	}
	printf ( "%d\n", ans==INT_MAX?-1:ans+1 );

	return 0;
}

