#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#ifdef LOCAL
	#define dbg(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
	//#define dbg(...) fprintf ( stderr, __VA_ARGS__ )
#else
	#define dbg(...) true
#endif

int main ()
{
	int a = 105;

	return 0;
}

