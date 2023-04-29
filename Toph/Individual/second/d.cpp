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

int main ( void ) {
    string s = read_string ();
    string bs = s;
    string ans = s;
    for ( auto &i : ans )
        i = 'a';
    string invalid = ans;
    string ns;
    for ( int i = 0; i < int ( s.length () ); ++i ) {
        for ( int j = 0; j < int ( s.length () ); ++j ) {
            ns = s;
            swap ( ns[i], ns[j] );
            if ( ns != s && ns[0] != '0' && ns > s ) ans = min ( ans, ns );
        }
    }
    map<char, int> mp;
    for ( auto i : s )
        mp[i]++;
    for ( int i = 0; i < int ( s.length () ); ++i ) {
        if ( mp[s[i]] > 1 ) {
            for ( int j = 0; j < int ( s.length () ); ++j ) {
                ns = s;
                ns[i] = s[j];
                if ( ns != s && ns[0] != '0' && ns > s ) ans = min ( ans, ns );
            }
        }
    }
    if ( ans != invalid )
        printf ( "%s\n", ans.c_str () );
    else
        puts ( "0" );
}

int main2 ( void ) {
    string s = read_string ();
    string bs = s;
    if ( s.length () == 1 ) {
        puts ( "0" );
        return 0;
    }
    for ( int i = int ( s.length () - 1 ); i > -1; --i ) {
        string ns = s;
        int ind = -1;
        int mx = 1000000000;
        for ( int j = int ( s.length () - 1 ); j > i; --j ) {
            if ( s[j] > s[i] && int ( s[j] - '0' ) < mx ) {
                ind = j;
                mx = int ( s[j] - '0' );
            }
        }
        if ( ind != -1 ) {
            swap ( ns[i], ns[ind] );
            if ( ns[0] != '0' && ns != bs ) {
                printf ( "%s\n", ns.c_str () );
                return 0;
            }
        }
    }
    puts ( "0" );

    return 0;
}
