#include "bits/stdc++.h"
using namespace std;

int main ( void )
{
	string s;
	vector<int> v;
	int t; cin >> t;
	cin.ignore();
	int l;
	while ( t-- ) {
		v.clear();
		getline ( cin, s );
		istringstream ss( s );
		while ( ss >> l ) v.push_back ( l );
		int ans = 1;
		for ( int i = 0 ; i < int(v.size()) ; ++i ) {
			for ( int j = 0 ; j < int(v.size()) ; ++j ) {
				if ( i != j ) ans = max ( ans, __gcd(v[i],v[j]) );
			}
		}
		printf ( "%d\n", ans );
	}

	return 0;
}
