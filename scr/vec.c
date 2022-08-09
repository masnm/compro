#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	float x;
	float y;
} vec2f ;

void print ( const char * name, vec2f l )
{
	printf ( "%s : [ %.3f, %.3f ]\n", name, l.x, l.y );
}
#define print(a) print ( #a, a )

vec2f mul ( vec2f l, float r )
{
	l.x *= r;
	l.y *= r;
	return l;
}

int main ( int argc, char* argv[] )
{
	vec2f vec = { .x = 1.6f, .y = 1.8f };
	srand ( time(NULL) );
	float fang = ((float)rand() / (float)RAND_MAX) * 3.1416f * 2.0f;
	vec2f un = { .x = cosf(fang), .y = sinf(fang) };
	print ( un );
	printf ( "Ang : %f\n", fang );
	print ( vec );
	float tme = 0.3f;
	vec2f vecm = mul ( vec, tme );
	print ( vecm );

	return 0;
}

