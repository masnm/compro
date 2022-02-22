#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

long long l, y, z;
char px[] = "+x", nx[] = "-x", py[] = "+y", ny[] = "-y",
	pz[] = "+z", nz[] = "-z", no[] = "No";

char* calculate ()
{
	char* ans = px, ch[5];
	for ( long long i = 0 ; i < l - 1 ; ++i ) {
		scanf ( "%s", ch );
		if ( ! strcmp ( ch, pz ) ) {
			if ( ans == px || ans == nx ) {
				if ( ans == px ) ans = pz;
				else if ( ans == nx ) ans = nz;
			} else if ( ans == pz ) {
				ans = nx;
			} else if ( ans == nz ) {
				ans = px;
			}
		} else if ( !strcmp ( ch, nz ) ) {
			if ( ans == px || ans == nx ) {
				if ( ans == px ) ans = nz;
				else if ( ans == nx ) ans = pz;
			} else if ( ans == pz ) {
				ans = px;
			} else if ( ans == nz ) {
				ans = nx;
			}
		} else if ( !strcmp ( ch, py ) ) {
			if ( ans == px || ans == nx ) {
				if ( ans == px ) ans = py;
				else if ( ans == nx ) ans = ny;
			} else if ( ans == py ) {
				ans = nx;
			} else if ( ans == ny ) {
				ans = px;
			}
		} else if ( !strcmp ( ch, ny ) ) {
			if ( ans == px || ans == nx ) {
				if ( ans == px ) ans = ny;
				else if ( ans == nx ) ans = py;
			} else if ( ans == py ) {
				ans = px;
			} else if ( ans == ny ) {
				ans = nx;
			}
		} else if ( !strcmp ( ch, no ) ) {
		} else assert ( false );
	}
	return ans;
}

int main ()
{
	while ( true ) {
		scanf ( "%lld", &l );
		if ( l == 0 ) break;
		y = 0; z = 0;
		printf ( "%s\n", calculate () );
	}

	return 0;
}
