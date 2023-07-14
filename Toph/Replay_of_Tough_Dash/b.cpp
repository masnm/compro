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

vector<ll> v;
vector<pair<ll, ll>> vp;
int n, c;

int main ( void ) {
    scanf ( "%d%d", &n, &c );
    v.resize ( c + 5 );
    vp.resize ( n );
    for ( auto &i : vp )
        scanf ( "%lld%lld", &i.F, &i.S );
    sort ( vp.begin (), vp.end () );
    v[0] = 1;
    debug () << imie ( v );
    for ( auto item : vp ) {
        // for ( int i = 0; i < c - item.F + 2; i++ ) {
        for ( int i = c - item.F + 1; i > -1; --i ) {
            if ( v[i] ) {
                v[i + item.F] = max ( v[i + item.F], v[i] + item.S );
            }
        }
        debug () << imie ( v );
    }
    ll mx = 0;
    for ( int i = 0; i < c + 1; ++i )
        mx = max ( mx, v[i] );
    debug () << imie ( v );
    printf ( "%lld\n", mx - 1 );
    return 0;
}
