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

// clang-format

#define F  first
#define S  second
#define eb emplace_back

string read_string ( void ) {
    static char ch[1000005];
    scanf ( "%s", ch );
    return string ( ch );
}

using ll = long long int;

struct node {
    public:
        int count;
        array<int, 10> next{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
};

const int nax = 1000005, INF = 1e9 + 5;
node trie[nax];
int n, N = 0, ind, cur, Q;
string s;
vector<int> prio ( 10 );

void fix_string ( string &_s ) {
    reverse ( _s.begin (), _s.end () );
    while ( _s.length () < 7 )
        _s += '0';
    reverse ( _s.begin (), _s.end () );
}

void trie_push ( string &_s ) {
    cur = 0;
    for ( auto c : _s ) {
        ind = int ( c - '0' );
        if ( trie[cur].next[ind] == -1 ) {
            trie[cur].next[ind] = ++N;
            trie[N].count = 0;
        }
        ++trie[cur].count;
        cur = trie[cur].next[ind];
    }
        ++trie[cur].count;
}

int trie_get_ans ( string &st ) {
    cur = 0;
    int ans = 0;
    for ( int i = 0; i < int ( st.length () ); ++i ) {
        char c = st[i];
        ind = int ( c - '0' );
        for ( auto item : prio ) {
            if ( item == ind ) {
                cur = trie[cur].next[item];
                break;
            } else if ( trie[cur].next[item] != -1 )
                ans += trie[trie[cur].next[item]].count;
        }
    }
    return ans;
}

int main ( void ) {
    N = 0;
    trie[0].count = 0;
    scanf ( "%d", &n );
    for ( int i = 0; i < n; ++i ) {
        s = read_string ();
        fix_string ( s );
        trie_push ( s );
    }
    scanf ( "%d", &Q );
    while ( Q-- ) {
        for ( auto &item : prio )
            scanf ( "%d", &item );
        s = read_string ();
        fix_string ( s );
        printf ( "%d\n", trie_get_ans ( s ) );
    }

    return 0;
}
