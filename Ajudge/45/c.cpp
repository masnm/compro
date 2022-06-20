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
	static char ch[400005];
	scanf ( "%s", ch );
	return string ( ch );
}

int main ()
{
	int n, k, sum = 0; scanf ( "%d%d", &n, &k );
	string in = read_string ();
	vector<int> occ ( 130, 0 );
	for ( auto i : in ) occ[int(i)]++, sum++;
	int ind = int('a'), end = int('z');
	assert ( sum >= k );
	while ( k-- ) {
		if ( occ[ind] > 0 ) {
			--occ[ind];
		} else {
			while ( occ[ind] <= 0 ) { assert ( ind <= end ); ++ind; };
			--occ[ind];
		}
	}
	reverse ( in.begin(), in.end() );
	string ans;
	for ( auto i : in ) {
		if ( occ[int(i)] > 0 ) {
			--occ[int(i)];
			ans += i;
		}
	}
	reverse ( ans.begin(), ans.end() );
	printf ( "%s\n", ans.c_str() );


	return 0;
}

