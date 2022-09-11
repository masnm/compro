#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( int argc, char* argv[] )
{
	char c[100];
	scanf ( "%s", c );
	printf ( "%[^\n]", c );

	return 0;
}

