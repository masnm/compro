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

const int CN = 100000, CQ = 100000;
const int nl = 6;
const int nax = 100005;
string s;
int trie[nax][10], cost[nax];
int n, q, cur, N, ind, num;
vector<int> prio ( 10 );

void trie_push ( string &st )
{
    cur = 0;
    for ( auto c : st ) {
        ind = int(c - '0');
        if ( trie[cur][ind] == 0 ) trie[cur][ind] = ++N;
        ++cost[trie[cur][ind]];
        cur = trie[cur][ind];
    }
}

int trie_get ( string &st )
{
    cur = 0;
    int ans = 0;
    for ( auto c : st ) {
        ind = int(c - '0');
        for ( auto ni : prio ) {
            if ( ni == ind ) {
                break;
            }
            if ( trie[cur][ni] != 0 )
                ans += cost[trie[cur][ni]];
        }
        if ( trie[cur][ind] == 0 ) break;
        cur = trie[cur][ind];
    }
    return ans;
}

int main ( void )
{
    N = 0;
    scanf ( "%d", &n );
    assert ( n <= 100000 );
    for ( int i = 0; i < n; ++i ) {
        scanf ( "%d", &num );
        assert ( num <= 100000 );
        s = to_string ( num );
        reverse ( s.begin(), s.end() );
        while ( s.length() < nl ) s += '0';
        reverse ( s.begin(), s.end() );
        trie_push ( s );
    }
    scanf ( "%d", &q );
    assert ( q <= 100000 );
    for ( int qq = 0; qq < q; ++qq ) {
        for ( int i = 0; i < 10; ++i ) {
            scanf ( "%d", &num );
            assert ( num < 10 && num > -1 );
            s = to_string ( num );
            assert ( s.length() == 1 );
            prio[i] = int(s[0] - '0');
        }
        scanf ( "%d", &num );
        assert ( num <= 100000 );
        s = to_string ( num );
        reverse ( s.begin(), s.end() );
        while ( s.length() < nl ) s += '0';
        reverse ( s.begin(), s.end() );
        printf ( "%d\n", trie_get ( s ) );
    }

	return 0;
}

