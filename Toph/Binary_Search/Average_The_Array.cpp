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

int n, q;
ll lim, ta;
vector<ll> v, ps;

inline void solve ( ll _lm ) {
    int low = 0, high = n - 1, mid;
    // for ( int i = 0; i < 32; ++i ) {
    while ( low < high ) {
        mid = ( high + low + 1) / 2;
        ta = ps[mid] / (mid + 1);
        // debug() << imie(low) imie(high) imie(mid) imie(_lm) imie(ta);
        if ( ta >= _lm )
            high = mid - 1;
        else
            low = mid;
    }
    if ( (ps[low] / (low + 1)) < _lm )
        printf ( "%d\n", low + 1 );
    else
        printf ( "0\n" );
}

int main ( void ) {
    scanf ( "%d", &n );
    v.resize ( n );
    for ( auto &i : v ) scanf ( "%lld", &i );
    sort ( v.begin(), v.end() );
    ps.resize ( n );
    partial_sum ( v.begin(), v.end(), ps.begin() );
    scanf ( "%d", &q );
    while ( q-- ) {
        scanf ( "%lld\n", &lim );
        solve ( lim );
    }

    return 0;
}

