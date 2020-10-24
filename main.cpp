#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void do_task()
{
	string in, key; ll n;
	cin >> in;
	cin >> n;
	cin >> key;
	sort(key.begin(), key.end());
	vector<pair<int, char>> vpair;
	for (ll i = 0; i < (ll)in.length(); i++) {
		if (in[i] == '?') {
			vpair.push_back({ i, i + 1 < (ll)in.length() ? in[i + 1] : 'z' });
		}
	}
	ll vpsz = vpair.size();
	if (vpsz == n) {
		for (auto i : vpair) {
			in[i.first] = key[0];
			key.erase(key.begin());
		}
		cout << in << "\n";
	}
	else {
		ll extra = n - vpsz; 
		for ( ll i=0; i<vpsz ; i++ ) {
			in[vpair[i].first] = key[0];
			key.erase(key.begin());
			while ( extra ) {
				if ( key[0] <= vpair[i].second ) {
					in.insert ( vpair[i].first + 1, key.substr(0,1) );
					key.erase ( key.begin() );
				}
			}
		}
		//if ( key.length() != 0 ) in += key;
		cout << in << "\n";
	}
}

int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);

	ll n = 1;
	cin >> n;
	while (n--) {
		do_task();
	}

	return 0;
}
