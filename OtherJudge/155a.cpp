#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long int ll;
typedef unsigned long long ull;

int main ()
{
	int n; scanf("%d",&n);
	vector<int> v ( n );
	for ( int& i : v ) scanf("%d",&i);
	int an = 0, ms = v[0], mm = v[0];
	for ( int i = 1 ; i < n ; ++i ) {
		if ( v[i] > mm ) {
			mm = v[i];
			++an;
		} else if ( v[i] < ms ) {
			ms = v[i];
			++an;
		} 
	}
	printf ( "%d", an );

	return 0;
}
//xterm -e "/bin/sh %c"
