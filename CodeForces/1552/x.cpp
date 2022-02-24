#include "bits/stdc++.h"
using namespace std;

int main ()
{
	int n = 4, tn = 1;
	for ( int i = 0 ; i < n ; ++i ) tn *= 3;
	for ( int mask = 0 ; mask < tn ; ++mask ) {
		int mc = mask;
		for ( int i = 0 ; i < n ; ++i ) {
			printf ( "%d", mc % 3 );
			mc /= 3;
		}
		puts ( "" );
	}
	
	return 0;
}
