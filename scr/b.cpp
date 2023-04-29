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
vector<int> v;

int main ( void ) {
    scanf ( "%d", &n );
    v.resize ( n );
    for ( auto &i : v )
        scanf ( "%d", &i );
    sort ( v.begin (), v.end () );
    int t;
    debug () << imie ( v );
    scanf ( "%d", &t );
    while ( t-- ) {
        int tar;
        scanf ( "%d", &tar );
        if ( tar < v[0] ) {
            printf ( "0\n" );
            continue;
        }
        if ( tar >= v.back () ) {
            printf ( "%zu\n", v.size () );
            continue;
        }
        int low = 0, high = v.size () - 1, mid;
        while ( low < high ) {
            mid = ( high + low ) / 2;
            if ( v[mid] == tar ) {
                low = mid;
                high = mid;
            } else if ( v[mid] > tar ) {
                high = mid - 1;
            } else {
                low = mid;
            }
        }
        printf ( "%d\n", low + 1 );
    }

    return 0;
}
