#include "bits/stdc++.h"
using namespace std;

using ll = long long int;

int power ( int a, int b )
{
	int result = 1;
	while ( b > 0 ) {
		if ( b&1 ) result *= a;
		a *= a;
		b /= 2;
	}
	return result;
}

int main ()
{
	int a = 3, n = 4;
	int sa = 0, sb = 0;
	int sm = 0;
	for ( int i = 1 ; i < n ; ++i ) {
		sm += power ( a, i );
	}
	cout << ((power(a,n)-1)/(a-1))-1 << endl;
	cout << sm << endl;


	puts("");
	return 0;
}

