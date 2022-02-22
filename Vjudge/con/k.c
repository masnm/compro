#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

long long t, n, m, ans;

int main ()
{
	scanf ( "%lld", &t );
	for ( int i = 0 ; i < t ; ++i ) {
		ans = 0;
		scanf ( "%lld%lld", &n, &m );
		for ( int j = 1 ; j <= n ; ++j )
			ans += j*j*m;
		printf ( "%lld\n", ans );
	}

	return 0;
}

