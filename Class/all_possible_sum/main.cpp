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

int N, sum;
vector<int> arr;

int iterative ( void ) {
    scanf ( "%d%d", &N, &sum );
    arr.resize ( N );
    for ( auto &i : arr )
        scanf ( "%d", &i );
    for ( int i = 0; i < ( 1 << N ); i++ ) {
        int tar_sum = 0;
        for ( int j = 0; j < N; ++j ) {
            if ( i & ( 1 << j ) ) {
                tar_sum += arr[j];
            }
        }
        if ( tar_sum == sum ) {
            printf ( "Ans found\n" );
        }
    }
    printf ( "Ans Not found" );

    return 0;
}

vector<bool> bits;
bool ans_found;
// [ 0, 0, 0 ]
//
// [ 0, 0, 0 ]
// [ 0, 0, 1 ]
//
// [ 0, 1, 0 ]
// [ 0, 1, 1 ]
//
// [ 1, 0, 0 ]
// [ 1, 0, 1 ]

void rcur ( int current_bit, int total_bit ) {
    if ( current_bit >= total_bit ) {
        // ending case
        int tar_sum = 0;
        for ( int i = 0; i < total_bit; ++i ) {
            if ( bits[i] == true ) {
                tar_sum += arr[i];
            }
        }
        if ( tar_sum == sum ) ans_found = true;
    } else {
        bits[current_bit] = false;
        rcur ( current_bit + 1, total_bit );
        bits[current_bit] = true;
        rcur ( current_bit + 1, total_bit );
    }
}

int recursive ( void ) {
    scanf ( "%d%d", &N, &sum );
    arr.resize ( N );
    for ( auto &i : arr )
        scanf ( "%d", &i );
    bits.resize ( N );
    fill ( bits.begin (), bits.end (), false );
    ans_found = false;
    rcur ( 0, N );
    if ( ans_found == true )
        puts ( "Ans found\n" );
    else
        puts ( "Ans Not found\n" );
}

//     N <= 20
//     a1  a2  a3   a4   a5
//     summation
//     10  121
//     1 43  12 434 12 43 12 43 12
//     `
//     0000
//     0001
//     0010
//     0011
//     0100
//     0101
