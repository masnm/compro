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

map<string, int> mp;
void pre ( void ) {
    string start = "A";
    for ( int i = 0; i < 1005; ++i ) {
        mp[start] = i;
        int ui = start.length () - 1;
        while ( true ) {
            if ( ui < 0 ) {
                start.insert ( start.begin (), 'A' );
                break;
            }
            if ( start[ui] < 'Z' ) {
                start[ui]++;
                break;
            } else {
                start[ui] = 'A';
                --ui;
            }
        }
    }
}

enum Type { value, formula };

typedef long long ( *Operation ) ( long long a, long long b );

struct Formula {
    public:
        pair<int, int> left, right;
        Operation operation;
        Formula ( string formula ) {
            auto get_row_col = [] ( string s, string::size_type n ) {
                string _l, _r;
                for ( auto c : s ) {
                    if ( c >= 'A' && c <= 'Z' )
                        _l += c;
                    else if ( c >= '0' && c <= '9' )
                        _r += c;
                }
                int _ll = mp[s.substr ( 0, n )], _rr = 0;
                for ( auto c : _r ) {
                    _rr *= 10;
                    _rr += int ( c - '0' );
                }
                return make_pair ( _ll, _rr );
            };
            assert ( formula[0] == '=' );
            formula.erase ( 0, 1 );
            if ( formula.find ( "+" ) != string::npos ) {
                auto n = formula.find ( "+" );
                left = get_row_col ( formula.substr ( 0, n ), n );
                right = get_row_col ( formula.substr ( n + 1 ),
            } else if ( formula.find ( "-" ) != string::npos ) {
                auto n = formula.find ( "-" );
            } else if ( formula.find ( "*" ) != string::npos ) {
                auto n = formula.find ( "*" );
            } else if ( formula.find ( "/" ) != string::npos ) {
                auto n = formula.find ( "/" );
            } else
                assert ( false );
        }
};

struct cell {
    public:
        Type type;
        union {
                long long value;
                Formula formula;
        };
};

inline void solve ( int _case ) {
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
