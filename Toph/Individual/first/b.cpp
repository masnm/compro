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

const vector<pair<int, int>> stps = {
    { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

const int nax = 55;
string s;
int r, c, ans;
int state[505][nax][nax];
bool vis[505][nax][nax];
pair<int, int> start, finish;
vector<tuple<int, int, int>> q;

void calculate_flood ( void ) {
    for ( int i = 1; i < 505; ++i ) {
        for ( int j = 0; j < nax - 1; ++j ) {
            for ( int k = 0; k < nax - 1; ++k ) {
                state[i][j][k] = state[i - 1][j][k];
            }
        }
        for ( int j = 0; j < nax - 1; ++j ) {
            for ( int k = 0; k < nax - 1; ++k ) {
                if ( state[i - 1][j][k] == 1 ) {
                    for ( auto stp : stps ) {
                        stp.F += j;
                        stp.S += k;
                        if ( stp.F < 0 || stp.S < 0 ) continue;
                        if ( stp.F >= r || stp.S >= c ) continue;
                        if ( stp == finish ) continue;
                        if ( state[i][stp.F][stp.S] != 0 ) continue;
                        state[i][stp.F][stp.S] = 1;
                    }
                }
            }
        }
    }
}

void bfs ( void ) {
    ans = -1;
    q.eb ( start.F, start.S, 1 );
    for ( int i = 0; i < int ( q.size () ); ++i ) {
        tuple<int, int, int> cp = q[i];
        if ( vis[get<2> ( cp )][get<0> ( cp )][get<1> ( cp )] ) continue;
        vis[get<2> ( cp )][get<0> ( cp )][get<1> ( cp )] = true;
        if ( finish.F == get<0> ( cp ) && finish.S == get<1> ( cp ) ) {
            ans = get<2> ( cp );
            break;
        }
        for ( auto stp : stps ) {
            stp.F += get<0> ( cp );
            stp.S += get<1> ( cp );
            if ( stp.F < 0 || stp.S < 0 ) continue;
            if ( stp.F >= r || stp.S >= c ) continue;
            if ( !vis[get<2> ( cp )][stp.F][stp.S] &&
                 state[get<2> ( cp )][stp.F][stp.S] == 0 )
                q.eb ( stp.F, stp.S, get<2> ( cp ) + 1 );
        }
    }
}

int main ( void ) {
    scanf ( "%d%d", &r, &c );
    for ( int i = 0; i < r; ++i ) {
        s = read_string ();
        for ( int j = 0; j < c; ++j ) {
            if ( s[j] == 'S' )
                start = { i, j };
            else if ( s[j] == 'D' )
                finish = { i, j };
            else if ( s[j] == 'X' )
                state[0][i][j] = -1;
            else if ( s[j] == '*' )
                state[0][i][j] = 1;
        }
    }
    calculate_flood ();
    bfs ();
    if ( ans == -1 ) {
        puts ( "KAKTUS" );
    } else {
        printf ( "%d\n", ans - 1 );
    }

    return 0;
}
