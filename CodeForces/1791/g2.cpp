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

const ll inf = 1e18L + 5;
int n, mi;
vector<ll> v;
vector<pair<ll, int>> mini, nxt;
ll money, mv, tc, lc, rc, bmn;

int get_ans ( void ) {
    int ans = 1;
    if ( money < 0LL ) ans = 0;
    for ( int i = 0; i < n; ++i ) {
        if ( nxt[i].F <= money ) {
            money -= nxt[i].F;
            ans++;
        }
    }
    return ans;
}

inline void solve ( int _case ) {
    scanf ( "%d%lld", &n, &money );
    bmn = money;
    v.resize ( n );
    for ( auto &i : v )
        scanf ( "%lld", &i );
    mini.clear ();
    for ( int i = 0; i < n; ++i ) {
        mini.eb ( v[i] + i + 1, i );
    }
    sort ( mini.begin (), mini.end () );
    nxt.resize ( n );
    for ( int i = 0; i < n; ++i ) {
        lc = v[i] + i + 1;
        rc = v[i] + n - i;
        nxt[i].F = min ( lc, rc );
        nxt[i].S = i;
    }
    sort ( nxt.begin (), nxt.end () );
    int ans = 0;
    for ( int i = 0; i < min ( n, 10 ); ++i ) {
        money = bmn;
        ll value, index;
        for ( int ii = 0; ii < n; ++ii ) {
            if ( nxt[ii].S == mini[i].S ) {
                value = nxt[ii].F;
                nxt[ii].F = inf;
                index = ii;
                break;
            }
        }
        money -= mini[i].F;
        if ( money >= 0 ) {
            ans = max ( ans, get_ans () );
        }
        nxt[index].F = value;
    }
    printf ( "%d\n", ans );
}

int main ( void ) {
    int _t = 1;
    scanf ( "%d", &_t );
    for ( int i = 0; i < _t; ++i ) {
        //		printf ( "Case %d: ", i+1 );
        solve ( i + 1 );
    }

    return 0;
}
