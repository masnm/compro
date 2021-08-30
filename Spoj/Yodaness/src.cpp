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
// debug & operator << (debug & dd, P p) { dd << imie(p.x) imie(p.y); return dd; }

string read_string ()
{
	static char ch[25];
	scanf ( "%s", ch );
	return string ( ch );
}

using ll = long long;
using ld = long double;

struct BIT {
	vector<ll> bit;
	int n;
	BIT ( int _n ) : n(_n + 1)
	{
		bit.resize(n);
	}
	BIT ( const vector<int>& _v ) : BIT( _v.size() )
	{
		for ( int i = 0 ; i < n ; ++i ) add ( i, _v[i] );
	}
	ll sum ( int r )
	{
		ll ans = 0;
		for ( ++r ; r > 0 ; r -= ( r & (-r) ) ) ans += bit[r];
		return ans;
	}
	ll sum ( int l, int r )
	{
		return sum ( r ) - sum ( l - 1 );
	}
	void add ( int i, ll val )
	{
		for ( ++i ; i < n ; i += ( i & (-i) ) ) bit[i] += val;
	}
};

void solve ()
{
	int n;
	scanf ( "%d", &n );
	vector<string> vi ( n );
	for ( string& i : vi ) i = read_string();
	string ss;
	map<string,int> mp;
	for ( int i = 0 ; i < n ; ++i ) {
		ss = read_string();
		mp[ss] = i;
	}
	vector<int> v ( n );
	for ( int i = 0 ; i < n ; ++i ) v[i] = mp[vi[i]];
	BIT bit ( n );
	ll ans = 0;
	debug() << imie ( v );
	for ( int i = n - 1 ; i > -1 ; --i ) {
		ans += bit.sum ( 0, v[i] );
		bit.add ( v[i], 1 );
		debug() << imie ( ans ) imie ( v[i] );
		debug() << imie ( bit.bit );
		debug() << "";
	}
	debug() << imie(n);
	printf ( "%lld\n", ans );
}

int main ( int argc, char** argv )
{
	int t;
	scanf ( "%d", &t );
	while ( t-- ) solve ();


	puts("");
	return 0;
}
