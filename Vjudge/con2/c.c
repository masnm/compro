#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

long long a, b, n, t, ans;

long long max ( long long _a, long long _b )
{
	return (_a > _b ? _a : _b);
}

void solve ()
{
	scanf ( "%lld%lld%lld", &a, &b, &n );
	ans = 0;
	while ( max(a,b) <= n ) {
		if ( a > b )
			b += a, ans++;
		else
			a += b, ans++;
	}
	printf ( "%lld\n", ans );
}

int main ()
{
	scanf ( "%lld", &t );
	while ( t-- )
		solve ();

	return 0;
}

