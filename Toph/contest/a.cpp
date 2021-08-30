#include "bits/stdc++.h"
using namespace std;

using ll = long long int;

int main ()
{
	int n = 1000000;
	for ( int i = 0 ; i < n ; ++i ) {
		if ( i%2==1 && i%3==2 && i%4==3 && i%5==4 && i%6==5 && i%7==6 ) {
			printf ( "%d", i);
			return 0;
		}
	}
	assert ( false );


	puts("");
	return 0;
}

