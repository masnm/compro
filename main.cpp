#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

#define chmax(a,b) if ( a < b ) a = b
#define chmin(a,b) if ( a > b ) a = b

#define si(a) scanf("%d",&a)
#define pis(a) printf("%d ",a)
#define pi(a) printf("%d",a)
#define nln printf("\n")

void prepare_lookup_table ()
{
}

void do_task ()
{
	string s; cin >> s;
	vector<pair<int,char>> vp;
	int len = s.length();
	char prev = '.';
	pair<int,char> p={INT_MIN,'.'};
	for ( int i = 0 ; i < len ; i++ ) {
		if ( s[i] != prev ) {
			vp.push_back(p);
			p.second = s[i];
			p.first = 1;
			prev = s[i];
		} else {
			p.first++;
		}
	}
	vp.push_back(p);
	sort ( vp.begin(), vp.end() );
	p = vp[vp.size()-1];
	if ( p.first > 6 ) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	prepare_lookup_table();

	ll t = 1;
//	cin >> t;
	while ( t-- ) {
		do_task();
	}


	return 0;
}
