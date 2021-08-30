#include <bits/stdc++.h>
using namespace std;

int ar[5] = { 1, 2, 3, 4, 5 };

void recur ( int me, int limit )
{
	if ( me >= limit ) return;
	if ( ar[me] > ar[0] ) ar[0] = ar[me];
	recur ( me+1, limit )
}

int find_max ( int me, int limit )
{
	if ( me >= limit ) return 0;
	return max ( ar[me], find_max ( me+1, limit ) );
}

int main() {
	recur ( 1, 5 );
	printf ( "%d", ar[0] );
	
	return 0;
}
