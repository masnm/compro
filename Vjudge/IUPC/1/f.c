#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int main ()
{
	int n, a, b, s;
	scanf ( "%d%d%d%d", &n, &a, &b, &s );
	int min = a * (n - 1); min += b;
	int max = b * (n - 1); max += a;
	if ( s >= min && s <= max )
		puts("Yes");
	else
		puts("No");

	return 0;
}

