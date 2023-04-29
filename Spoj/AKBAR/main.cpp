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

const int nax = 1000005;
int n, _r, m, l, r;
vector<int> g[nax], cvr;
vector<bool> vis;
vector<pair<int, int>> q;
pair<int, int> cp;
set<int> st;

inline void solve ( int _case ) {
    (void)_case;
    scanf ( "%d%d%d", &n, &_r, &m );
    for ( int i = 1; i <= n; ++i )
        g[i].clear ();
    for ( int i = 0; i < _r; ++i ) {
        scanf ( "%d%d", &l, &r );
        g[l].eb ( r );
        g[r].eb ( l );
    }
    cvr.resize ( n + 1 );
    fill ( cvr.begin (), cvr.end (), 0 );
    vis.resize ( n + 1 );
    fill ( vis.begin (), vis.end (), false );
    bool ok = true;
    debug () << imie ( n );
    for ( int mm = 0; mm < m; ++mm ) {
        scanf ( "%d%d", &l, &r );
        if ( !ok ) continue;
        q.clear ();
        q.eb ( l, 0 );
        st.clear ();
        for ( int i = 0; i < int ( q.size () ); ++i ) {
            cp = q[i];
            if ( cp.S > r ) continue;
            st.insert ( cp.F );
            if ( vis[cp.F] ) continue;
            vis[cp.F] = true;
            for ( auto &x : g[cp.F] )
                if ( !vis[x] ) q.eb ( x, cp.S + 1 );
        }
        debug () << imie ( mm );
        debug () << imie ( st );
        for ( auto i : st )
            cvr[i]++;
        for ( auto i : st )
            if ( cvr[i] > 1 ) ok = false;
    }
    for ( int i = 1; i <= n; ++i )
        if ( cvr[i] < 1 ) ok = false;
    puts ( ok ? "Yes" : "No" );
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
