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

const int nax = 35;
vector<int> mg(nax), pig[nax];
int n, s, e;
char ch[5];

void merger ()
{
	int gs = mg[s], ge = mg[e];
	if (gs == ge) return;
	if ( pig[gs].size() < pig[ge].size() ) swap ( gs, ge );
	for ( int& i : pig[ge] ) {
		mg[i] = gs;
		pig[gs].eb(i);
	}
	pig[ge].clear();
}

void solve ()
{
	for ( int i = 0 ; i < nax ; ++i ) mg[i] = i;
	for ( int i = 0 ; i < nax ; ++i ) pig[i].clear(), pig[i].eb(i);

	while ( scanf ( "%c", &ch[0] ) != EOF ) {
		if ( ch[0] == '\n' ) break;
		else scanf ( "%c%c", &ch[1], &ch[2] );
//		printf ( "%c%c\n", ch[0], ch[1] );
		s = ch[0] - 'A';
		e = ch[1] - 'A';
		merger ();
	}
	int ans = 0;
	for ( int i = 0 ; i < n ; ++i ) ans += ( pig[i].size() > 0 ? 1 : 0 );
//	for ( int i = 0 ; i < n ; ++i ) debug() << imie(pig[i]);
	printf ( "%d\n", ans );
}

int main ()
{
	int t = 1;
	scanf ( "%d", &t );
	for ( int i = 0 ; i < t ; ++i ) {
		if ( i == 0 ) scanf ( "%c%c", &ch[0], &ch[1] );
		scanf ( "%c\n", &ch[0] );
		n = ch[0] - 'A';
//		printf ( "Case %d: ", i+1 );
		solve ();
		if ( i != t-1 ) puts("");
	}


	return 0;
}

