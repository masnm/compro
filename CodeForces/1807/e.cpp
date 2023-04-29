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
vector<ll> v, ps;

ll query_sum ( int low, int mid ) {
    printf ( "? %d", mid - low + 1 );
    for ( int i = 0; low + i <= mid; ++i ) {
        printf ( " %d", low + i );
    }
    cout << endl;
    fflush ( stdout );
    ll sum;
    scanf ( "%lld", &sum );
    return sum;
}

ll ps_sum ( int low, int mid ) {
    return ps[mid - 1] - ( low < 2 ? 0 : ps[low - 2] );
}

inline void solve ( int _case ) {
    scanf ( "%d", &n );
    v.resize ( n );
    for ( auto &i : v )
        scanf ( "%lld", &i );
    ps.resize ( n );
    partial_sum ( v.begin (), v.end (), ps.begin () );
    int low = 1, high = n, mid;
    ll cnt = 0;
    while ( low < high ) {
        assert ( cnt < 30 );
        mid = ( high + low ) / 2;
        if ( query_sum ( low, mid ) != ps_sum ( low, mid ) )
            high = mid;
        else
            low = mid + 1;
        ++cnt;
    }
    printf ( "! %d\n", low );
    fflush ( stdout );
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
