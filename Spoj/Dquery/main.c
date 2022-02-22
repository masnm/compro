#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define arl 30005
#define nax 1000006
#define qrl 200005
#define seg 32768
// #define arl 7
// #define nax 7
// #define qrl 7
// #define seg 8

typedef struct {
	int F, S;
} pair ;

typedef struct {
	size_t sz;
	pair* pr;
} arpair ;

int n, q, l, r;
int ar[arl], lpos[nax], cnt[arl], segt[2*seg];
pair querrys[qrl];
arpair pairar[qrl];

void get_input ()
{
	scanf ( "%d", &n );
	for ( int i = 0 ; i < n ; ++i )
		scanf ( "%d", &ar[i] );
}

void get_querry ()
{
	scanf ( "%d", &q );
	for ( int i = 0 ; i < q ; ++i ) pairar[i].sz = 0, pairar[i].pr = NULL;
	for ( int i = 0 ; i < q ; ++i ) {
		scanf ( "%d%d", &l, &r ); --l; --r;
		querrys[i].F = l; querrys[i].S = r;
		++ pairar[r].sz; pairar[r].pr =
			realloc ( pairar[r].pr, sizeof(pair) * pairar[r].sz );
		pairar[r].pr[pairar[r].sz-1] = (pair) { .F = l, .S = 0 };
	}
}

void print_ans ()
{
	for ( int i = 0 ; i < q ; ++i ) {
		l = querrys[i].F; r = querrys[i].S;
		for ( int j = 0 ; j < pairar[r].sz ; ++j )
			if ( pairar[r].pr[j].F == l ) {
				printf ( "%d\n", pairar[r].pr[j].S );
				break;
			}
	}
	for ( int i = 0 ; i < q ; ++i )
		if ( pairar[i].pr != NULL )
			free ( pairar[i].pr );
}

int main ()
{
	get_input (); get_querry ();
	for ( int i = 0 ; i < nax ; ++i ) lpos[i] = -1;
	for ( int i = 0 ; i < n ; ++i ) {
		if ( lpos[ar[i]] != -1 ) {
			-- cnt[lpos[ar[i]]];
			l = lpos[ar[i]] + seg;
			while ( l != 0 ) {
				--segt[l];
				l /= 2;
			}
		}
		lpos[ar[i]] = i;
		++ cnt[i];
		l = i + seg;
		while ( l != 0 ) {
			++segt[l];
			l /= 2;
		}
		for ( int j = 0 ; j < pairar[i].sz ; ++j ) {
			l = pairar[i].pr[j].F + seg; r = i + seg + 1;
			int sum = 0;
			while ( l < r ) {
				if ( l&1 ) sum += segt[l++];
				if ( r&1 ) sum += segt[--r];
				l >>= 1; r >>= 1;
			}
			//for ( int k = pairar[i].pr[j].F ; k <= i ; ++k )
			//	sum += cnt[k];
			pairar[i].pr[j].S = sum;
		}
	}

	print_ans ();

	return 0;
}
