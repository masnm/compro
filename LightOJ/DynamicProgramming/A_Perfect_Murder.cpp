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

const int nax = 1005;

vector<int> g[nax], q;
vector<bool> vis;
int n, m, l, r, cp;

void make_vis ( int me ) {
    q.clear ();
    q.eb ( me );
    for ( int i = 0; i < int ( q.size () ); ++i ) {
        cp = q[i];
        if ( vis[cp] ) continue;
        vis[cp] = true;
        for ( auto ii : g[cp] )
            if ( !vis[ii] ) q.eb ( ii );
    }
}

int memo[nax][nax][2];

ll get_ans ( int me, int par, int prev_tak ) {
    if ( memo[me][par][prev_tak] != -1 ) return memo[me][par][prev_tak];
    ll ans = 0;
    if ( prev_tak ) {
        for ( auto item : g[me] ) {
            if ( item != par ) {
                ans += get_ans ( item, me, 0 );
            }
        }
    } else {
        for ( auto item : g[me] ) {
            if ( item != par ) {
                ans += max ( get_ans ( item, me, 0 ),
                             1LL + get_ans ( item, me, 1 ) );
            }
        }
    }
    return memo[me][par][prev_tak] = ans;
}

inline void solve ( int _case ) {
    scanf ( "%d%d", &n, &m );
    vis.resize ( n + 1 );
    fill ( vis.begin (), vis.end (), false );
    for ( int i = 0; i < n; ++i )
        g[i].clear ();
    for ( int i = 0; i <= n; ++i )
        for ( int j = 0; j <= n; ++j )
            memo[i][j][0] = memo[i][j][1] = -1;
    for ( int i = 0; i < m; ++i ) {
        scanf ( "%d%d", &l, &r );
        --l;
        --r;
        g[l].eb ( r );
        g[r].eb ( l );
    }
    ll ans = 0;
    for ( int i = 0; i < n; ++i ) {
        if ( !vis[i] ) {
            ans += max ( get_ans ( i, n, 0 ), 1LL + get_ans ( i, n, 1 ) );
            make_vis ( i );
        }
    }
    printf ( "%lld\n", ans );
}

int main ( void ) {
    int _t = 1;
    scanf ( "%d", &_t );
    for ( int i = 0; i < _t; ++i ) {
        printf ( "Case %d: ", i + 1 );
        solve ( i + 1 );
    }

    return 0;
}
