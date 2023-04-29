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

// ll solve ( int l, int r ) {
//     if ( l == r ) return 1;
//     if ( l > r ) return 0;
//     ll ans = 0;
//     if ( s[l] == s[r] ) {
//         ans += 1 + solve ( l + 1, r - 1 );
//     }
//     ans += solve ( l + 1, r );
//     ans += solve ( l, r - 1 );
//     return ans;
// }

string s;

const int nax = 65;
ll memo[nax][nax];

ll solve ( int l, int r ) {
    if ( memo[l][r] != -1 ) return memo[l][r];
    ll ans = 0;
    for ( int i = l; i < r; ++i ) {
        for ( int j = i + 1; j <= r; ++j ) {
            if ( s[i] == s[j] ) {
                ans += 1LL + solve ( i + 1, j - 1 );
            }
        }
    }
    ans += ( r - l + 1 );
    memo[l][r] = ans;
    return ans;
}

inline void solve ( int _case ) {
    s = read_string ();
    int lim = s.length () + 3;
    for ( int i = 0; i < lim; ++i )
        for ( int j = 0; j < lim; ++j )
            memo[i][j] = -1;
    printf ( "%lld\n", solve ( 0, s.length () - 1 ) );
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
