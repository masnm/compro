#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cvector.h"

typedef long long int ll;

ll n, ta = LLONG_MAX;
cvector cv;

ll min ( ll a, ll b ) { return a<b?a:b; }

void cal ( void* data )
{
	if ( *(ll*)data > n ) return;
	ta = min ( ta, n - *(ll*)data );
}

static inline void solve ()
{
	ta = LLONG_MAX;
	scanf ( "%lld", &n );
	cvector_for_each ( &cv, cal );
	printf ( "%lld\n", ta );
}

int main ( int argc, char* argv[] )
{
	cv = cvector_create ( sizeof(ll) );
	ll tv = 1, ten = 10;
	for ( ll i = 1 ; i < 15 ; ++i ) {
		cvector_emplace_back ( &cv, &tv );
		tv *= ten;
	}

	int t; scanf ( "%d", &t );
	while ( t-- )
		solve ();

	return 0;
}
