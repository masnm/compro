#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( int argc, char* argv[] )
{
	FILE* fl = fopen ( "./a.txt", "r" );

	char c;
	fscanf ( fl, "%c", &c );
	printf ( "%c\n", c );

	fclose ( fl );

	return 0;
}

