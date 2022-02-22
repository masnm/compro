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
	static char ch[1005];
	scanf ( "%s", ch );
	return string ( ch );
}

struct FenwickTree {
	int n;
	vector<int> tree;
	FenwickTree ()
	{
		n = 1005;
		tree.assign ( n, 0 );
	}
	void init ( string s )
	{
		for ( int i = 0 ; i < (int)s.length() ; ++i ) {
			int ind = i + 1, val = (s[i] == '*' ? 1 : 0);
			for ( ; ind < n ; ind += ( ind & -ind ) )
				tree[ind] += val;
		}
	}
	int sum ( int r )
	{
		int s = 0;
		for ( ; r > 0 ; r -= ( r & -r ) )
			s += tree[r];
		return s;
	}
};

const int nax = 1005;
int _n, q, a, b, c, d;
vector<FenwickTree> vf(nax);

int main ()
{
	scanf ( "%d%d", &_n, &q );
	string s;
	for ( int i = 0 ; i < _n ; ++i ) {
		s = read_string ();
		vf[i].init(s);
	}
	for ( int i = 0 ; i < q ; ++i ) {
		scanf ( "%d%d%d%d", &a, &b, &c, &d );
		ll ans = 0;
		--c; --a;
		while ( c >= a ) {
			ans += vf[c].sum(d) - vf[c].sum(b-1);
			--c;
		}
		printf ( "%lld\n", ans );
	}
	return 0;
}

