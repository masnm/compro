#include "bits/stdc++.h"
using namespace std;

class TreeAncestor {
    int log = 20;
    vector<vector<int>> vvi = vector<vector<int>>(20, vector<int>(50005));
    vector<int> depth;
    int dfs ( vector<int>& parent, int me ) {
        if ( depth[me] == -1 ) {
            int ret = dfs ( parent, depth[parent[me]]);
            depth[me] = 1 + ret;
        }
        return depth[me];
    }
public:
    TreeAncestor(int n, vector<int>& parent) {
        parent[0] = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            vvi[0][i] = parent[i];
        }
        for ( int i = 1 ; i < log ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                vvi[i][j] = vvi[i-1][vvi[i-1][j]];
            }
        }
        depth.clear();
        depth.assign ( n, -1 );
        depth[0] = 0;
        for ( int i = 1 ; i < n ; ++i ) {
            depth[i] = dfs ( parent, i );
            int ind = 0;
            for ( int d : depth ) {
                cout << ind++ << " " << d << endl;
            }
            cout << endl;
        }
    }

    int getKthAncestor(int node, int k) {
        if ( k > depth[node] ) return -1;
        for ( int i = 0 ; i < log ; ++i )
            if ( k & (1<<i) ) {
                node = vvi[i][node];
            }
        return node;
    }
};

int main ()
{
	vector<int> v = {-1,0,0,1,2,0,1,3,6,1};
	TreeAncestor t ( 10, v );
	cout << t.getKthAncestor ( 8, 9 ) << endl;

	return 0;
}
