#include "bits/stdc++.h"
using namespace std;

using ll = long long int;

void solve ()
{
	int n;
	scanf ( "%d", &n );
	vector<int> v ( n );
	for ( int& i : v ) scanf ( "%d", &i );
	int ans = *max_element(v.begin(), v.end() );
	ll fans = INT_MAX;
	for ( int i = 0 ; i < n ; ++i ) {

}

int main ()
{
	int t;
	scanf ( "%d", &t );
	for ( int i = 0 ; i < t ; ++i ) {
		solve();
	}


	puts("");
	return 0;
}

