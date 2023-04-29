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

const ll nax = 1e10L + 5L;
vector<ll> all;

inline void pre ( void ) {
    ll st;
    for ( ll i = 2; i * i <= nax; ++i ) {
        st = i * i;
        while ( st < nax ) {
            all.eb ( st );
            st *= i;
        }
        if ( all.size () > 1000000 ) {
            debug () << imie ( i );
            break;
        }
    }
    sort ( all.begin (), all.end () );
    all.resize ( unique ( all.begin (), all.end () ) - all.begin () );
}

const int cax = 20005;
const ll mod = 100000007;
ll dp[cax];
inline void post ( void ) {
    dp[0] = dp[1] = 1;
    for ( ll i = 2; i < cax; ++i ) {
        for ( ll j = 0; j < i; ++j ) {
            dp[i] += dp[j] * dp[i - j - 1];
            dp[i] %= mod;
        }
    }
}

const int bax = 693;
ll memo[bax][bax];

ll get_ans ( ll l, ll r ) {
    if ( l == r ) return 1;
    if ( l > r ) return 1;
    if ( l + 1 == r ) return 2;
    if ( memo[l][r] != -1 ) return memo[l][r];
    ll tot = 0;
    for ( int i = l; i <= r; ++i ) {
        ll ans = get_ans ( l, i - 1 );
        ans %= mod;
        ans *= get_ans ( i + 1, r );
        ans %= mod;
        tot += ans;
        tot %= mod;
    }
    return memo[l][r] = tot;
}

ll a, b, fi, li;

inline void solve ( int _case ) {
    scanf ( "%lld%lld", &a, &b );
    fi = li = -1;
    if ( a <= all[0] ) fi = 0;
    if ( b >= all.back () ) li = all.size () - 1;
    if ( fi == -1 )
        fi = int ( lower_bound ( all.begin (), all.end (), a ) - all.begin () );
    if ( li == -1 )
        li = int ( lower_bound ( all.begin (), all.end (), b ) - all.begin () );
    while ( all[li] > b && li > 0 )
        --li;
    if ( li - fi + 1 > cax - 3 ) assert ( false );
    bool found = false;
    for ( int i = fi; i <= li; ++i )
        if ( all[i] >= a && all[i] <= b ) {
            found = true;
            break;
        }
    if ( !found ) {
        printf ( "0\n" );
        return;
    }
    printf ( "%lld\n", dp[li - fi + 1] );
    // printf ( "%lld\n", get_ans ( 0, li - fi ) );
    // debug () << imie ( fi ) imie ( li );
}

int main ( void ) {
    pre ();
    post ();
    // for ( int i = 0; i < bax; ++i )
    //     for ( int j = 0; j < bax; ++j )
    //         memo[i][j] = -1;
    // get_ans ( 0, bax - 1 );
    int _t = 1;
    scanf ( "%d", &_t );
    for ( int i = 0; i < _t; ++i ) {
        printf ( "Case %d: ", i + 1 );
        solve ( i + 1 );
    }

    return 0;
}
