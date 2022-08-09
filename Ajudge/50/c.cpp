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

string read_string ()
{
	static char ch[1000005];
	scanf ( "%s", ch );
	return string ( ch );
}

using ll = long long int;

int n, k, s, e;
vector<int> v;
map<int,pair<int,int>> mp;

void solve ()
{
	mp.clear();
	scanf ( "%d%d", &n, &k );
	v.resize ( n );
	for ( auto& i : v ) scanf ( "%d", &i );
	for ( int i = 0 ; i < n ; ++i ) {
		mp[v[i]] = { i, i };
	}
	for ( int i = 0 ; i < n ; ++i ) {
		pair<int,int>& val = mp[v[i]];
		val.first = min ( val.first, i );
		val.second = max ( val.second, i );
	}
	for ( int kk = 1 ; kk <= k ; ++kk ) {
		scanf ( "%d%d", &s, &e );
		auto ss = mp.find ( s );
		auto se = mp.find ( e );
		if ( ss == mp.end() || se == mp.end() ) {
			puts ( "NO" );
		} else {
			debug() << imie(n) imie(kk);
			debug() << imie(s) imie(e);
			debug() << imie(ss->second);
			debug() << imie(se->second);
			if ( ss->second.first < se->second.second )
				puts ( "YES" );
			else
				puts ( "NO" );
		}
	}
}

int main ( int argc, char* argv[] )
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

