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
	static char ch[5];
	scanf ( "%s", ch );
	return string ( ch );
}

struct st {
	st () : pri(0LL), vit(vector<bool>(3,false)) {}
	st ( ll _pri, string _vit )
	{
		pri = _pri;
		vit = vector<bool>(3, false);
		for ( char c : _vit ) vit[c-'A'] = true;
	}
	ll pri;
	vector<bool> vit;
};
debug & operator << (debug & dd, st p) { dd << "(" << p.pri << ", " << p.vit[0]<<p.vit[1]<<p.vit[2] << ")"; return dd; }

void solve ()
{
	int n;
	scanf ( "%d", &n );
	vector<st> v ( n );
	for ( int i = 0 ; i < n ; ++i ) {
		ll t; scanf ( "%lld", &t );
		string s = read_string();
		v[i] = st ( t, s );
	}
	vector<st> dp ( n );
	const ll INF = INT_MAX;
	auto get_min = [&v] ( st& in ) {
		for ( st& i : v ) {
			if ( i.vit == in.vit )
				in.pri = min ( in.pri, i.pri );
		}
	};
	st a = st ( INF, "A" ), b = st ( INF, "B" ), c = st ( INF, "C" ),
	   ab = st ( INF, "AB" ), ac = st ( INF, "AC" ), bc = st ( INF, "BC" ),
	   abc = st ( INF, "ABC" );
	get_min ( a ); get_min ( b ); get_min ( c ); get_min ( ab ); get_min ( ac );
	get_min ( bc ); get_min ( abc );
	ll ans = INF;
	ans = min ( abc.pri, ans );
	ans = min ( a.pri + b.pri + c.pri , ans );
	ans = min ( ab.pri + c.pri, ans );
	ans = min ( bc.pri + a.pri, ans );
	ans = min ( ac.pri + b.pri, ans );
	ans = min ( ac.pri + bc.pri, ans );
	ans = min ( ab.pri + ac.pri, ans );
	ans = min ( ab.pri + bc.pri, ans );
	printf ( "%lld\n", ans==INF?-1:ans );
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

