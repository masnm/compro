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
using ld = long double;

const int nax = 25;
int n, t;
long double inp[nax][nax];

void read_input ( void ) {
    scanf ( "%d", &n );
    for ( int i = 0; i < n; ++i )
        for ( int j = 0; j < n; ++j ) {
            scanf ( "%d", &t );
            inp[i][j] = ld ( t ) / ld ( 100 );
        }
}

unordered_map<int, ld> mp;
unordered_map<int, ld> smp;

int main ( void ) {
    read_input ();
    mp.reserve ( 1 << 20 );
    smp.reserve ( 1 << 20 );

    for ( int i = 0; i < n; ++i )
        mp[1 << i] = inp[0][i];
    for ( int i = 1; i < n; ++i ) {
        smp.clear ();
        for ( auto item : mp ) {
            for ( int x = 0; x < n; ++x ) {
                if ( ( item.F & ( 1 << x ) ) == 0 ) {
                    smp[item.F | ( 1 << x )] =
                        max ( smp[item.F | ( 1 << x )], item.S * inp[i][x] );
                }
            }
        }
        mp = smp;
    }
    long double mx = ld ( 0 );
    for ( auto item : mp )
        mx = max ( mx, item.S );
    printf ( "%LF\n", mx * ld ( 100 ) );

    return 0;
}
