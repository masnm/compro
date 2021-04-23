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

map<pair<ll,ll>,ll> mp;

void print ( vector<pair<ll,ll>>& vp )
{
	for ( auto& i : vp ) {
		ll ind = mp[i];
		string st = "A-";
		st += to_string ( ind );
		reverse(st.begin(),st.end());
		ll need = 4 - st.length();
		while ( need-- > -1 ) {
			st += " ";
		}
		reverse(st.begin(),st.end());
		cout << st << " ";
	}
	cout << endl;
	for ( auto& i : vp ) {
		string st = to_string(i.second); reverse(st.begin(), st.end());
		ll need = 4 - st.length();
		while ( need-- > -1 ) {
			st += " ";
		}
		reverse(st.begin(),st.end());
		cout << st << " ";
	}
	cout << endl;
	for ( auto& i : vp ) {
		string st = to_string(i.first); reverse(st.begin(), st.end());
		ll need = 4 - st.length();
		while ( need-- > -1 ) {
			st += " ";
		}
		reverse(st.begin(),st.end());
		cout << st << " ";
	}
	cout << endl;
}

void greedy ( vector<pair<ll,ll>>& vp, ll& n )
{
	cout << "The initial table is " << endl;
	print ( vp );
	sort(vp.begin(), vp.end());
	cout << "The table after sorting in ascending orber by end time is " << endl;
	print ( vp );
	int taken = 0;
	vector<pair<ll,ll>> va;
	cout << endl;
	for ( auto& i : vp ) {
		if ( i.second >= taken ) {
			int ind = mp[i];
			cout << "A-"<<ind<< " is valid ( " <<
				i.second << " >= " << taken << " ) so adding it to ans."
				<< endl;
			va.emplace_back(i);
			taken = i.first;
			cout << "New accupied length is " << taken << endl;
		} else {
			int ind = mp[i];
			cout << "A-"<<ind<<" is not valid ( " <<
				i.second << " < " << taken << " ) so not adding it to ans."
				<< endl;
		}
		cout << endl;
	}
	cout << "The ans table is " << endl;
	print ( va );
}

vector<pair<ll,ll>> recar ( vector<pair<ll,ll>>& vp, ll ind, ll& n )
{
	ll m = ind + 1;
	while ( m < n && vp[m].second < (ind == -1 ? 0: vp[ind].first) ) {
		ll indx = mp[vp[m]];
		cout << "A-" << indx << " is not valid," <<
			" cause ( " << vp[m].second << " >= " << (ind == -1 ? 0: vp[ind].first) << " ). " <<
		       "So not addint to ans." << endl;
		++m;
	}
	if ( m < n ) {
		ll indx = mp[vp[m]];
		cout << "A-" << indx << " is valid," 
			<< " cause ( " << vp[m].second << " < " << (ind == -1 ? 0: vp[ind].first) << " ). "
			<< "so adding it to set and, " << endl;
		cout << " recursively calling the next activityes." << endl << endl;
		vector<pair<ll,ll>> v = recar ( vp, m, n );
		v.emplace_back ( vp[m] );
		return v;
	} else {
		cout << "As we finished the processing of all activity. " << endl;
		cout << "We don't need to process more, and returning NULL set." << endl << endl;
		return vector<pair<ll,ll>>();
	}
}

void do_task ()
{
	ll n; cin >> n;
	vector<pair<ll,ll>> vp(n);
	for ( auto& i : vp ) {
		cin >> i.second;
	}
	for ( auto& i : vp ) {
		cin >> i.first;
	}
	ll index = 0;
	for ( auto& i : vp ) {
		mp[i] = ++index;
	}
	char ch; cin >> ch;
	if ( ch == 'r' ) {
		cout << "The initial table is " << endl;
		print ( vp );
		sort(vp.begin(), vp.end());
		cout << "The table after sorting in ascending orber by end time is " << endl;
		print ( vp );
		vector<pair<ll,ll>> v = recar (vp, -1, n);
		cout << "The ans table is " << endl;
		print ( v );
	} else if ( ch == 'g' ) {
		greedy (vp, n);
	}
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	prepare_lookup_table();

	int t = 1;
	for ( int i = 1 ; i <= t ; ++i ) {
		//cout << "Case " << i << ": " ;
		do_task();
	}


	return 0;
}
// resize-pane -L 30 
