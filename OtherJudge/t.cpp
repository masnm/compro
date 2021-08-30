#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	vector<int> v ( n );
	for ( int i = 0 ; i < n ; ++i ) {
		cin >> v[i];
	}
	sort ( v.begin(), v.end() );
	int count = 0, pv = -1;
	for ( int i = 0 ; i < n ; ++i ) {
		if ( v[i] != pv ) {
			pv = v[i];
			++count;
		}
	}
	cout << count << endl;

	cout << endl;
	return 0;
}
