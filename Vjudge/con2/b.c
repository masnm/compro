#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

long long r, c, x, ir, ic, low, high, mid, mn;
int t;

long long bs ()
{
	int cnt = 0;
	low = 0; high = 1000006;
	while ( low < high ) {
		if ( ++cnt > 60 ) break;
		mid = low + (high-low)/2LL;
		mn = mid * r + 1;
		if ( mn <= x ) low = mid;
		else high = mid;
	}
	return low;
}

void solve ()
{
	scanf ( "%lld%lld%lld", &r, &c, &x );
	ir = bs ();
	ic = x - (ir*r);
	++ir;
	long long ans = c * (ic - 1);
	ans += ir;
	printf ( "%lld\n", ans );
}

int main ()
{
	scanf ( "%d", &t );
	while ( t-- )
		solve ();

	return 0;
}
