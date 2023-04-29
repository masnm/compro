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

const ll mod = 100000;
const int nax = 205;
int n;
string s;
int memo[nax][nax];

bool ishot ( char ch ) {
    return !( ch == '(' || ch == ')' || ch == '[' || ch == ']' );
}

bool ismatch ( char l, char r ) {
    if ( ishot ( l ) && ishot ( r ) ) return true;
    if ( ishot ( l ) && ( r == ')' || r == ']' ) ) return true;
    if ( ishot ( r ) && ( l == '[' || l == '(' ) ) return true;
    if ( l == '(' && r == ')' ) return true;
    if ( l == '[' && r == ']' ) return true;
    return false;
}

ll solve ( int l, int r ) {
    if ( l > r ) return 1;
    if ( l == r ) return 0;
    if ( memo[l][r] != -1 ) return memo[l][r];
    ll ans = 0, ta;
    for ( int i = l + 1; i <= r; ++i ) {
        if ( ismatch ( s[l], s[i] ) ) {
            ta = 1;
            if ( ishot ( s[l] ) && ishot ( s[i] ) ) ta = 2;
            ta *= solve ( l + 1, i - 1 );
            ta %= mod;
            ta *= solve ( i + 1, r );
            ta %= mod;
            ans += ta;
            ans %= mod;
        }
    }
    debug () << imie ( l ) imie ( r ) imie ( ans );
    memo[l][r] = ans;
    return ans;
}

int main ( void ) {
    scanf ( "%d", &n );
    s = read_string ();
    int lim = s.length () + 3;
    for ( int i = 0; i < lim; ++i )
        for ( int j = 0; j < lim; ++j )
            memo[i][j] = -1;
    printf ( "%lld\n", solve ( 0, n - 1 ) );

    return 0;
}
