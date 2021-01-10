#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

#define sl(a) scanf("%lld",&a)
#define pl(a) printf("%lld ",a)
#define nln printf("\n")

const long long INF = 1e18;
const long long mod = 1000000007;

#warning need array limit
ll A[long(1e7+5)];
ll B[long(1e7+5)];

void prepare_lookup_table ()
{
}

void do_task ()
{
	ll n,m; sl(n); sl(m);
	ll arr[n+1][m] = { };
	vector<ll> c(m);
	for ( ll i = 0 ; i < m ; i++ ) sl(c[i]);

	for ( ll i = 0 ; i < m ; i++ ) arr[0][i] = 1;

	for ( ll i = 1 ; i < n+1 ; i++ ) {
		for ( ll j = 0 ; j < m ; j++ ) {
			ll x = ( i - c[j] >= 0 ) ? arr[i-c[j]][j] : 0;
			ll y = ( j >= 1 ) ? arr[i][j-1] : 0;
			arr[i][j] = x + y;
		}
	}

	for ( ll i = 0 ; i < n+1 ; i++ ) {
		for ( ll j = 0 ; j < m ; j++ ) {
			pl(arr[i][j]);
		}
		nln;
	}
	nln;
}

int main ()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);

	prepare_lookup_table();

	ll t = 1;
	cin >> t;
	while ( t-- ) {
		do_task();
	}


	return 0;
}
