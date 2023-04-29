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

class JimmyLightning {
    public:
        static const int bax = 1005, nax = 52, inf = 1e8 + 5;
        int n, m;
        int memo[bax][nax][nax];
        vector<int> mins;
        vector<tuple<int, int, int>> vtp;
        int find_ans ( int c_time, int c_item, int p_item ) {
            if ( memo[c_time][c_item][p_item] != -1 )
                return memo[c_time][c_item][p_item];
            if ( mins[get<2> ( vtp[p_item] ) - 1] < c_time )
                return memo[c_time][c_item][p_item] = -inf;
            if ( c_item >= int ( vtp.size () ) ) return 0;

            // taking current item
            int ans = get<0> ( vtp[c_item] ) +
                      find_ans ( c_time + get<1> ( vtp[c_item] ), c_item + 1,
                                 c_item );

            ans = max ( ans, get<0> ( vtp[c_item] ) +
                                 find_ans ( c_time + get<1> ( vtp[c_item] ),
                                            c_item, c_item ) );
            if ( c_item > 0 )
                ans = max ( ans, get<0> ( vtp[c_item] ) +
                                     find_ans ( c_time + get<1> ( vtp[c_item] ),
                                                c_item - 1, c_item ) );

            // not taking current item
            ans = max ( ans, find_ans ( c_time, c_item + 1, p_item ) );

            return memo[c_time][c_item][p_item] = ans;
        }
        int robTheBank ( vector<int> doors, vector<string> diamonds ) {
            n = int ( doors.size () );
            m = int ( diamonds.size () );
            for ( int i = 0; i < bax; ++i )
                for ( int j = 0; j < nax; ++j )
                    for ( int k = 0; k < nax; ++k )
                        memo[i][j][k] = -1;
            vtp.resize ( m );
            for ( int i = 0; i < m; ++i ) {
                int v, t, r;
                sscanf ( diamonds[i].c_str (), "%d %d %d", &v, &t, &r );
                vtp[i] = tie ( v, t, r );
            }
            // vtp.insert ( vtp.begin (), tuple<int, int, int> ( 0, 0, 0 ) );
            mins.resize ( n );
            mins[0] = doors[0];
            for ( int i = 1; i < n; ++i )
                mins[i] = min ( doors[i], mins[i - 1] );
            return find_ans ( 1, 0, 0 );
        }
};

int main ( void ) {
    vector<int> v;
    vector<string> vs;
    int n, m;
    scanf ( "%d", &n );
    v.resize ( n );
    for ( auto &i : v )
        scanf ( "%d", &i );
    scanf ( "%d", &m );
    vs.resize ( m );
    char ch[25];
    for ( auto &i : vs ) {
        scanf ( " %[^\n]", ch );
        i = string ( ch );
    }
    JimmyLightning jl;
    cout << "Ans: " << jl.robTheBank ( v, vs ) << endl;

    return 0;
}
