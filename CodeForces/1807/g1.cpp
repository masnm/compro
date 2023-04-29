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

const int nax = 5005;
ll n;
vector<ll> v;
bool dp[nax];

inline void solve ( int _case ) {
    scanf ( "%lld", &n );
    v.resize ( n );
    for ( auto &i : v )
        scanf ( "%lld", &i );
    sort ( v.begin (), v.end () );
    ll limit = v.back () + 2;
    for ( int i = 0; i <= limit; ++i )
        dp[i] = false;
    ll prev = 1;
    dp[0] = true;
    if ( v[0] != 1 ) {
        puts ( "NO" );
        return;
    }
    v.erase ( v.begin () );
    bool ok = true;
    for ( auto &item : v ) {
        for ( int i = limit; i > -1; --i ) {
            if ( ( dp[i] == true ) && ( i + prev < limit ) )
                dp[i + prev] = true;
        }
        if ( dp[item] != true ) ok = false;
        prev = item;
    }
    puts ( ok ? "YES" : "NO" );
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