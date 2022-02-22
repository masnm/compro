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

map<string,bool> mp;
map<string,bool> mpb;

void solve ()
{
	mp.clear();
	string a = read_string(), b = read_string();
	int k;
	scanf("%d", &k );
	int limit = int(a.length()) - k;
	for ( int i = 0 ; i <= limit ; ++i ) {
		mp[a.substr(i,k)] = true;
	}
	int cnta = mp.size();
	limit = int(b.length()) - k;
	int same = 0;
	mpb.clear();
	for ( int i = 0 ; i <= limit ; ++i ) {
		string subs = b.substr(i,k);
		mpb[subs] = true;
	}
	for ( auto i : mpb ) {
		auto search = mp.find(i.first);
		if ( search != mp.end() )
			++same;
	}
	int cntb = mpb.size();
	double sm = same;
	double ns = cnta + cntb - same;
	debug() << imie(sm) imie(ns);
	printf ( "%lF\n", sm/ns );
}

int main ()
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

