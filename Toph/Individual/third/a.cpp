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

int na, nb, t, ind;
string a, b;
vector<pair<char, int>> vp;

int main ( void ) {
    scanf ( "%d%d", &na, &nb );
    a = read_string ();
    b = read_string ();
    reverse ( a.begin (), a.end () );
    scanf ( "%d", &t );
    for ( int i = 0; i < na; ++i )
        b.insert ( b.begin (), '0' );
    for ( int i = 0; i < 100; ++i )
        a.insert ( a.begin (), '0' );
    for ( int i = 0; i < 100; ++i )
        b.insert ( b.begin (), '0' );
    b = b.substr ( t );
    while ( a.length () != b.length () ) {
        if ( a.length () < b.length () )
            a += '0';
        else
            b += '0';
    }
    for ( int i = 0; i < int ( a.length () ); ++i ) {
        if ( b[i] != '0' ) printf ( "%c", b[i] );
        if ( a[i] != '0' ) printf ( "%c", a[i] );
    }

    return 0;
}
