#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printa ( void* data ) { printf ( "Hello from A\n" ); }
void printb ( void* data ) { printf ( "Hello from B\n" ); }
void printc ( void* data ) { printf ( "Hello from C\n" ); }

typedef void (*fun) ( void* );

typedef struct {
	fun f;
} arr ;

arr array[3];

int main ( int argc, char* argv[] )
{
	char ch[] = { 'a', 'b', 'c' };
	for ( int i = 0 ; i < 3 ; ++i ) {
		if ( ch[i] == 'a' ) {
			array[i].f = printa;
		} else if ( ch[i] == 'b' ) {
			array[i].f = printb;
		} else {
			array[i].f = NULL;
		}
	}
	for ( int i = 0 ; i < 3 ; ++i ) {
		if ( array[i].f != NULL ) {
			array[i].f(NULL);
		}
	}

	return 0;
}

