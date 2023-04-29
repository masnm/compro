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

int n;
ll px, py;
vector<pair<ll, ll>> vp;
vector<ll> bst;
pair<ll, ll> one, two;

unordered_map<ll, ll> umx, umy;

int main ( void ) {
    scanf ( "%d", &n );
    for ( int i = 0; i < n; ++i ) {
        scanf ( "%lld%lld", &px, &py );
        vp.eb ( px, py );
        bst.eb ( px );
        bst.eb ( py );
    }
    sort ( bst.begin (), bst.end () );
    bst.resize ( int ( unique ( bst.begin (), bst.end () ) - bst.begin () ) );
    for ( auto &item : vp ) {
        item.F = int ( lower_bound ( bst.begin (), bst.end (), item.F ) -
                       bst.begin () );
        item.S = int ( lower_bound ( bst.begin (), bst.end (), item.S ) -
                       bst.begin () );
    }
    umx.reserve ( 1 << 12 );
    umy.reserve ( 1 << 12 );
    for ( auto &item : vp ) {
        umx[item.F]++;
        umy[item.S]++;
    }
    debug () << imie ( vp );
    ll ans = 0;
    for ( int i = 0; i < n; ++i ) {
        for ( int j = i + 1; j < n; ++j ) {
            one = vp[i];
            two = vp[j];
            if ( one.F == two.F ) {
                ans += umy[one.S] - 1;
                ans += umy[two.S] - 1;
                // |
            } else if ( one.S == two.S ) {
                ans += umx[one.F] - 1;
                ans += umx[two.F] - 1;
                // _
            } else {
            }
        }
    }
    printf ( "%lld\n", ans );

    return 0;
}
