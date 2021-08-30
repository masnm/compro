#include "bits/stdc++.h"
using namespace std;

using ll = long long int;

int ar[100005];
void solve ()
{
	int n;
	scanf ( "%d", &n );
	for ( int i = 0 ; i < n ; ++i ) {
		scanf ( "%d", &ar[i] );
	}
	int cnt = 0;
	for ( int i = 0 ; i < n ; ++i ) {
		if ( ar[i] > 0 ) ++cnt;
	}
	if ( cnt & 1 ) {
		puts("Alice");
	} else {
		puts("Bob");
	}
}

int main ()
{
	int t;
	scanf ( "%d", &t );
	while ( t-- ) solve();


	puts("");
	return 0;
}

