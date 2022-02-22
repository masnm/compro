#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct {
	int I, J, K, IP, ans;
} querie ;
typedef struct {
	int data, ind;
} pair ;

int pcomp ( const void* a, const void* b ) { return ((pair*)b)->data - ((pair*)a)->data; }
int kcomp ( const void* a, const void* b ) { return ((querie*)a)->K - ((querie*)b)->K; }
int ipcomp ( const void* a, const void* b ) { return ((querie*)a)->IP - ((querie*)b)->IP; }

#define arl 30005
#define seg 32768
#define qul 200005

querie quer[qul];
pair ar[arl];
int segt[2*seg], n, q;

void get_input ()
{
	scanf ( "%d", &n );
	for ( int i = 0 ; i < n ; ++i )
		ar[i].ind = i, scanf ( "%d", &ar[i].data );
	qsort ( ar, n, sizeof(pair), pcomp );
}

void get_querry ()
{
	scanf ( "%d", &q );
	for ( int i = 0 ; i < q ; ++i ) {
		scanf ( "%d%d%d", &quer[i].I, &quer[i].J, &quer[i].K );
		quer[i].IP = i;
		--quer[i].I;
		--quer[i].J;
	}
	qsort ( quer, q, sizeof(querie), kcomp );
}

void calculate ()
{
	int top, ars = 0, qq = q;
	--qq;
	while ( qq > -1 ) {
		top = quer[qq].K;
		while ( ars < n && ar[ars].data > top ) {
			int in = ar[ars].ind + seg;
			while ( in > 0 ) {
				segt[in] += 1;
				in >>= 1;
			}
			++ars;
		}
		int l = quer[qq].I + seg, r = quer[qq].J + seg + 1;
		int sum = 0;
		while ( l < r ) {
			if ( l&1 ) sum += segt[l++];
			if ( r&1 ) sum += segt[--r];
			l >>= 1;
			r >>= 1;
		}
		quer[qq].ans = sum;
		--qq;
	}
}

void print_ans ()
{
	qsort ( quer, q, sizeof(querie), ipcomp );
	for ( int i = 0 ; i < q ; ++i ) {
		printf ( "%d\n", quer[i].ans );
	}
}

int main ()
{
	get_input ();
	get_querry ();
	calculate ();
	print_ans ();

	return 0;
}
