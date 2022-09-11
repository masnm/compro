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

const int nax = 101;
const int alice = 0, bob = 1;
int meme[nax][nax][nax];
int n;
vector<int> v;

void clear_memo ( void )
{
	for ( int i = 0 ; i < n ; ++i )
		for ( int j = 0 ; j < n ; ++j )
			for ( int k = 0 ; k < n ; ++k )
				meme[i][j][k] = -1;
}

int get_ans ( int l, int r, int ab, int ac, int bc )
{
	if ( l > r ) {
		return ac-bc;
	}
	int ta = INT_MAX;
	int sum = 0;
	for ( int i = l ; i <= r ; ++i ) {
		sum += v[i];
		if ( ab == alice ) ta = min ( ta, get_ans ( i+1, r, ab^alice^bob, ac+sum, bc ) );
		else ta = min ( ta, get_ans ( i+1, r, ab^alice^bob, ac, bc+sum ) );
	}
	for ( int i = r ; i >= l ; --i ) {
		sum += v[i];
		if ( ab == alice ) ta = min ( ta, get_ans ( l, i-1, ab^alice^bob, ac+sum, bc ) );
		else ta = min ( ta, get_ans ( l, i-1, ab^alice^bob, ac, bc+sum ) );
	}
	return ta;
}

void solve ()
{
	scanf ( "%d", &n );
	v.resize ( n );
	for ( auto& i : v ) scanf ( "%d", &i );
	clear_memo();
	printf ( "%d\n", get_ans( 0, n-1, alice, 0, 0 ) );
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

