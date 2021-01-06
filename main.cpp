#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

void prepare_lookup_table ()
{
}

void do_task ()
{
	ll n,x,sum = 0; cin >> n >> x;
	vector<ll> a(n),b(n);
	for ( ll i = 0 ; i < n ; i++ ) {
		cin >> a[i];
		b[i] = a[i];
		sum += a[i];
	}
	ll index = 0;
	while ( b[index] % x == 0 ) {
		sum += a[index];
		b[index] /= x;
		index++;
		if ( index == n ) index = 0;
	}
	cout << sum << endl;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	prepare_lookup_table();

	ll t = 1;
	cin >> t;
	while ( t-- ) {
		do_task();
	}


	return 0;
}
