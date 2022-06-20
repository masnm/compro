#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define nax 200005

typedef struct {
	int num, count, ind;
} tpl ;

int cmin ( const void* a, const void* b ) { return ((tpl*)a)->num - ((tpl*)b)->num; }
int bcmp ( const void* a, const void* b ) { return (*(int*)a) - ((tpl*)b)->num; }
int max ( int a, int b ) { return (a > b ? a : b); }

tpl p[nax];
int n, ar[nax];

int main ()
{
	scanf ( "%d", &n );
	for ( int i = 0 ; i < n ; ++i ) {
		scanf ( "%d", &p[i].num );
		p[i].ind = i;
		p[i].count = 0;
		ar[i] = p[i].num;
	}
	qsort ( p, n, sizeof(tpl), cmin );
	int ansc = 0, ansv = -1, tv;
	for ( int i = 0 ; i < n ; ++i ) {
		tv = ar[i] - 1;
		tpl* prev = bsearch ( &tv, p, n, sizeof(tpl), bcmp );
		tv = ar[i];
		tpl* me = bsearch ( &tv, p, n, sizeof(tpl), bcmp );
		me->count = max ( me->count, 1 );
		if ( prev ) {
			me->count = max ( me->count, prev->count + 1 );
		}
		if ( me->count > ansc ) {
			ansc = me->count;
			ansv = me->num;
		}
	}
	int s = ansv - ansc + 1, e = ansv;
	printf ( "%d\n", ansc );
	for ( int i = 0 ; i < n && s <= e ; ++i ) {
		if ( ar[i] == s ) {
			printf ( "%d ", i+1 );
			s++;
		}
	}

	return 0;
}

// extern void qsort (void *__base, size_t __nmemb, size_t __size,
// 		   __compar_fn_t __compar) __nonnull ((1, 4));
// void *bsearch (const void *__key, const void *__base,
// 		      size_t __nmemb, size_t __size, __compar_fn_t __compar)
