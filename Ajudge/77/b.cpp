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

vector<pair<int, ll>> v;

void pre ( void ) {
    ll fac = 1;
    v.eb ( 0, fac );
    for ( ll i = 1; i < 20; ++i ) {
        fac *= i;
        v.eb ( i, fac );
    }
}

ll n;
vector<int> ans;

inline void solve ( int _case ) {
    ans.clear ();
    scanf ( "%lld", &n );
    for ( int i = 19; i > -1; --i ) {
        if ( n >= v[i].S ) {
            ans.eb ( v[i].F );
            n -= v[i].S;
        }
    }
    reverse ( ans.begin (), ans.end () );
    if ( n != 0 ) {
        puts ( "impossible" );
    } else {
        for ( int i = 0; i < int ( ans.size () ); ++i ) {
            if ( i != 0 ) printf ( "+" );
            printf ( "%d!", ans[i] );
        }
        puts ( "" );
    }
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
