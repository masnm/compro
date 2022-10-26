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

struct tpl {
	int s = 0, e = 0, c = 0;
	tpl () = default;
	tpl ( int _s, int _e, int _c )
		: s(_s), e(_e), c(_c) {}
};

const int nax = 1<<19;
int tree[nax];
int n, m, th;
vector<pair<int,int>> bl, rd;
vector<tpl> all;

inline void solve ( int _case )
{
	all.clear();
	scanf ( "%d%d", &n, &m );
	bl.resize ( n );
	for ( auto& i : bl ) {
		scanf ( "%d%d", &i.F, &i.S );
		--i.F; --i.S;
	}
	rd.resize ( m );
	for ( auto& i : rd ) {
		scanf ( "%d%d", &i.F, &i.S );
		--i.F; --i.S;
	}
	th = 1; while ( th <= n+m ) th <<= 1;
	for ( int i = 0 ; i < 2*th ; ++i ) tree[i] = 0;
	for ( auto& i : rd ) tree[i.S+th] += 1;
	for ( int i = th - 1 ; i > 0 ; --i ) tree[i] = tree[i*2] + tree[i*2+1];
	for ( auto& i : bl ) all.eb ( i.F, i.S, 0 );
	for ( auto& i : rd ) all.eb ( i.F, i.S, 1 );
	sort ( all.begin(), all.end(), [](auto& l, auto& r) {
			return tie(l.s,l.e) < tie(r.s,r.e);
			});
	ll ans = 0;
	for ( auto& item : all ) {
		if ( item.c == 1 ) {
			int ind = item.e + th;
			tree[ind] -= 1;
			for ( ind >>= 1 ; ind > 0 ; ind >>= 1 )
				tree[ind] = tree[ind*2] + tree[ind*2+1];
		} else {
			int ind = item.e + 1;
			int l = th, r = th + ind;
			ll gt = 0;
			for ( ; l < r ; l >>= 1, r >>= 1 ) {
				if ( l & 1 ) gt += tree[l++];
				if ( r & 1 ) gt += tree[--r];
			}
			ans += gt;
		}
	}
	for ( auto& i : rd ) tree[i.S+th] += 1;
	for ( int i = th - 1 ; i > 0 ; --i ) tree[i] = tree[i*2] + tree[i*2+1];
	reverse ( all.begin(), all.end() );
	for ( auto& item : all ) {
		if ( item.c == 1 ) {
			int ind = item.e + th;
			tree[ind] -= 1;
			for ( ind >>= 1 ; ind > 0 ; ind >>= 1 )
				tree[ind] = tree[ind*2] + tree[ind*2+1];
		} else {
			int l = th + item.e, r = n + m + 1 + th;
			ll gt = 0;
			for ( ; l < r ; l >>= 1, r >>= 1 ) {
				if ( l & 1 ) gt += tree[l++];
				if ( r & 1 ) gt += tree[--r];
			}
			ans += gt;
		}
	}
	printf ( "%lld\n", ans );
}

int main ( void )
{
	int _t = 1;
	scanf ( "%d" , &_t );
	for ( int i = 0 ; i < _t ; ++i ) {
		printf ( "Case %d: ", i+1 );
		solve ( i+1 );
	}


	return 0;
}

