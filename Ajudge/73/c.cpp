#include "bits/stdc++.h"
using namespace std;

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

#define F first
#define S second
#define eb emplace_back

string read_string ( void )
{
	static char ch[1000005];
	scanf ( "%s", ch );
	return string ( ch );
}

using ll = long long int;

const int nax = 5005;
unordered_map <string,int> mp;
int C, R, N, l, r, mxc, mxn;
vector<int> g[nax];
pair<int,int> cp;
vector<pair<int,int>> q;
vector<bool> vis ( nax );

inline void solve ( int _case )
{
    (void) _case;
    mp.clear();
    N = 0;
    for ( int i = 0 ; i < C ; ++i )
        mp[read_string()] = N++;
    for ( int i = 0 ; i < R ; ++i ) {
        l = mp[read_string()]; r = mp[read_string()];
        g[l].eb ( r ); g[r].eb ( l );
    }
    mxc = 0; mxn = 0;
    q.clear(); q.eb ( 0, 0 );
    for ( int i = 0 ; i < int(q.size()); ++i ) {
        cp = q[i];
        if ( vis[cp.F] ) continue;
        vis[cp.F] = true;
        if ( cp.S > mxc ) { mxc = cp.S; mxn = cp.F; }
        for ( auto &next : g[cp.F] )
            if ( !vis[next] )
                q.eb ( next, cp.S + 1 );
    }
    fill ( vis.begin(), vis.end(), false );
    q.clear();
    q.eb ( mxn, 0 );
    for ( int i = 0 ; i < int(q.size()); ++i ) {
        cp = q[i];
        if ( vis[cp.F] ) continue;
        vis[cp.F] = true;
        if ( cp.S > mxc ) { mxc = cp.S; mxn = cp.F; }
        for ( auto &next : g[cp.F] )
            if ( !vis[next] )
                q.eb ( next, cp.S + 1 );
    }
    printf ( "%d\n", mxc + 1 );
}

int main ( void )
{
    mp.reserve ( 7000 );
    fill ( vis.begin(), vis.end(), false );
	int _t = 1;
    while ( true ) {
        scanf ( "%d%d", &C, &R );
        if ( C == R && C == 0 ) break;
//		printf ( "Case %d: ", i+1 );
		solve ( _t );
	}


	return 0;
}

