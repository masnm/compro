#include "bits/stdc++.h"
using namespace std;

using ll = long long int;

int main ()
{
	string s = "141592653589793238";
	int t;
	scanf ( "%d", &t );
	while ( t-- ) {
		int n;
		scanf ( "%d", &n );
		int ans = 0;
		for ( int i = 0 ; i < n ; ++i ) {
			ans += s[i]-'0';
		}
		printf ( "%d", ans );
		puts("");
	}



	return 0;
}

