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

int r, c;
vector<string> vs;

void clear_wall ( int _r, int _c, int dis ) {
    for ( int i = 0; i < r; ++i ) {
        for ( int j = 0; j < c; ++j ) {
            if ( vs[i][j] == '#' && ( abs ( i - _r ) + abs ( j - _c ) <= dis ) )
                vs[i][j] = '.';
        }
    }
    vs[_r][_c] = '.';
}

int main ( void ) {
    scanf ( "%d%d", &r, &c );
    vs.resize ( r );
    for ( auto &i : vs )
        i = read_string ();
    for ( int i = 0; i < r; ++i ) {
        for ( int j = 0; j < c; ++j ) {
            if ( vs[i][j] >= '1' && vs[i][j] <= '9' ) {
                clear_wall ( i, j, int ( vs[i][j] - '0' ) );
            }
        }
    }
    for ( auto &i : vs )
        printf ( "%s\n", i.c_str () );

    return 0;
}
