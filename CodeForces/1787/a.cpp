#include "bits/stdc++.h"
using namespace std;

using ll = long long int;

inline void solve ( int _case ) {
    ll n;
    scanf ( "%lld", &n );
    if ( !( n & 1LL ) ) {
        printf ( "%lld %lld\n", 1, n / 2LL );
    } else {
        puts ( "-1" );
    }
}

int main ( void ) {
    int _t = 1;
    scanf ( "%d", &_t );
    for ( int i = 0; i < _t; ++i ) {
        //		printf ( "Case %d: ", i+1 );
        solve ( i + 1 );
    }

    return 0;
}
