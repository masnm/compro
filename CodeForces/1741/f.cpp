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

struct P {
	P () = default;
	P ( ll _x, ll _y, int _c, int _ind, ll _ans )
		: x(_x), y(_y), c(_c), ind(_ind), ans(_ans) {}
	ll x = 0;
	ll y = 0;
	int c = 0;
	int ind = 0;
	ll ans = LLONG_MAX;
};
debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ", C" << p.c << ", " << p.ind << ")"; return dd; }

int n;
vector<P> vs;

ll my_dis ( P& l, P& r )
{
	if ( l.x >= r.x && l.x <= r.y ) return 0LL;
	if ( l.y >= r.x && l.y <= r.y ) return 0LL;
	ll ans = LLONG_MAX;
	ans = min ( ans, abs ( l.x - r.x ) );
	ans = min ( ans, abs ( l.x - r.y ) );
	ans = min ( ans, abs ( l.y - r.x ) );
	ans = min ( ans, abs ( l.y - r.y ) );
	return ans;
}

void make_ans ()
{
	int sm = 0;
	for ( int i = 0 ; i < n ; ++i ) {
		for ( int j = sm ; j < n ; ++j ) {
			if ( vs[i].c != vs[j].c ) {
				sm = j;
				break;
			}
		}
		if ( vs[i].c != vs[sm].c ) {
			vs[i].ans = min ( vs[i].ans, my_dis ( vs[i], vs[sm] ) );
			vs[sm].ans = min ( vs[sm].ans, my_dis ( vs[i], vs[sm] ) );
		}
		sm = max ( sm, i );
	}
}

void print_ans ()
{
	for ( auto i : vs )
		printf ( "%lld ", i.ans );
	puts ( "" );
}


inline void solve ( int _case )
{
	(void ) _case ;
	scanf ( "%d", &n );
	vs.resize ( n );
	int ind = 0;
	P _p;
	fill ( vs.begin(), vs.end(), _p );
	for ( auto& i : vs ) {
		scanf ( "%lld%lld%d", &i.x, &i.y, &i.c );
		i.ind = ++ind;
		i.ans = LLONG_MAX;
	}
	sort ( vs.begin(), vs.end(), [](auto& l, auto& r) { return tie(l.x,l.y) < tie(r.x,r.y); } );
	make_ans ();
	reverse ( vs.begin(), vs.end() );
	make_ans ();
	sort ( vs.begin(), vs.end(), [](auto& l, auto& r) { return tie(l.y,l.x) < tie(r.y,r.x); } );
	make_ans ();
	reverse ( vs.begin(), vs.end() );
	make_ans ();
	//sort ( vs.begin(), vs.end(), [](auto& l, auto& r) { return l.c < r.c; } );
	//make_ans ();
	//reverse ( vs.begin(), vs.end() );
	//make_ans ();
	//sort ( vs.begin(), vs.end(), [](auto& l, auto& r) { return l.c > r.c; } );
	//make_ans ();
	//reverse ( vs.begin(), vs.end() );
	//make_ans ();
	sort ( vs.begin(), vs.end(), [](auto& l, auto& r) { return l.ind < r.ind; } );
	print_ans ();
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

/*
5
1 2 1
1 5 1
4 9 2
5 7 3
8 9 2
 */

/*
15 18 1
20 22 2
13 22 2
13 22 2
3 13 2
6 10 2
3 6 2
19 24 2
22 24 2

 */
