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

ll a, b, c, d;
ll f, s, ans, mn;

template <typename T> T min ( T _a, T _b, T _c ) {
    return min ( _c, min ( _a, _b ) );
}
template <typename T> T max ( T _a, T _b, T _c ) {
    return max ( _c, max ( _a, _b ) );
}

inline void solve ( int _case ) {
    scanf ( "%lld%lld%lld%lld", &a, &b, &c, &d );
    f = 0;
    s = 0;
    ans = 0;
    if ( a > 0 ) {
        mn = min ( b, c );
        ans += mn;
        ans += mn;
        b -= mn;
        c -= mn;
    }
    mn = min ( a, d );
    ans += mn;
    ans += mn;
    a -= mn;
    d -= mn;
    debug () << imie ( a ) imie ( b ) imie ( c ) imie ( d ) imie ( ans );
    if ( a > 0 ) {
        ans += a;
    }
    mn = max ( b, c, d );
    if ( mn > 0 ) ans += 1;
    printf ( "%lld\n", ans );
}

int main ( void ) {
    int _t = 1;
    scanf ( "%d", &_t );
    for ( int i = 0; i < _t; ++i ) {
        // printf ( "Case %d: ", i + 1 );
        solve ( i + 1 );
    }

    return 0;
}
