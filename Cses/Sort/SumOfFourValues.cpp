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

ll n, target, need;
vector<ll> v;
vector<tuple<ll, int, int>> sms;

bool ok ( tuple<ll, int, int> &l, auto it ) {
    if ( it == sms.end () || get<0> ( *it ) != need ) return false;
    if ( get<1> ( l ) == get<1> ( *it ) || get<1> ( l ) == get<2> ( *it ) ||
         get<2> ( l ) == get<1> ( *it ) || get<2> ( l ) == get<2> ( *it ) )
        return false;
    printf ( "%d %d %d %d\n", get<1> ( l ), get<2> ( l ), get<1> ( *it ),
             get<2> ( *it ) );
    return true;
}

int main ( void ) {
    scanf ( "%lld%lld", &n, &target );
    v.resize ( n );
    for ( auto &i : v )
        scanf ( "%lld", &i );
    sms.resize ( n * n );
    for ( int i = 0; i < n; ++i )
        for ( int j = i + 1; j < n; ++j )
            sms.eb ( v[i] + v[j], i + 1, j + 1 );
    sort ( sms.begin (), sms.end () );
    for ( int i = 0; i < n * n; ++i ) {
        need = need - get<0> ( sms[i] );
        if ( ok ( sms[i], lower_bound ( sms.begin (), sms.end (), need,
                                        [] ( auto &l, auto &r ) {
                                            return get<0> ( l ) < r;
                                        } ) ) ) {
            return 0;
        }
    }
    puts ( "IMPOSSIBLE" );

    return 0;
}
