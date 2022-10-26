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

const int nax = 28;
vector<ll> s ( nax ), t ( nax ), cs ( nax ), ct ( nax );
int q, op;
ll k;
string ss;

void print_ans ()
{
	vector<ll> bs = s, bt = t;
	if ( bs == bt ) {
		puts ( "NO" );
		return;
	}
	bool ok = true;
	int si = 0, ti = nax - 1;
	while ( ok ) {
		while ( si < nax && bs[si] == 0 )
			++si;
		while ( ti > -1 && bt[ti] == 0 )
			--ti;
		if ( ti < 0 && si < nax ) { ok = false; break; }
		if ( si >= nax || ti < 0 ) break;
		debug() << imie(si) imie(ti);
		if ( si > ti ) { ok = false; break; }
		if ( si < ti ) break;
		int mn = min ( bs[si], bt[ti] );
		bs[si] -= mn;
		bt[ti] -= mn;
		debug() << imie(bs);
		debug() << imie(bt);
	}
	if ( ok ) puts ( "YES" );
	else puts ( "NO" );
}

inline void solve ( int _case )
{
	fill ( s.begin(), s.end(), 0LL );
	s[0] = 1;
	fill ( t.begin(), t.end(), 0LL );
	t[0] = 1;
	scanf ( "%d", &q );
	while ( q-- ) {
		fill ( cs.begin(), cs.end(), 0LL );
		fill ( ct.begin(), ct.end(), 0LL );
		scanf ( "%d %lld", &op, &k );
		ss = read_string ();
		if ( op == 1 ) for ( auto& i : ss ) cs[int(i-'a')] += k;
		else for ( auto& i : ss ) ct[int(i-'a')] += k;
		for ( int i = 0 ; i < nax ; ++i ) s[i] += cs[i];
		for ( int i = 0 ; i < nax ; ++i ) t[i] += ct[i];
		print_ans ();
	}
}

int main ( void )
{
	int _t = 1;
	scanf ( "%d" , &_t );
	for ( int i = 0 ; i < _t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ( i+1 );
	}


	return 0;
}

