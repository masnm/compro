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

const int nax = 1000;
vector<pair<int, int>> all;

void pre ( void ) {
    all.resize ( nax );
    for ( auto &i : all )
        i.F = i.S = 0;
    for ( int i = 1; i <= nax; ++i )
        for ( int j = 1; j <= i; ++j )
            if ( i % j == 0 ) all[i - 1].S++;
    for ( int i = 0; i < nax; ++i )
        all[i].F = i;
    sort ( all.begin (), all.end (), [] ( auto &l, auto &r ) {
        return tie ( l.S, r.F ) < tie ( r.S, l.F );
    } );
}

int n;

inline void solve ( int _case ) {
    scanf ( "%d", &n );
    printf ( "%d\n", all[n - 1].F + 1 );
}

int main ( void ) {
    pre ();
    int _t = 1;
    scanf ( "%d", &_t );
    for ( int i = 0; i < _t; ++i ) {
        printf ( "Case %d: ", i + 1 );
        solve ( i + 1 );
    }

    return 0;
}
