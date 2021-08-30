#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long int ll;
typedef unsigned long long ull;

int main ()
{
	int n, m; scanf ( "%d%d", &n, &m );
	string ev, od;
	for ( int i = 0 ; i < m ; ++i ) {
		ev += '#';
		od += '.';
	}
	od[m-1] = '#';
	for ( int i = 0 ; i < n ; ++i ) {
		if ( i & 1 ) {
			printf ( "%s", od.c_str() );
			swap ( od[0], od[m-1] );
		} else {
			printf ( "%s", ev.c_str() );
		}
		puts("");
	}

	return 0;
}
