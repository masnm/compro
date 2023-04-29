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

int tod, n, ans;
vector<int> v;

int my_next ( int ind ) {
    if ( ind + 1 == n )
        return 0;
    else
        return ind + 1;
}
int my_prev ( int ind ) {
    if ( ind == 0 )
        return n - 1;
    else
        return ind - 1;
}

const int nax = 103;
int mp[nax][nax][nax][2];
bool func ( int left, int right, int ic, int who ) {
    int saved = mp[left][right][ic][who];
    if ( saved != -1 ) return ( saved == 0 );
    if ( left == right ) {
        if ( who == 0 && v[left] % 2 == 1 ) ic += 1;
        return ( ic > ( tod - ic ) );
    }
    bool ta = false, ba;
    if ( who == 0 ) {
        if ( v[left] & 1 ) {
            if ( func ( my_next ( left ), right, ic + 1, who ^ 1 ) ) ta = true;
        } else {
            if ( func ( my_next ( left ), right, ic, who ^ 1 ) ) ta = true;
        }
        if ( v[right] & 1 ) {
            if ( func ( left, my_prev ( right ), ic + 1, who ^ 1 ) ) ta = true;
        } else {
            if ( func ( left, my_prev ( right ), ic, who ^ 1 ) ) ta = true;
        }
        if ( ta ) {
            mp[left][right][ic][who] = 0;
        } else {
            mp[left][right][ic][who] = 1;
        }
        return ta;
    } else {
        if ( func ( my_next ( left ), right, ic, who ^ 1 ) == false ) ta = true;
        if ( func ( left, my_prev ( right ), ic, who ^ 1 ) == false ) ta = true;
        if ( ta ) {
            mp[left][right][ic][who] = 1;
            return false;
        } else {
            mp[left][right][ic][who] = 0;
            return true;
        }
    }
}

int main ( void ) {
    for ( int i = 0; i < nax; ++i )
        for ( int j = 0; j < nax; ++j )
            for ( int k = 0; k < nax; ++k )
                mp[i][j][k][0] = mp[i][j][k][1] = -1;
    scanf ( "%d", &n );
    v.resize ( n );
    for ( auto &i : v )
        scanf ( "%d", &i );
    tod = 0;
    for ( auto &i : v )
        if ( i & 1 ) ++tod;
    ans = 0;
    for ( int i = 0; i < n; ++i ) {
        int ic = ( v[i] % 2 == 1 ? 1 : 0 );
        if ( func ( my_next ( i ), my_prev ( i ), ic, 1 ) ) ++ans;
    }
    printf ( "%d\n", ans );

    return 0;
}
