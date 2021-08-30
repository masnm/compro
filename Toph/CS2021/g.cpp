#include "bits/stdc++.h"
using namespace std;

using ll = long long int;

const int nax = 1'00'005;
ll ps[nax];
int l, r, n, m ;
ll ar[nax][27];
char ch[nax];
ll an[27];

void pre ()
{
	for ( int i = 1 ; i < nax ; ++i ) ps[i] = ps[i-1]+i;
}

void calc ()
{
	++ar[0][ch[0]-'a'];
	for ( int i = 1 ; i < n ; ++i ) {
		for ( int j = 0 ; j < 27 ; ++j ) ar[i][j] = ar[i-1][j];
		++ar[i][ch[i]-'a'];
	}
}

ll rngsm ()
{
	for ( int i = 0 ; i < 27 ; ++i ) an[i] = 0;
	--l; --r;
	if ( l != 0 ) {
		--l;
		for ( int i = 0 ; i < 27 ; ++i )
			an[i] = ar[r][i] - ar[l][i];
	} else {
		for ( int i = 0 ; i < 27 ; ++i )
			an[i] = ar[r][i];
	}
	ll cnt = 0;
	for ( int i = 0 ; i < 27 ; ++i ) {
		cnt += ( an[i]>0?1:0);
	}
	cerr << cnt << endl;
	return ps[cnt];
}

int main ()
{
	pre();
	scanf ( "%d%d", &n, &m );
	scanf ( "%s", ch );
	calc();
	for ( int i = 0 ; i < m ; ++i ) {
		scanf ( "%d%d", &l, &r );
		printf ( "%lld\n", rngsm() );
	}


	return 0;
}

