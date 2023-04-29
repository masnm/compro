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

// trie part start
const int mod = 5000000;
const int tnax = 1 << 14;
int tree[2 * tnax];

void trie_clear ( void ) {
    for ( int i = 0; i < 2 * tnax; ++i )
        tree[i] = 0;
}

void trie_add ( int index, int val ) {
    index += tnax;
    tree[index] += val;
    for ( index >>= 1; index > 0; index >>= 1 ) {
        tree[index] = tree[2 * index] + tree[2 * index + 1];
        tree[index] %= mod;
    }
}

int trie_get ( int low, int high ) {
    int _ans = 0;
    low += tnax;
    high += tnax;
    for ( ; low < high; low >>= 1, high >>= 1 ) {
        if ( low & 1 ) _ans += tree[low++];
        if ( high & 1 ) _ans += tree[--high];
        _ans %= mod;
    }
    return _ans % mod;
}
// trie part end

int n, k, digits;
vector<int> v, temp, ans, ca;
vector<int> g[tnax];

void read_input ( void ) {
    scanf ( "%d%d", &n, &k );
    v.resize ( n );
    for ( auto &i : v )
        scanf ( "%d", &i );
}

void compress ( void ) {
    temp = v;
    sort ( temp.begin (), temp.end () );
    temp.resize ( unique ( temp.begin (), temp.end () ) - temp.begin () );
    for ( auto &i : v )
        i = int ( lower_bound ( temp.begin (), temp.end (), i ) -
                  temp.begin () );
    digits = temp.size ();
    for ( int i = 0; i < n; ++i ) {
        g[v[i]].eb ( i );
    }
}

void process_data ( void ) {
    ans.resize ( n );
    fill ( ans.begin (), ans.end (), 1 );
    ca.resize ( n );
    --k;
    while ( k-- ) {
        ca = ans;
        fill ( ans.begin (), ans.end (), 0 );
        trie_clear ();
        for ( int i = digits - 1; i > -1; --i ) {
            for ( auto index : g[i] ) {
                ans[index] += trie_get ( index, tnax );
                ans[index] %= mod;
            }
            for ( auto index : g[i] ) {
                trie_add ( index, ca[index] );
            }
        }
    }
    int _ans = 0;
    for ( auto _an : ans ) {
        _ans += _an;
        _ans %= mod;
    }
    printf ( "%d\n", _ans % mod );
}

int main ( void ) {
    read_input ();
    compress ();
    process_data ();

    return 0;
}
