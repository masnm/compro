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

const int nax = 100005;
int n, l, r;
vector<int> g[nax];
vector<int> edges ( nax, 0 ), depth ( nax, 0 ), par ( nax, 0 );
vector<pair<int, int>> vp;
vector<tuple<int, int, int>> q;
tuple<int, int, int> cp;
vector<bool> vis ( nax, false );

void bfs ( int root ) {
    q.eb ( root, 0, -1 );
    for ( int i = 0; i < int ( q.size () ); ++i ) {
        cp = q[i];
        if ( vis[get<0> ( cp )] ) continue;
        vis[get<0> ( cp )] = true;
        depth[get<0> ( cp )] = get<1> ( cp );
        par[get<0> ( cp )] = get<2> ( cp );
        for ( auto &ii : g[get<0> ( cp )] )
            if ( !vis[ii] ) q.eb ( ii, get<1> ( cp ) + 1, get<0> ( cp ) );
    }
}

int ask ( int node ) {
    printf ( "? %d\n", node );
    fflush ( stdout );
    int tt;
    scanf ( "%d", &tt );
    return tt;
}

void ansis ( int node ) {
    printf ( "! %d\n", node );
}

void find_and_delete ( pair<int, int> me ) {
}

int main ( void ) {
    scanf ( "%d", &n );
    for ( int i = 0; i < n - 1; ++i ) {
        scanf ( "%d%d", &l, &r );
        --l;
        --r;
        g[l].eb ( r );
        g[r].eb ( l );
        ++edges[l];
        ++edges[r];
    }
    int root = -1;
    for ( int i = 0; i < n; ++i ) {
        if ( edges[i] == 1 ) {
            root = i;
            break;
        }
    }
    bfs ( root );
    for ( int i = 0; i < n; ++i ) {
        vp.eb ( depth[i], i );
    }
    sort ( vp.begin (), vp.end () );
    int low = 0;
    high = n - 1;
    // F parent, S child
    pair<int, int> one;
    while ( low < high ) {
        int mid = ( high + low + 1 ) / 2;
        int fnd = ask ( mid );
        int fnd2 = ask ( par[mid] );
        if ( fnd == 0 ) {
            ansis ( mid );
            return 0;
        }
        if ( fnd2 == ) {
            ansis ( par[mid] );
            return 0;
        }
        if ( fnd > fnd2 )
            one = make_pair ( par[mid], mid );
        else
            one = make_pair ( mid, par[mid] );
        break;
    }
    fill ( vis.begin (), vis.end () );
    while ( true ) {
        // delete nodes
        find_and_delete ( one );
        // find median
        // do same
    }

    return 0;
}
