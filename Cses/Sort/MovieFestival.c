#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct {
	int F, S;
} pair ;
pair ar[200005];
int n, ans, it, s;

int inc ( const void* a, const void* b )
{
	if ( ((pair*)a)->S == ((pair*)b)->S ) {
		if ( ((pair*)a)->F == ((pair*)b)->F )
			return 0;
		else if ( ((pair*)a)->F < ((pair*)b)->F )
			return -1;
		else return 1;
	} else if ( ((pair*)a)->S < ((pair*)b)->S )
		return -1;
	else return 1;
}

int main ()
{
	(void)scanf ( "%d", &n );
	for ( int i = 0 ; i < n ; ++i ) (void)scanf ( "%d%d", &ar[i].F, &ar[i].S );
	qsort ( ar, n, sizeof(pair), inc );
	ans = 1; s = ar[0].S; it = 1;
	for (  ; it < n ; ++it ) {
		if ( s <= ar[it].F ) {
			s = ar[it].S;
			++ans;
		}
	}
	printf ( "%d\n", ans );

	return 0;
}
