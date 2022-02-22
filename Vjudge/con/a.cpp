#include "bits/stdc++.h"
using namespace std;

int n = 100005;

int cnt ( int a )
{
	int cnt = 0, s = 1<<31;
	for ( int i = 31 ; i > -1 ; --i )
		if ( a & (1<<i) )
			return 31 - i;
	return 32;
}

int main ()
{
	int h = sizeof(int) * 8 - __builtin_clz(10);
	int h2 = sizeof(int) * 8 - cnt(10);
	cout << h << " " << h2 << endl;
	return 0;
}
