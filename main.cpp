#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long
#define ld long double

#define chmax(a,b) if ( a < b ) a = b
#define chmin(a,b) if ( a > b ) a = b

#define mxn 101
ll dp[mxn] = { };
vector<ll> mn(mxn, LLONG_MAX);

void solve ( ll a, ll b, ll c, ll ind, ll count )
{
	if ( ind+a < mxn ) {
		++dp[ind+a];
		solve ( a+3, b, c, ind+a, count+1 );
	}
	if ( ind+b < mxn ) {
		++dp[ind+b];
		solve ( a, b+3, c, ind+b, count+1 );
	}
	if ( ind+c < mxn ) {
		++dp[ind+c];
		solve ( a, b, c+3, ind+c, count+1 );
	}
	chmin ( mn[ind], count );
}

void prepare_lookup_table ()
{
	dp[0] = 1;
	solve ( 1, 2, 3, 0, 0 );
}

void do_task ()
{
	for ( ll i = 0 ; i < mxn ; ++i ) {
		cout << i << " " << (mn[i]==LLONG_MAX?-1:mn[i]) << " " << dp[i] << endl;
	}
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
