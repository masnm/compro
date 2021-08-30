#include <bits/stdc++.h>
using namespace std;

void swap (char *str1, char *str2)
{
	char *temp = (char *)malloc((strlen(str1) + 1) * sizeof(char));
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
	free(temp);
}

int main ()
{
	char ch[100][100], cl[100][100];
	int n;
	cout << "Enter n " ;
	cin >> n;
	
	cout << "Enter " << n << " names : " ;
	for ( int i = 0 ; i < n ; ++i ) {
		cin >> ch[i];
		cin >> cl[i];
	}
	
	char s[100];
	cout << "Enter second name to delete : " ;
	cin >> s;
	for ( int i = 0 ; i < n ; ++i ) {
		if ( strcmp ( s, cl[i] ) == 0 ) {
			for ( int j = i ; j < n ; ++j ) {
				swap ( ch[j], ch[j+1] );
				swap ( cl[j], cl[j+1] );
			}
			--n;
			--i;
		}
	}
	
	cout << endl;
	for ( int i = 0 ; i < n ; ++i ) {
		cout << ch[i] << " " << cl[i] << endl;
	}
	

	return 0;
}

/*

8
Adams Nelson
Brown Davis
Cohen Davis
Dixon Levine
Eisen Davis
Fischer Levine
Gibson Nelson
Harris Nelson

Nelson

*/
