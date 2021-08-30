#include "bits/stdc++.h"
using namespace std;

using ll = long long int;

int main ()
{
	int n, q;
	scanf ( "%d%d", &n, &q );
	int ar[n+5] = { };
	for ( int i = 0 ; i < n ; ++i ) {
		scanf ( "%d", &ar[i] );
	}
	for ( int i = 0 ; i < q ; ++i ) {
		int l, r, x;
		scanf ( "%d%d%d", &l, &r, &x );
		bool fnd = false;
		for ( int j = l ; j <= r ; ++j ) {
			if ( ar[j] == x ) fnd = true;
		}
		if ( fnd ) {
			puts("Yes" );
		} else {
			puts ( "No" );
		}
	}


	puts("");
	return 0;
}

