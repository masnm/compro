#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long int ll;
typedef unsigned long long ull;

int main ()
{
	int x;
	cin >> x;
	while ( x-- ) {
		int l, r;
		cin >> l >> r;
		int ans = l, c = __builtin_popcount(l);
		for ( int i = l + 1 ; i <= r ; ++i ) {
			int ci = __builtin_popcount ( i );
			if ( ci > c ) {
				c = ci;
				ans = i;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
