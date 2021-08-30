#include "bits/stdc++.h"
using namespace std;

using ll = long long int;

const int nax = 200;
bool ar[nax], fb[nax];

int n;

string read_string ()
{
	static char ch[10005];
	scanf ( "%s", ch );
	return string ( ch );
}

bool no ( string& l, string& r )
{
	bool arr[nax] = { };

	for ( char& c : l ) arr[(int)c] = true;
	for ( char& c : r ) if ( !arr[(int)c] ) return true;
	for ( char& c : r ) if ( fb[(int)c] ) return true;

	for ( int i = 0 ; i < nax ; ++i ) arr[i] = false;

	for ( char& c : r ) arr[(int)c] = true;
	for ( char& c : l ) if ( !arr[(int)c] ) fb[(int)c] = true;
	return false;
}

void solve ()
{
	bool ans = false;
	for ( int i = 0 ; i < 129 ; ++i ) ar[i] = false;
	for ( int i = 0 ; i < 129 ; ++i ) fb[i] = false;
	for ( int i = 0 ; i < n ; ++i ) {
		string l = read_string ( );
		string r = read_string ( );
		l.erase(0,1); l.pop_back();
		r.erase(0,1); r.pop_back();
		if ( no ( l, r ) ) {
			ans = true;
		}
		for ( char& c : r ) ar[(int)c] = true;
	}
	if ( !ans ) {
		string ss = "";
		int last = -1;
		for ( int i = 0 ; i < 129 ; ++i ) if ( ar[i] ) last = i;
		for ( int i = 'a' ; i <= 'z' ; ++i ) if ( i <= last && !fb[i] ) ss += (char)i;
		for ( int i = 'A' ; i <= 'Z' ; ++i ) if ( i <= last && !fb[i] ) ss += (char)i;
		for ( int i = '0' ; i <= '9' ; ++i ) if ( i <= last && !fb[i] ) ss += (char)i;
		sort(ss.begin(), ss.end());
		printf ( "[%s]\n", ss.c_str() );
	} else {
		puts ( "I_AM_UNDONE" );
	}
}

int main ()
{
	for ( int i = 1 ;  ; ++i ) {
		scanf ( "%d", &n );
		if ( n == 0 ) break;
		printf ( "Case %d: ", i );
		solve ();
	}


	return 0;
}

