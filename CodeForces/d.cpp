#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long double ld;
typedef long long int ll;
typedef unsigned long long ull;

const ll inf = 1e18 + 5;

template<typename T> void chmax ( T& a, T b ) { if ( a < b ) a = b; }
template<typename T> void chmin ( T& a, T b ) { if ( a > b ) a = b; }

void prepare_lookup_table ()
{
}

void do_task ()
{
	ll n; cin >> n;
	int qt, ind, len;
	string s;
	vector<string> d;
	set<string> q;
	for ( ll i = 0 ; i < n ; ++i ) {
		cin >> qt;
		if ( qt == 1 ) {
			cin >> s;
			d.emplace_back(s);
			q.insert ( s );
		} else if ( qt == 2 ) {
			cin >> ind >> len; --ind;
			q.erase ( d[ind] );
			d[ind].erase ( 0, len );
			q.insert ( d[ind] );
		} else {
			cin >> ind >> len; --ind; --len;
			string mn = min ( d[ind], d[len] ), mx = max ( d[ind], d[len] );
			//cout << ll dd = distance ( q.lower_bound(mn), q.upper_bound(mx) ) << endl;
			ll dd = distance ( q.lower_bound(mn), q.upper_bound(mx) );
			cout << dd << endl;
		}
	}
}

int main ()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);

	prepare_lookup_table();

	int t = 1;
	for ( int i = 1 ; i <= t ; ++i ) {
//		cout << "Case " << i << ": " ;
		do_task();
	}


	return 0;
}
