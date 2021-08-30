#include "bits/stdc++.h"
using namespace std;

using ll = long long int;

int main ()
{
	int ar[6];
	for ( int i = 0 ; i < 5 ; ++i ) {
		cin >> ar[i];
	}
	srand(time(0));
	int sum = 0;
	auto next = [&]( int limit ) {
		return ar[rand()%6];
	};
	for ( int i = 0 ; i < 3 ; ++i ) {
		sum += next(6);
	}
	cout << sum << endl;

	puts("");
	return 0;
}

