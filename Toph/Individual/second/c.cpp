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

int n, b;
vector<int> v;
unordered_map<int, int> ump;

int main ( void ) {
    scanf ( "%d%d", &n, &b );
    v.resize ( n );
    for ( auto &i : v )
        scanf ( "%d", &i );
    int bi = -1;
    for ( int i = 0; i < n; ++i ) {
        if ( v[i] == b ) {
            bi = i;
            break;
        }
    }
    ump.reserve ( 1 << 18 );
    assert ( bi != -1 );
    pair<int, int> cnts = make_pair<int, int> ( 0, 0 );
    for ( int i = bi + 1; i < n; ++i ) {
        if ( v[i] > b )
            cnts.S++;
        else
            cnts.F++;
        ++ump[cnts.F - cnts.S];
    }
    cnts = make_pair<int, int> ( 0, 0 );
    ll ans = 0;
    for ( int i = bi - 1; i > -1; --i ) {
        if ( v[i] > b )
            cnts.S++;
        else
            cnts.F++;
        int tval = cnts.F - cnts.S;
        if ( ump.find ( ( -1 * tval ) ) != ump.end () )
            ans += ump[( -1 * tval )];
        if ( tval == 0 ) ++ans;
    }
    if ( ump.find ( 0 ) != ump.end () ) ans += ump[0];
    printf ( "%lld\n", ans + 1 );

    return 0;
}
