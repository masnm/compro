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

const vector<pair<int,int>> vp {
	{ -1, -1 }, { -1, 0 }, { -1, 1 },
	{ 0, 1 }, { 1, 1 }, { 1, 0 },
	{ 1, -1 }, { 0, -1 }
};

int n, m, q, qr, qc, ih, nx, ny;
vector<vector<int>> mp;

int main ( void )
{
	scanf ( "%d%d", &n, &m );
	mp.resize ( n );
	for ( auto& i : mp ) i.resize ( m );
	for ( auto& i : mp )
		for ( auto& j : i )
			scanf ( "%d", &j );
	scanf ( "%d", &q );
	while ( q-- ) {
		scanf ( "%d%d", &qr, &qc );
		ih = mp[qr][qc-1];
		for ( auto i : vp ) {
			nx = qr + i.F;
			ny = qc + i.S;
			swap ( ih, mp[nx][ny] );
		}
		for ( auto& i : mp ) {
			for ( auto& j : i ) {
				printf ( "%d ", j );
			}
			printf ( "\n" );
		}
	}

	return 0;
}

