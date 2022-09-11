#include "bits/stdc++.h"
using namespace std;

string read_string ()
{
	static char ch[1000005];
	scanf ( "%s", ch );
	return string ( ch );
}

using ll = long long int;

int key_inverse ( int key )
{
	for ( int i = 1 ; i < 27 ; ++i ) {
		if ( (key*i)%26 == 1 ) {
			return i;
		}
	}
	fprintf ( stderr, "Invalik key to inverse\n" );
	exit ( 1 );
}

int mod ( int x, int p )
{
	while ( x < 0 ) x += p;
	while ( x > p ) x -= p;
	return x;
}

int main ( int argc, char* argv[] )
{
	string plain = read_string ();
	int key1, key2;
	scanf ( "%d%d", &key1, &key2 );
	for ( auto& i : plain ) {
		i = char((mod(((key1*int(i-'A'))+key2),26)+'A'));
	}
	printf ( "Cipher : %s\n", plain.c_str() );
	for ( auto& i : plain ) {
		i = char ( (mod(((int(i-'A')-key2)*key_inverse(key1) ), 26) + 'A'));
	}
	printf ( "Reverse : %s\n", plain.c_str() );

	return 0;
}

