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

const int tnax = 1 << 19;
int tree[tnax];
int dpth;

void tree_updt ( int l, int r ) {
    l += dpth - 1;
    r += dpth;
    for ( ; l < r; l >>= 1, r >>= 1 ) {
        if ( l & 1 ) tree[l++] += 1;
        if ( r & 1 ) tree[--r] += 1;
    }
}

ll my_trans ( ll val ) {
    ll ans = 0;
    while ( val > 0 ) {
        ans += ( val % 10 );
        val /= 10;
    }
    return ans;
}

ll tree_get ( int l, ll val ) {
    l += dpth - 1;
    while ( l > 0 ) {
        for ( int i = 0; i < min ( 3, tree[l] ); ++i ) {
            val = my_trans ( val );
        }
        l >>= 1;
    }
    return val;
}

int n, q, op, l, r;
vector<ll> v;

inline void solve ( int _case ) {
    scanf ( "%d%d", &n, &q );
    v.resize ( n );
    for ( auto &i : v )
        scanf ( "%lld", &i );
    dpth = 1;
    while ( dpth <= n )
        dpth <<= 1;
    for ( int i = 0; i < 2 * dpth; ++i )
        tree[i] = 0;
    while ( q-- ) {
        scanf ( "%d", &op );
        if ( op == 1 ) {
            scanf ( "%d%d", &l, &r );
            tree_updt ( l, r );
        } else if ( op == 2 ) {
            scanf ( "%d", &l );
            printf ( "%lld\n", tree_get ( l, v[l - 1] ) );
        } else
            assert ( false );
    }
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
