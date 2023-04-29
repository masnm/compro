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

const int nax = 5005, nbx = 205;
const ll inf = 1e16L + 5;
int n, m;
ll inp[nax][nbx];
pair<ll, ll> dp[nax][nbx];
vector<ll> dis, ps;

int main ( void ) {
    scanf ( "%d%d", &n, &m );
    dis.resize ( n - 1 );
    for ( auto &i : dis )
        scanf ( "%lld", &i );
    ps.resize ( n - 1 );
    partial_sum ( dis.begin (), dis.end (), ps.begin () );
    for ( int i = 0; i < n; ++i )
        for ( int j = 0; j < m; ++j )
            scanf ( "%lld", &inp[i][j] );

    for ( int i = 0; i < n + 1; ++i )
        for ( int j = 0; j < m + 1; ++j )
            dp[i][j].F = -inf, dp[i][j].S = 0;

    for ( int j = 0; j < m; ++j ) {
        for ( int i = 0; i < n; ++i ) {
            for ( int k = 0; k < n; ++k ) {
                if ( j == 0 ) {
                    dp[i][j].F = max ( dp[i][j].F,
                                       inp[i][j] - ( i == 0 ? 0 : ps[i - 1] ) );
                    dp[i][j].S = i;
                } else {
                    ll minus = 0;
                    if ( i > dp[k][j - 1].S )
                        minus =
                            ( i == 0 ? 0 : ps[i - 1] ) -
                            ( dp[k][j - 1].S - 1 < 0 ? 0
                                                     : ps[dp[k][j - 1].S - 1] );
                    ll tar = dp[k][j - 1].F + inp[i][j] - minus;
                    if ( tar >= dp[i][j].F ) {
                        dp[i][j].F = tar;
                        dp[i][j].S = max ( ll ( i ), dp[k][j - 1].S );
                    }
                }
            }
        }
    }
    ll ans = -inf;
    for ( int i = 0; i < n; ++i )
        for ( int j = 0; j < m; ++j )
            ans = max ( ans, dp[i][j].F );
    printf ( "%lld\n", ans );

    return 0;
}
