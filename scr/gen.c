#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
 
#define typename(x) _Generic((x),        /* Get the name of a type */             \
        _Bool: "_Bool",                  unsigned char: "unsigned char",          \
         char: "char",                     signed char: "signed char",            \
    short int: "short int",         unsigned short int: "unsigned short int",     \
          int: "int",                     unsigned int: "unsigned int",           \
     long int: "long int",           unsigned long int: "unsigned long int",      \
long long int: "long long int", unsigned long long int: "unsigned long long int", \
        float: "float",                         double: "double",                 \
  long double: "long double",                   char *: "pointer to char",        \
       void *: "pointer to void",                int *: "pointer to int",         \
      default: "other")

#define typearg(x) _Generic((x),        /* Get the name of a type */             \
        _Bool: "_Bool",                  unsigned char: "unsigned char",          \
         char: "char",                     signed char: "signed char",            \
    short int: "short int",         unsigned short int: "unsigned short int",     \
          int: "int",                     unsigned int: "unsigned int",           \
     long int: "long int",           unsigned long int: "unsigned long int",      \
long long int: "long long int", unsigned long long int: "unsigned long long int", \
        float: "float",                         double: "double",                 \
  long double: "long double",                   char *: "pointer to char",        \
       void *: "pointer to void",                int *: "pointer to int",         \
      default: "other")

#define __int(X) fprintf ( stderr, "[%s : %d ]", #X, X )
#define __longdouble(X) fprintf ( stderr, "[%s : %Lf ]", #X, X )
#define dbg(X) _Generic((X), int: __int(X), long double: __longdouble(X), default: assert(false) )

int main(void)
{
	long double ppp = 23;
	int i = 5, abcd = 5;
	dbg(i);
	dbg(abcd);
	dbg(ppp);
}
