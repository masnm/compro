#include "bits/stdc++.h"
using namespace std;

using ll = long long int;

ll p, c;

ll dd ( ll a )
{
	ll ans = 0;
	ll i = 1;
	ll lim = 65 - __builtin_clzll ( a );
	for ( int rep = 0 ; rep < lim ; ++rep ) {
		i *= 2;
		ll ds = a/i;
		ans += ds*(i/2);
		ll dn = ds*i;
		dn = abs ( a-dn );
		dn -= ( i/2 );
		ans += ( dn>0?dn:0);
	}
	return ans;
}

void solve ()
{
	ll l = (p<1?0:dd(p)), r = (c<1?0:dd(c+1));
	printf ( "%lld\n", r-l );
}

int main ()
{
	for ( int i = 1 ;  ; ++i ) {
		scanf ( "%lld%lld", &p, &c );
		if ( p == c && p == 0 ) break;
		printf ( "Case %d: ", i );
		solve();
	}

	return 0;
}

