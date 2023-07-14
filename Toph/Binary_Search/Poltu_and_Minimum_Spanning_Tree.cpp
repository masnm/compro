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

struct DSU {
        int n;
        vector<int> gi;
        vector<vector<int>> gm;
        void init ( int _n ) {
            n = _n;
            gi.resize ( n );
            iota ( gi.begin (), gi.end (), 0 );
            gm.resize ( n );
            for ( int i = 0; i < n; ++i ) {
                gm[i].clear ();
                gm[i].eb ( i );
            }
        }
        bool add ( int l, int r ) {
            if ( gi[l] == gi[r] ) return false;
            int gil = gi[l], gir = gi[r];
            if ( gm[gil].size () < gm[gir].size () ) swap ( gil, gir );
            for ( auto i : gm[gir] ) {
                gi[i] = gil;
                gm[gil].eb ( i );
            }
            gm[gir].clear ();
            return true;
        }
        bool done ( void ) {
            return int ( gm[gi[0]].size () ) == n;
        }
};

struct tpl {
        int u = 0, v = 0;
        ll w = 0;
        int c = 0;
        tpl () = default;
        tpl ( int _u, int _v, ll _w, int _c )
            : u ( _u ), v ( _v ), w ( _w ), c ( _c ) {
        }
};
debug &operator<< ( debug &dd, tpl p ) {
    dd << "(" << p.u << ", " << p.v << " " << p.w << " " << p.c << ")";
    return dd;
}

int n, m, k, u, v, c, wc;
ll w;
vector<tpl> edges, whites;

int main ( void ) {
    scanf ( "%d%d%d", &n, &m, &k );
    for ( int i = 0; i < m; ++i ) {
        scanf ( "%d%d%lld%d", &u, &v, &w, &c );
        edges.eb ( u, v, w, c );
    }
    DSU dsu;
    ll low = -1e9L + 5, high = 1e9L + 5, mid;
    while ( low < high ) {
        mid = ( low + high ) / 2LL;
        sort ( edges.begin (), edges.end (), [&mid] ( auto l, auto r ) {
            if ( l.c == 0 ) l.w += mid;
            if ( r.c == 0 ) r.w += mid;
            return tie ( l.w, l.c ) < tie ( r.w, r.c );
        } );
        wc = 0;
        dsu.init ( n );
        for ( auto i : edges ) {
            if ( dsu.add ( i.u - 1, i.v - 1 ) && i.c ) ++wc;
            if ( dsu.done () ) break;
        }
        if ( wc < k )
            low = mid + 1;
        else if ( wc > k )
            high = mid - 1;
        else
            low = high = mid;
    }
    sort ( edges.begin (), edges.end (), [&low] ( auto l, auto r ) {
        if ( l.c == 0 ) l.w += low;
        if ( r.c == 0 ) r.w += low;
        return tie ( l.w, l.c ) < tie ( r.w, r.c );
    } );
    wc = 0;
    dsu.init ( n );
    ll cst = 0;
    for ( auto i : edges ) {
        if ( dsu.add ( i.u - 1, i.v - 1 ) ) {
            if ( i.c ) ++wc;
            cst += i.w;
        }
        if ( dsu.done () ) break;
    }
    printf ( "%lld\n", wc == k ? cst : -1 );
    return 0;
}
