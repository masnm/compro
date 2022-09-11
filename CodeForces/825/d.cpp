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

string s, t, u;
vector<int> cnt(27), oc(27);
int wc;
pair<int, char> cp;

void solve ()
{
	wc = 0;
	fill ( cnt.begin(), cnt.end(), 0 );
	fill ( oc.begin(), oc.end(), 0 );
	s = read_string(); t = read_string();
	for ( auto i : s ) {
		if ( i == '?' ) ++wc;
		else ++cnt[int(i-'a')];
	}
	u = t;
	// sort ( u.begin(), u.end() );
	// u.resize ( unique ( u.begin(), u.end() ) - u.begin() );

	priority_queue<pair<int, char> > pq;
	for ( auto i : u ) pq.push ( { -1 * cnt[int(i-'a')], i } );
	debug() << imie(wc);
	while ( wc-- ) {
		cp = pq.top(); pq.pop();
		--cp.F;
		pq.push ( cp );
	}
	while ( !pq.empty() ) {
		cp = pq.top();
		oc[int(cp.S-'a')] += -1 * cp.F;
		pq.pop();
	}
	for ( auto i : s ) if ( i != '?' ) --oc[int(i - 'a')];
	int ind = 0;
	int sm = accumulate ( oc.begin(), oc.end(), 0 );
	debug() << imie(sm);
	debug() << imie(s.size());
	debug() << imie(oc);
	for ( auto& i : s ) {
		if ( i == '?' ) {
			while ( oc[ind] <= 0 ) ++ind;
			--oc[ind];
			i = char(ind+'a');
		}
	}
	printf ( "%s\n", s.c_str() );
}

int main ( int argc, char* argv[] )
{
	int _t = 1;
	scanf ( "%d" , &_t );
	for ( int i = 0 ; i < _t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

