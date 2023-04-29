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

struct Applicant {
    public:
        ll cst;
        vector<int> lst;
        Applicant () = default;
        Applicant ( int _cst, vector<int> _lst ) : cst ( _cst ), lst ( _lst ) {
        }
        void init ( int _cst, vector<int> _lst ) {
            cst = _cst;
            lst = _lst;
        }
};

ll cost, cst;
int s, m, n;
vector<int> bt, t, lst;
vector<Applicant> appli;

vector<int> get_list ( void ) {
    char ch[100];
    scanf ( "%[^\n]", ch );
    string ss = string ( ch );
    int num = 0;
    vector<int> tlst;
    for ( auto i : ss ) {
        if ( i == ' ' ) {
            tlst.eb ( num );
            num = 0;
        } else {
            num *= 10;
            num += int ( i - '0' );
        }
    }
    if ( ss.back () != ' ' ) tlst.eb ( num );
    while ( *tlst.begin () == 0 )
        tlst.erase ( tlst.begin () );
    return tlst;
}

inline void solve () {
    bt.resize ( s );
    fill ( bt.begin (), bt.end (), 0 );
    t.resize ( s );
    fill ( t.begin (), t.end (), 0 );
    cost = 0;
    for ( int i = 0; i < m; ++i ) {
        scanf ( "%lld", &cst );
        cost += cst;
        lst = get_list ();
        for ( auto ii : lst )
            bt[ii - 1]++;
    }
    appli.resize ( n );
    for ( int i = 0; i < n; ++i ) {
        scanf ( "%lld", &cst );
        lst = get_list ();
        appli[i].init ( cst, lst );
    }
    ll ac = LLONG_MAX;
    for ( int i = 0; i < ( 1 << n ); ++i ) {
        t = bt;
        ll tcc = 0;
        for ( int j = 0; j < n; ++j ) {
            if ( i & ( 1 << j ) ) {
                for ( auto x : appli[j].lst )
                    t[x - 1]++;
                tcc += appli[j].cst;
            }
        }
        bool ok = true;
        for ( auto j : t )
            if ( j < 2 ) ok = false;
        if ( ok ) ac = min ( ac, tcc );
    }
    assert ( ac != LLONG_MAX );
    printf ( "%lld\n", ac + cost );
}

int main ( void ) {
    while ( true ) {
        scanf ( "%d%d%d", &s, &m, &n );
        if ( s == 0 ) break;
        solve ();
    }

    return 0;
}
