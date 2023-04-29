#include "bits/stdc++.h"
using namespace std;

// clang-format off
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
// clang-format on

#define F  first
#define S  second
#define eb emplace_back

string read_string ( void ) {
    static char ch[1000005];
    scanf ( "%s", ch );
    return string ( ch );
}

using ll = long long int;

const int nax = 10005;
int n, m, l, r;
vector<int> g[nax], q, order, ans, rg[nax];
vector<bool> vis, is;
bool cycle;

void dfs ( int me ) {
    if ( vis[me] ) return;
    vis[me] = true;
    for ( auto &x : g[me] ) {
        if ( is[x] ) cycle = true;
        is[x] = true;
        dfs ( x );
        is[x] = false;
    }
}

void bfs ( int me ) {
    order.clear ();
    q.clear ();
    fill ( vis.begin (), vis.end (), false );
    for ( int i = 0; i < int ( q.size () ); ++i ) {
        int cp = q[i];
        if ( vis[cp] ) continue;
        order.eb ( cp );
        vis[cp] = true;
        for ( auto x : rg[me] ) {
            if ( !vis[x] ) q.eb ( x );
        }
    }
}

int main ( void ) {
    scanf ( "%d%d", &n, &m );
    for ( int i = 0; i < m; ++i ) {
        scanf ( "%d%d", &l, &r );
        --l;
        --r;
        g[l].eb ( r );
        rg[r].eb ( l );
    }
    ans.resize ( n );
    fill ( ans.begin (), ans.end (), 0 );
    vis.resize ( n );
    fill ( vis.begin (), vis.end (), false );
    is.resize ( n );
    fill ( is.begin (), is.end (), false );
    cycle = false;
    is[0] = true;
    dfs ( 0 );
    debug () << imie ( cycle );
    bfs ( 0 );
    adfs ( 0 );

    return 0;
}
