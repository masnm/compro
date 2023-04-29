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

// seg tree start
const int inf = 1 << 25;
const int nax = ( 1 << 19 );
int th;
int tree[nax];

void build ( int _n, vector<int> &inp ) {
    th = 1;
    while ( th <= _n )
        th <<= 1;
    for ( int i = 0; i < _n; ++i )
        tree[th + i] = inp[i];
    for ( int i = _n; i < th; ++i )
        tree[th + i] = inf;
    for ( int i = th - 1; i > 0; --i )
        tree[i] = min ( tree[i * 2], tree[i * 2 + 1] );
}

int tree_min ( int l, int r ) {
    int ans = inf;
    for ( l += th, r += th + 1; l < r; l >>= 1, r >>= 1 ) {
        if ( l & 1 ) ans = min ( ans, tree[l++] );
        if ( r & 1 ) ans = min ( ans, tree[--r] );
    }
    return ans;
}
// seg tree end

int n;
vector<int> v;

void my_case ( void ) {
    scanf ( "%d", &n );
    v.resize ( n );
    for ( auto &i : v )
        scanf ( "%d", &i );
    build ( n, v );
    int ans = 0;
    for ( int i = 0; i < n; ++i ) {
        int low, high, mid;
        // for right
        low = i;
        high = n - 1;
        for ( int rep = 0; rep < 32; ++rep ) {
            mid = ( low + high + 1 ) / 2;
            int min_val = tree_min ( i, mid );
            if ( min_val >= v[i] )
                low = mid;
            else
                high = mid - 1;
        }
        int can_go_ri = low;
        // for left
        low = 0, high = i;
        for ( int rep = 0; rep < 32; ++rep ) {
            mid = ( low + high ) / 2;
            int min_val = tree_min ( mid, i );
            if ( min_val >= v[i] )
                high = mid;
            else
                low = mid + 1;
        }
        int can_go_le = mid;
        int di = can_go_ri - can_go_le + 1;
        ans = max ( ans, di * v[i] );
    }
    printf ( "%d\n", ans );
}

int main ( void ) {
    int t;
    scanf ( "%d", &t );
    int ccs = 1;
    while ( t-- ) {
        printf ( "Case %d: ", ccs++ );
        my_case ();
    }

    return 0;
}

// 2 2 2 2 2 2 2 2 10
//
// low = 0, high = 8
// mid = 4
//
// low = mid = 4, high = 8
// mid = 6
//
// low = mid = 6, high = 8
// mid = 7
//
// low = mid = 7, high = 8
// mid = 8
//
// low = 7, high = 7

// 4 4 3 2 4
// |
// low 0
// high 4
// mid = 2
//
// low 0 high 2
// mid 1
//
//
// low 1 high 2
// mid
//
//   1 3 2
// th = 4
//
//
//
//                          1
//                1                  2
//            1        3        2         inf
