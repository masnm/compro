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

const int nax = 80;
string ss;
map<pair<int,int >,int > memo;

ll get_ans ( int s, int e )
{
	auto cnt = [&]( int a, int b, int c ) {
		int cn = 0;
		if ( ss[a] == 'R' ) ++cn;
		if ( ss[b] == 'R' ) ++cn;
		if ( ss[c] == 'R' ) ++cn;
		return cn;
	};
	if ( s == e ) return 1;
	if ( s >= e ) return 0;
	if ( e-s < 3 ) return 0;
	auto src = memo.find ( make_pair(s,e) );
	if ( src != memo.end() ) return src->second;
	ll ans = 0;
	for ( int a = s + 1 ; a < e ; ++a ) {
		for ( int b = a + 1 ; b < e ; ++b ) {
			if ( cnt ( s, a, b ) <= 1 ) {
				int a1 = get_ans ( s + 1, a );
				int b1 = get_ans ( a + 1, b );
				int c1 = get_ans ( b + 1, e );
				ans += (a1 * b1 * c1);
			}
		}
	}
	memo[make_pair ( s, e )] = ans;
	return ans;
}

void solve ()
{
	memo.clear();
	ss = read_string ();
	printf ( "%lld\n", get_ans ( 0, ss.length() ) );
}

int main ( int argc, char* argv[] )
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

// TODO: Extended GCD
