#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int x;
	int y;
} pair ;
pair pad[1024];
int pac = 0;

#define row 10
#define col 10
char mp[row][col];

bool insideii ( int _r, int _c )
{ return (_r >= 0 && _r < row && _c >= 0 && _c < col); }

bool insidep ( pair p ) { return insideii(p.x, p.y); }

bool what ( void )
{
	for ( int rep = 0 ; rep < pac ; ++rep ) {
		pair cp;
		int cnt;
		// line vertical
		cnt = 0;
		for ( int ag = -1 ; ag < 2 ; ag += 2 ) {
			cp = pad[rep];
			while ( true ) {
				cp.x += ag;
				if ( insidep(cp) && mp[cp.x][cp.y] == 'X' ) ++cnt;
				else break;
			}
		}
		if ( cnt + 1 >= 5 ) return true;
		// line horizontal
		cnt = 0;
		for ( int ag = -1 ; ag < 2 ; ag += 2 ) {
			cp = pad[rep];
			while ( true ) {
				cp.y += ag;
				if ( insidep(cp) && mp[cp.x][cp.y] == 'X' ) ++cnt;
				else break;
			}
		}
		if ( cnt + 1 >= 5 ) return true;
		// diagonal \ //
		cnt = 0;
		for ( int ag = -1 ; ag < 2 ; ag += 2 ) {
			cp = pad[rep];
			while ( true ) {
				cp.x += ag; cp.y += ag;
				if ( insidep(cp) && mp[cp.x][cp.y] == 'X' ) ++cnt;
				else break;
			}
		}
		if ( cnt + 1 >= 5 ) return true;
		// diagonal / //
		cnt = 0;
		for ( int ag = -1 ; ag < 2 ; ag += 2 ) {
			cp = pad[rep];
			while ( true ) {
				cp.x += -1 * ag; cp.y += ag;
				if ( insidep(cp) && mp[cp.x][cp.y] == 'X' ) ++cnt;
				else break;
			}
		}
		if ( cnt + 1 >= 5 ) return true;
	}
	return false;
}

int main ( int argc, char* argv[] )
{
	for ( int i = 0 ; i < row ; ++i )
		for ( int j = 0 ; j < col ; ++j )
			scanf ( "%c ", &mp[i][j] );
	for ( int j = 0 ; j < 10 ; ++j )
		for ( int i = 9 ; i > -1 ; --i )
			if ( mp[i][j] == '.' )
				pad[pac++] = (pair) { .x = i, .y = j };
	printf ( what() ? "YES" : "NO" );
	// puts ( "" );
	// for ( int i = 0 ; i < pac ; ++i )
	// 	mp[pad[i].x][pad[i].y] = '*';
	// for ( int i = 0 ; i < row ; ++i ) {
	// 	for ( int j = 0 ; j < col ; ++j )
	// 		printf ( "%c", mp[i][j] );
	// 	printf ( "\n" );
	// }

	return 0;
}

