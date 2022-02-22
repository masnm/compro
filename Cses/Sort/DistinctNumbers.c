#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

int32_t ar[200005], n, cnt, prev;

int min ( const void* a, const void* b )
{ return *(int32_t*)a - *(int32_t*)b; }

int main ()
{
	scanf ( "%d", &n );
	for ( int32_t i = 0 ; i < n ; ++i ) {
		scanf ( "%d", ar+i );
	}
	qsort ( ar, n, sizeof(int32_t), min );
	cnt = 0; prev = -1;
	for ( int32_t i = 0 ; i < n ; ++i ) {
		if ( ar[i] != prev ) {
			prev = ar[i];
			++cnt;
		}
	}
	printf ( "%d\n", cnt );

	return 0;
}
