#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

unsigned long long n, m, a, b, c, d, mx, mn;

int main ()
{
	scanf ( "%llu%llu", &n, &m );
	a = n - m + 1LL;
	b = (a*(a-1))/2LL;
	mx = b;
	a = n/m;
	b = n%m;
	c = (a*(a-1))/2LL;
	++a;
	d = (a*(a-1))/2LL;
	mn = d*b + c*(m-b);
	printf ( "%llu %llu", mn, mx );

	return 0;
}
