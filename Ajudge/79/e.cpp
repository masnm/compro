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
    char ch[120];
    scanf ( "%s", ch );
    return string ( ch );
}

using ll = long long int;

map<string, vector<string>> mp;
string s;
int n;

void add_list ( string ss ) {
    char ch[205];
    scanf ( "%[^\n]", ch );
    string t = string ( ch );
    string sss = string ( "" );
    for ( auto i : t ) {
        if ( i == ' ' ) {
            mp[ss].eb ( sss );
            sss = string ( "" );
        } else {
            sss += i;
        }
    }
    if ( t.back () != ' ' ) mp[ss].eb ( sss );
    for ( int i = int ( mp[ss].size () - 1 ); i > -1; --i ) {
        if ( mp[ss][i] == string ( "" ) )
            mp[ss].erase ( mp[ss].erase ( mp[ss].begin () + i ) );
    }
}

vector<pair<int, string>> vs;

int main ( void ) {
    scanf ( "%d", &n );
    for ( int i = 0; i < n; ++i ) {
        s = read_string ();
        add_list ( s );
    }
    for ( auto i : mp ) {
        vs.eb ( i.S.size (), i.F.c_str () );
    }
    sort ( vs.begin (), vs.end (), [] ( auto &l, auto &r ) {
        return tie ( l.S, l.F ) < tie ( r.S, r.F );
    } );
    for ( auto i : vs )
        cout << i.S << " " << i.F << "\n";

    return 0;
}
