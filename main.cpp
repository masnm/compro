#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

#define chmax(a,b) if ( a < b ) a = b
#define chmin(a,b) if ( a > b ) a = b

void prepare_lookup_table ()
{
}

void do_task ()
{
	ll a[3] = { };
	ll n; cin >> n;
	ll t, tt = n / 3;
	while ( n-- ) {
		cin >> t; a[t%3]++;
	}
	ll ans = 0;
//	cout << a[0] << " " << a[1] << " " << a[2] << "\n";
	for ( int i = 0 ; i < 3 ; i++ ) {
		if ( a[i] > tt ) {
			ll t = a[i] - tt;
			a[i] -= t;
			for ( int j = 1 ; j < 3 ; j++ ) {
				int ind = (i+j)%3;
				if ( a[ind] < tt ) {
					ll c = tt - a[ind];
					if ( c >= t ) {
						c -= t;
						ans += t*j;
						a[ind] += t;
					} else {
						t -= c;
						ans += c*j;
						a[ind] += c;
					}
				}
			}
		}
	}
	cout << ans << "\n";
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	prepare_lookup_table();

	ll t = 1;
	cin >> t;
	while ( t-- ) {
		do_task();
	}


	return 0;
}
