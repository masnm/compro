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
string s;
vector<pair<int, int>> vp;

bool in_same_line ( pair<int, int> a, pair<int, int> b, pair<int, int> c ) {
    int chx = b.F - a.F;
    int chy = b.S - a.S;
    bool fb = false, fc = false;
    for ( int i = 0; i < 200; ++i ) {
        if ( ( a.F + ( chx * i ) == b.F ) && ( a.S + ( chy * i ) == b.S ) )
            fb = true;
        if ( ( a.F + ( chx * i ) == c.F ) && ( a.S + ( chy * i ) == c.S ) )
            fc = true;
    }
    return ( fb && fc );
}

int main ( void ) {
    scanf ( "%d", &n );
    for ( int i = 0; i < n; ++i ) {
        s = read_string ();
        for ( int j = 0; j < n; ++j ) {
            if ( s[j] != '.' ) {
                vp.eb ( i, j );
            }
        }
    }
    int ans = 0;
    for ( int i = 0; i < int ( vp.size () ); ++i ) {
        for ( int j = i + 1; j < int ( vp.size () ); ++j ) {
            for ( int k = j + 1; k < int ( vp.size () ); ++k ) {
                if ( in_same_line ( vp[i], vp[j], vp[k] ) ||
                     in_same_line ( vp[i], vp[k], vp[j] ) ||
                     in_same_line ( vp[k], vp[i], vp[j] ) ||
                     in_same_line ( vp[k], vp[j], vp[i] ) ||
                     in_same_line ( vp[j], vp[i], vp[k] ) ||
                     in_same_line ( vp[j], vp[k], vp[i] ) ) {
                    ++ans;
                }
            }
        }
    }
    printf ( "%d\n", ans );

    return 0;
}
