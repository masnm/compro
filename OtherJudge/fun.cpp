#include <bits/stdc++.h>
using namespace std;

void functoin_input ( int ar[], int n )
{
	for ( int i = 0 ; i < n ; i++ ) {
		cin >> ar[i];
	}
}

int function_print ( int ar[], int n )
{
	for ( int i = 0 ; i < n ; ++i ) {
		cout << ar[i] << " ";
	}
	return n;
}

int main ()
{
	int n;
	cin >> n;
	int ar[100];
	for ( int i = 0 ; i < 10 ; ++i ) {
		cout << "Enter input : ";
		functoin_input ( ar, n );
		function_print ( ar, n );
	}
	
	return 0;
}
