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
	static char ch[55];
	scanf ( "%s", ch );
	return string ( ch );
}

void solve ()
{
	int n, m;
	scanf ( "%d%d", &n, &m );
	string f = "face";
	sort ( f.begin(), f.end() );
	vector<string> vs ( n );
	for ( int i = 0 ; i < n ; ++i ) vs[i] = read_string ();
	--n; --m;
	char ch[4];
	bool ok;
	int ans = 0;
	for ( int i = 0 ; i < n ; ++i ) {
		for ( int j = 0 ; j < m ; ++j ) {
			int s = 0;
			for ( int k = i ; k < i + 2 ; ++k ) {
				for ( int l = j ; l < j + 2 ; ++l ) {
					ch[s++] = vs[k][l];
				}
			}
			sort ( ch, ch+4 );
			ok = true;
			for ( int k = 0 ; k < 4 ; ++k ) {
				if ( f[k] != ch[k] ) ok = false;
			}
			if ( ok ) ++ans;
		}
	}
	printf ( "%d\n", ans );
}

int main ()
{
	int t = 1;
//	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

