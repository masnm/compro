#include <bits/stdc++.h>
using namespace std ;

string s = "14159265358979311600";

int main ( void )
{
	int t; scanf ( "%d", &t );
	while ( t-- ) {
		int n; scanf ( "%d", &n );
		int ans = 0;
		for ( int i = 0 ; i < n ; ++i )
			ans += int( s[i] - '0' );
		printf ( "%d\n", ans );
	}

	return 0 ;
}
