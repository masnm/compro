#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define mm 105
float per[mm];
int months, n;
float down_pay, loan;

void take_months ()
{
	assert ( months < mm );
	for ( int i = 0 ; i < mm ; ++i ) per[i] = 0.0f;
	int next; float perc;
	for ( int i = 0 ; i < n ; ++i ) {
		scanf ( "%d%f", &next, &perc );
		per[next] = perc;
	}
	for ( int i = 0 ; i < months ; ++i ) {
		if ( per[i] != 0.0f ) perc = per[i];
		per[i] = perc;
	}
}

void cal_print ()
{
	float cpri = down_pay + loan;
	cpri = cpri - (cpri * per[0]);
	for ( int i = 1 ; true ; ++i ) {
		printf ( "%f %f \n", cpri, loan );
		assert ( i <= months );
		if ( cpri > loan ) {
			if ( i == 1 )
				printf ( "%d month\n", i);
			else
				printf ( "%d months\n", i);
			return;
		}
		loan -= down_pay;
		cpri -= (cpri * per[i]);
	}
}

int main ()
{
	while ( true ) {
		scanf ( "%d%f%f%d", &months, &down_pay, &loan, &n );
		if ( months < 0 ) break;
		take_months ();
		cal_print ();
	}

	return 0;
}

