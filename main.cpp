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

void dfa ( vector<vector<ll>>& g, ll s, vector<bool>& v, stack<ll>& st )
{
	for ( auto& i : g[s] ) {
		if ( !v[i] ) {
			v[i] = true;
			dfa ( g, i, v, st );
		}
	}
	st.push(s);
}

void dfb ( vector<vector<ll>>& g, ll s, vector<bool>& v, ll& id, vector<ll>& ids )
{
	ids[s] = id;
	for ( auto& i : g[s] ) {
		if ( !v[i] ) {
			v[i] = true;
			dfb ( g, i, v, id, ids );
		}
	}
}

ll dfs ( vector<vector<ll>>& g, vector<bool>& v, ll s, ll e, vector<ll>& ans, vector<ll>& fun )
{
	if ( s == e ) {
		return fun[e];
	}
	ll ca = LLONG_MIN;
	v[s] = true;
	for ( auto& i : g[s] ) {
		if ( !v[i] ) {
			v[i] = true;
			ans[i] = dfs ( g, v, i, e, ans, fun );
		}
		chmax ( ca, ans[i] );
	}
	ans[s] = fun[s] + ( ca == LLONG_MIN ? 0 : ca );
	return ans[s];
}

void do_task ()
{
	ll n,m,s,e; cin >> n >> m >> s >> e; --s; --e;
	vector<vector<ll>> ga ( n, vector<ll>() ), gb ( n, vector<ll>() );
	vector<ll> cst ( n );
	for ( auto& i : cst ) cin >> i;
	ll ss, ee;
	for ( ll i = 0 ; i < m ; ++i ) {
		cin >> ss >> ee; --ss; --ee;
		ga[ss].emplace_back(ee);
		gb[ee].emplace_back(ss);
	}
	vector<bool> v ( n, false );
	stack<ll> st;
	for ( ll i = 0 ; i < n ; ++i ) {
		if ( !v[i] ) {
			v[i] = true;
			dfa ( ga, i, v, st );
		}
	}
	for ( ll i = 0 ; i < n ; ++i ) v[i] = false;
	vector<ll> ids ( n, -1 );
	ll id = 0, top;
	while ( !st.empty() ) {
		top = st.top(); st.pop();
		if ( !v[top] ) {
			v[top] = true;
			dfb ( gb, top, v, id, ids );
			++id;
		}
	}
	set<pair<ll,ll>> vt;
	for ( ll i = 0 ; i < n ; ++i ) {
		for ( auto& j : ga[i] ) {
			ss = ids[i], ee = ids[j];
			if ( ss != ee )
				vt.insert ( { ss, ee } );
		}
	}
	vector<ll> fun ( id, 0 );
	for ( ll i = 0 ; i < n ; ++i ) {
		fun[ids[i]] += cst[i];
	}
	vector<vector<ll>> gc ( id, vector<ll>() );
	for ( auto& i : vt ) {
		gc[i.first].emplace_back(i.second);
	}
	s = ids[s];
	e = ids[e];
	vector<ll> ans ( id, -1 );
	for ( ll i = 0 ; i < id ; ++i ) v[i] = false;
	ans[e] = fun[e];
	ll fans = dfs ( gc, v, s, e, ans, fun );
	cout << fans << endl;
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
