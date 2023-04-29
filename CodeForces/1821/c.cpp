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

const int nax = 200005;
vector<int> pa ( nax );
void pre ( void ) {
    pa[0] = pa[1] = 1;
    for ( int i = 2; i < nax; ++i )
        pa[i] = pa[i / 2] + 1;
}

string s;

int solve_for ( char ch ) {
    int ans = 0;
    for ( int i = 0; i < int ( s.length () ); ++i ) {
        if ( s[i] == ch ) continue;
        int j;
        for ( j = i; j < int ( s.length () ); ++j )
            if ( s[j] == ch ) break;
        ans = max ( ans, pa[j - i] );
        i = j;
    }
    return ans;
}

inline void solve ( int _case ) {
    s = read_string ();
    int ans = INT_MAX;
    for ( char ch = 'a'; ch <= 'z'; ++ch ) {
        ans = min ( ans, solve_for ( ch ) );
    }
    printf ( "%d\n", ans );
}

int main ( void ) {
    pre ();
    int _t = 1;
    scanf ( "%d", &_t );
    for ( int i = 0; i < _t; ++i ) {
        // printf ( "Case %d: ", i + 1 );
        solve ( i + 1 );
    }

    return 0;
}
