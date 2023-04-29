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

string s, back_s;

void stl_purmutation ( void ) {
    back_s = s;
    string max_s = s;
    for ( auto &i : max_s )
        i = '9';
    sort ( s.begin (), s.end () );
    do {
        if ( s > back_s ) {
            max_s = min ( max_s, s );
        }
    } while ( next_permutation ( s.begin (), s.end () ) );

    bool ok = false;
    for ( auto i : max_s ) {
        if ( i != '9' ) ok = true;
    }
    if ( ok )
        cout << max_s << endl;
    else
        cout << "0" << endl;
}

string current, backup, max_s;
vector<bool> used;

void recur ( int current_ind, int target_ind ) {
    if ( current_ind >= target_ind ) {
        if ( current > backup ) {
            max_s = min ( max_s, current );
        }
        return;
    }
    for ( int i = 0; i < int ( s.length () ); ++i ) {
        if ( used[i] == false ) {
            used[i] = true;
            current += s[i];
            recur ( current_ind + 1, target_ind );
            current.pop_back ();
            used[i] = false;
        }
    }
}

void recursive_purmutation ( void ) {
    backup = s;
    int size = s.length ();
    max_s = s;
    for ( auto &i : max_s )
        i = '9';
    used.resize ( size );
    fill ( used.begin (), used.end (), false );
    current = "";

    recur ( 0, size );

    bool ok = false;
    for ( auto i : max_s ) {
        if ( i != '9' ) ok = true;
    }
    if ( ok )
        cout << max_s << endl;
    else
        cout << "0" << endl;
}

int main ( void ) {
    cin >> s;
    // stl_purmutation ();
    recursive_purmutation ();

    return 0;
}

//  321012
//
//  max_s 321012
//  max_s 999999
//
//  322101
//  321021
