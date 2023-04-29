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

debug &operator<< ( debug &dd, tuple<int, char, int> p ) {
    dd << "(" << get<0> ( p ) << ", " << get<1> ( p ) << " " << get<2> ( p )
       << ")";
    return dd;
}

#define F  first
#define S  second
#define eb emplace_back

string read_string ( void ) {
    static char ch[1000005];
    scanf ( "%s", ch );
    return string ( ch );
}

using ll = long long int;

int tar = 15;
vector<tuple<int, char, int>> q;
tuple<int, char, int> cp;
string s;
vector<bool> vis;

inline void solve ( int _case ) {
    int ans = INT_MAX;
    fill ( vis.begin (), vis.end (), false );
    s = read_string ();
    q.clear ();
    q.eb ( 0, 'z', 0 );
    for ( int xx = 0; xx < 1000 && xx < int ( q.size () ); ++xx ) {
        cp = q[xx];
        if ( get<0> ( cp ) == tar ) ans = min ( ans, get<2> ( cp ) );
        // if ( vis[get<0> ( cp )] ) continue;
        vis[get<0> ( cp )] = true;
        for ( int i = 0; i < 4; ++i ) {
            if ( get<1> ( cp ) != s[i] ) {
                q.eb ( get<0> ( cp ) ^ ( 1 << ( 3 - i ) ), s[i],
                       get<2> ( cp ) + 1 );
            }
        }
    }
    debug () << imie ( q );
    printf ( "%d\n", ans == INT_MAX ? -1 : ans );
}

int main ( void ) {
    vis.resize ( 64 );
    int _t = 1;
    scanf ( "%d", &_t );
    for ( int i = 0; i < _t; ++i ) {
        // printf ( "Case %d: ", i + 1 );
        solve ( i + 1 );
    }

    return 0;
}
