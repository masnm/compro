#include <bits/stdc++.h>
using namespace std;

int main ( void )
{
	int t; scanf ( "%d", &t );
	while ( t-- ) {
		vector<int> v ( 3 );
		for ( auto& i : v ) scanf ( "%d", &i );
		sort ( v.begin(), v.end() );
		printf ( "%d\n", v[1] );
	}
	return 0;
}
