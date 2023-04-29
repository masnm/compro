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
vector<int> a, b, c, ok;

inline void solve ( int _case ) {
    scanf ( "%d", &n );
    a.resize ( n );
    for ( auto &i : a )
        scanf ( "%d", &i );
    b.resize ( n );
    for ( auto &i : b )
        scanf ( "%d", &i );
    c.resize ( n );
    c[0] = 1;
    ok.resize ( n );
    for ( int i = 0; i < n; ++i )
        ok[i] = ( a[i] == b[i] ? 0 : 1 );
    for ( int i = 1; i < n; ++i )
        ok[i] = ok[i] + ok[i - 1];
    for ( int i = 1; i < n; ++i ) {
        if ( b[i] < b[i - 1] )
            c[i] = 1;
        else
            c[i] = c[i - 1] + 1;
    }
    int mx = 0, mi = -1;
    for ( int i = n - 1; i > -1; --i ) {
        int sum = ok.back ();
        sum -= ok[i];
        int si = i - c[i];
        if ( si > -1 ) sum += ok[si];
        if ( sum < 1 && c[i] > mx ) {
            mx = c[i];
            mi = i;
        }
    }
    printf ( "%d %d\n", mi - mx + 2, mi + 1 );
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
