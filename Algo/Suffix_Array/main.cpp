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

void sort_cyclic_shifts(string const& s) {
	int n = s.size();
	const int alphabet = 256;
	vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
	for (int i = 0; i < n; i++)
		cnt[s[i]]++;
	debug() << imie(p);
	debug() << imie(c);
	for (int i = 1; i < alphabet; i++)
		cnt[i] += cnt[i-1];
	debug() << imie(p);
	debug() << imie(c);
	for (int i = 0; i < n; i++)
		p[--cnt[s[i]]] = i;
	debug() << imie(p);
	debug() << imie(c);
	c[p[0]] = 0;
	int classes = 1;
	for (int i = 1; i < n; i++) {
		if (s[p[i]] != s[p[i-1]])
			classes++;
		c[p[i]] = classes - 1;
	}
	debug() << imie(p);
	debug() << imie(c);
}

inline void solve ( int _case )
{
	(void) _case;
	string s = "abcdabcd";
	sort_cyclic_shifts ( s );
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

