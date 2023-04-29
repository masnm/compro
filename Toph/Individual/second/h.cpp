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

// seg start
const int nax = 1 << 19;
int td, tree[nax];
void tree_build ( int _n ) {
    td = 1;
    while ( td <= _n )
        td <<= 1;
}
void tree_add ( int ind, int val = 1 ) {
    ind += td;
    tree[ind] = val;
    for ( ind >>= 1; ind > 0; ind >>= 1 )
        tree[ind] = tree[ind * 2] + tree[ind * 2 + 1];
}
int tree_get ( int l, int r ) {
    l += td;
    r += td + 1;
    int ans = 0;
    for ( ; l < r; l >>= 1, r >>= 1 ) {
        if ( l & 1 ) ans += tree[l++];
        if ( r & 1 ) ans += tree[--r];
    }
    return ans;
}
// seg end

int n;
vector<int> v, seq, ind;
vector<pair<int, int>> vp, ans;

int main ( void ) {
    scanf ( "%d", &n );
    v.resize ( n );
    for ( auto &i : v )
        scanf ( "%d", &i );
    for ( auto &i : v )
        --i;
    seq.resize ( n );
    int l = 0, r = n - 1, ep = 0;
    while ( l < r ) {
        seq[l++] = ep++;
        seq[r--] = ep++;
    }
    if ( l == r ) {
        seq[l++] = ep++;
    }
    ind.resize ( n );
    for ( int i = 0; i < n; ++i )
        ind[v[i]] = i;
    for ( int i = 0; i < n; ++i )
        vp.eb ( seq[i], i );
    sort ( vp.begin (), vp.end () );
    debug () << imie ( vp );
    bool left = true;
    tree_build ( n );
    for ( int i = 0; i < n; ++i )
        tree_add ( i, 1 );
    for ( auto &item : vp ) {
        tree_add ( ind[item.S], 0 );
        if ( left ) {
            ans.eb ( item.S, tree_get ( 0, ind[item.S] ) );
        } else {
            ans.eb ( item.S, tree_get ( ind[item.S], n ) );
        }
        debug () << imie ( ans );
        left ^= true;
    }
    for ( auto &item : ans )
        printf ( "%d\n", item.S );

    return 0;
}
