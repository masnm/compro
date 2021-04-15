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

string p_r_s ( ll ind, set<ll>& s )
{
	string str = "g";
	str += "(" + to_string(ind+1) + "," + "{";
	if ( s.empty() ) {
		str += ".})";
		return str;
	}
	for ( auto& i : s ) str += to_string(i+1) + ",";
	ll len = str.length();
	str[len-1] = '}'; str += ")";
	return str;
}

map<pair<ll,set<ll>>,ll> mp;
ll solve ( ll& sind, vector<vector<ll>>& cost, ll ind, set<ll>& s )
{
	auto search = mp.find({ind,s});
	if ( search != mp.end() ) {
		return search->second;
	}
	if ( s.empty() ) {
		mp[{ind,s}] = cost[ind][sind];
		cout<<"g("<<ind+1<<",∅"<<") = ";
		cout<<"C"<<ind+1<<sind+1<<" = "<<cost[ind][sind];
		cout << endl << endl;
		return cost[ind][sind];
	}
	set<ll> cp = s;
	string str = p_r_s ( ind, s );
	string str2 = "min{";
	str += " = min {";
	ll ans = LLONG_MAX;
	for ( auto& i : s ) {
		cp.erase(i);
		str += "C" + to_string(ind+1) + to_string(i+1);
		str += "+" + p_r_s ( i, cp );
		ll recur_ans = solve ( sind, cost, i, cp );
		ll ca = cost[ind][i] + recur_ans;
		str2 +="("+to_string(cost[ind][i])+"+"+to_string(recur_ans)+"),";
		chmin ( ans, ca );
		cp.insert(i);
	}
	str += "}\n";
	ll st2len = str2.length(); str2[st2len-1] = '}'; str2 += "\n=" + to_string(ans) + "\n";
	cout << str << str2 << endl;
	return ans;
}

void do_task ()
{
	ll n; cin >> n;
	vector<vector<ll>> cost(n,vector<ll>(n));
	for ( ll i = 0 ; i < n ; ++i ) {
		for ( ll j = 0 ; j < n ; ++j ) {
			cin >> cost[i][j];
		}
	}
	ll sind; cin >> sind; --sind;
	set<ll> s;
	for ( ll i = 0 ; i < n ; ++i ) s.insert(i);
	s.erase(sind);
	ll ans = solve ( sind, cost, sind, s );
	cout << ans << endl;
}

int main ()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);

	prepare_lookup_table();

	int t = 1;
	for ( int i = 1 ; i <= t ; ++i ) {
		//cout << "Case " << i << ": " ;
		do_task();
	}


	return 0;
}
// resize-pane -L 30 
