#include <bits/stdc++.h>
using namespace std;

// 3 -> 5
// 5 - 3 = 2

string read_string ()
{
	static char ch[101];
	scanf ( "%s", ch );
	return string(ch);
}

void insert ( vector<int>& bit,int lim, int ind, int val )
{
	for ( ++ind ; ind < lim ; ind += ( ind & ( -ind ) ) ) {
		bit[ind] += val;
	}
}

int sum ( vector<int>& bit, int ind )
{
	int sum = 0;
	for ( ++ind ; ind > 0 ; ind -= ( ind & ( -ind ) ) ) {
		sum += bit[ind];
	}
	return sum;
}

int  suma ( vector<int>& bit, int l, int r )
{
	return sum ( bit, r ) - sum ( bit, l-1 );
}

void solve ( int n )
{
	cout << n << endl;
	vector<int> v ( n ), bit ( n + 1, 0 );
	int t;
	for ( int i = 0 ; i < n ; ++i ) {
		scanf ( "%d", &v[i] );
		insert ( bit, n+1, i, v[i] );
	}
	string s;
	int l, r;
	while ( true ) {
		s = read_string ();
		if ( s=="END" ) break;
		if ( s[0] == 'S' ) {
			scanf ( "%d%d", &l, &r );
			int val = r - v[l];
			insert ( bit, n+1, l-1, val );
			v[l] = r;
		} else {
			scanf ( "%d%d", &l, &r );
			printf ( "%d\n", suma ( bit, l-1, r-1 ) );
		}
	}
}

int main ( int argc, char** argv )
{
	int n, ca = 1;
	while ( true ) {
		scanf ( "%d", &n );
		if ( n == 0 ) break;
		printf ( "Case %d :\n", ca++ );
		solve ( n );
		puts("");
	}
	
	return 0;
}
