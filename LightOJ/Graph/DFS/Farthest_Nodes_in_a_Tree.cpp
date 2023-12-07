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

struct tpl {
    tpl() = default;
    tpl ( ll _n, ll c, ll mc ) :
        next(_n), cost(c), mxcost(mc) {}

    ll next = 0, cost = 0, mxcost = 0;
};
debug & operator << (debug & dd, tpl p) { dd << "(" << p.next << ", " << p.cost << ", " << p.mxcost << ")"; return dd; }

const int nax = 30005;

ll n, s, e, c, fans;
vector<tpl> g[nax];
vector<ll> csts;

ll first_dfs ( ll me, ll par ) {
    for ( auto &item : g[me] ) {
        if ( item.next != par ) {
            ll next_cost = first_dfs ( item.next, me );
            item.mxcost = max ( item.mxcost, next_cost + item.cost );
        }
    }
    ll ret = 0;
    for ( auto item : g[me] ) {
        if ( item.next != par ) {
            ret = max ( ret, item.mxcost );
        }
    }
    return ret;
}

void second_dfs ( ll me, ll par, ll pc ) {
    csts.clear();
    for ( auto item : g[me] ) {
        if ( item.next != par ) {
            csts.eb ( item.mxcost );
        }
    }
    csts.eb ( pc );
    sort ( csts.begin(), csts.end(), greater<ll>() );
    if ( csts.size() == 1 )
        fans = max ( fans, csts[0] );
    else
        fans = max ( fans, csts[0] + csts[1] );
}

inline void solve ( int _case ) {
    scanf ( "%lld", &n );
    for ( int i = 0; i < nax; i++ ) g[i].clear();
    for ( int i = 0; i < n - 1; i++ ) {
        scanf ( "%lld%lld%lld", &s, &e, &c );
        g[s].eb ( e, c, 0LL );
        g[e].eb ( s, c, 0LL );
    }
    fans = LLONG_MIN;
    first_dfs ( 0, -1 );
    second_dfs ( 0, -1, 0 );
    printf ( "%lld\n", fans );
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

/*
 * { 20, 30, 12, 10, 5 }
 */
