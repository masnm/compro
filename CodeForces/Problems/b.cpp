#include "bits/stdc++.h"
using namespace std;

using ll = long long int;

string read_string ()
{
	static char ch[105];
	scanf ( "%s", ch );
	return string ( ch );
}

void solve ()
{
	int n;
	scanf ( "%d", &n );
	string s = read_string();
	int st = -1;
	for ( int i = 0 ; i < n ; ++i ) {
		if ( s[i] != '?' ) {
			st = i;
			break;
		}
	}
	if ( st == -1 ) {
		char c = 'B';
		for ( int i = 0 ; i < n ; ++i ) {
			s[i] = c;
			c = c ^ 'B' ^ 'R';
		}
		puts ( s.c_str() );
	} else {
		for ( int i = st + 1 ; i < n ; ++i ) {
			if ( s[i] == '?' ) {
				s[i] = s[i-1] ^ 'B' ^ 'R';
			}
		}
		for ( int i = st - 1 ; i > -1 ; --i ) {
			if ( s[i] == '?' ) {
				s[i] = s[i+1] ^ 'B' ^ 'R';
			}
		}
		puts ( s.c_str() );
	}
}

int main ()
{
	int t;
	scanf ( "%d", &t );
	for ( int i = 0 ; i < t ; ++i ) {
		solve();
	}


	puts("");
	return 0;
}

