#include <bits/stdc++.h>

using namespace std;

void prepare_lookup_table ()
{
}

struct st {
	int sum = 0;
	int mn = INT_MAX;
	int mx = INT_MIN;
};

void do_task ()
{
	int n,m; cin >> n >> m;
	vector<vector<pair<int,int>>> gp(n+1);
	int s,e,w;
	while ( m-- ) {
		cin >> s >> e >> w;
		gp[s].emplace_back(e,w);
		gp[e].emplace_back(s,w);
	}
	bool visited[n+1] = { };
	queue<int> q; q.push(1); visited[1] = true;
	st out[n+1];
	out[1].sum = 0;
	while ( !q.empty() ) {
		int top = q.front(); q.pop();
		for ( auto i : gp[top] ) {
			if ( i.first != 1 && !visited[i.first] ) {
				out[i.first].sum = out[top].sum + i.second;
				out[i.first].mn = min ( out[top].mn, i.second );
				out[i.first].mx = max ( out[top].mx, i.second );
				q.push(i.first);
				visited[i.first] = true;
			} else if ( i.first != 1 ) {
				int tsm = out[top].sum + i.second,
				    tmx = max ( out[top].mx, i.second ),
				    tmn = min ( out[top].mn, i.second );
				if ( (out[i.first].sum-out[i.first].mx+out[i.first].mn) > (tsm-tmx+tmn) ) {
					out[i.first].sum = tsm;
					out[i.first].mn = tmn;
					out[i.first].mx = tmx;
					q.push(i.first);
				}
			}
		}
	}
	for ( int i = 2 ; i <= n ; i++ ) {
		cout << out[i].sum - out[i].mx + out[i].mn << " ";
	}
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	prepare_lookup_table();

	int t = 1;
	//cin >> t;
	while ( t-- ) {
		do_task();
	}


	return 0;
}
