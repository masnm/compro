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

struct Dsu {
        vector<int> gi;
        vector<vector<int>> gm;
        Dsu ( int n ) {
            gi.resize ( n );
            for ( int i = 0; i < n; ++i )
                gi[i] = i;
            gm.clear ();
            gm.resize ( n );
            for ( int i = 0; i < n; ++i ) {
                gm[i].clear ();
                gm[i].eb ( i );
            }
        }
        bool finished () {
            return gm[gi[0]].size () == gi.size ();
        }
        bool add ( int l, int r ) {
            if ( gi[l] == gi[r] ) return false;
            l = gi[l];
            r = gi[r];
            if ( gm[l].size () > gm[r].size () ) swap ( l, r );
            for ( auto i : gm[l] ) {
                gm[r].eb ( i );
                gi[i] = r;
            }
            gm[l].clear ();
            return true;
        }
};

int n, c, l, r;
vector<tuple<ll, int, int>> vtp;

inline void solve ( int _case ) {
    scanf ( "%d", &n );
    vtp.clear ();
    while ( true ) {
        scanf ( "%d%d%d", &l, &r, &c );
        if ( l == r && l == c && l == 0 ) break;
        vtp.eb ( c, l, r );
    }
    sort ( vtp.begin (), vtp.end () );
    Dsu d ( vtp.size () + 1 );
    ll min_ans = 0;
    for ( auto item : vtp ) {
        if ( d.add ( get<1> ( item ), get<2> ( item ) ) )
            min_ans += get<0> ( item );
    }
    ll max_ans = 0;
    Dsu dd ( vtp.size () + 1 );
    reverse ( vtp.begin (), vtp.end () );
    for ( auto item : vtp ) {
        if ( dd.add ( get<1> ( item ), get<2> ( item ) ) )
            max_ans += get<0> ( item );
    }
    ll summ = min_ans + max_ans;
    if ( summ & 1 ) {
        printf ( "%lld/2\n", summ );
    } else {
        printf ( "%lld\n", summ / 2 );
    }
}

int main ( void ) {
    int _t = 1;
    scanf ( "%d", &_t );
    for ( int i = 0; i < _t; ++i ) {
        printf ( "Case %d: ", i + 1 );
        solve ( i + 1 );
    }

    return 0;
}
