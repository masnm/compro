#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long double ld;
typedef long long int ll;
typedef unsigned long long ull;

template<typename T> void chmax ( T& a, T b ) { if ( a < b ) a = b; }
template<typename T> void chmin ( T& a, T b ) { if ( a > b ) a = b; }

void prepare_lookup_table ()
{
}

void do_task ()
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution un(1,20);
	uniform_int_distribution ut(1,5);
	
	ll n = un(mt), k = ut(mt); cout << n << " " << k << endl;
	for ( ll i = 0 ; i < n ; ++i ) {
		cout << un(mt) << " ";
	}
	cout << endl;
	for ( ll i = 0 ; i < n ; ++i ) {
		cout << un(mt) << " ";
	}
	cout << endl;
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	prepare_lookup_table();

	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution ud(1,10);

	int t = 1;
	t = ud(mt);
	cout << t << endl;
	for ( int i = 1 ; i <= t ; ++i ) {
		//cout << "Case " << i << ": " ;
		do_task();
	}


	return 0;
}
// resize-pane -L 30 
