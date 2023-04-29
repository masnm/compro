#include "bits/stdc++.h"
using namespace std;

#define F  first
#define S  second
#define eb emplace_back

using ll = long long int;

struct node {
    public:
        node () = default;
        node ( int _id ) : id ( _id ), rev_ind ( -1 ), bridge ( false ) {
        }
        node ( int _id, bool _bridge )
            : id ( _id ), rev_ind ( -1 ), bridge ( _bridge ) {
        }
        int id = -1, rev_ind = -1;
        bool bridge = true;
};

const int nax = 500005;
const int blog = 18;
int nodes;
int par[nax][blog];
int N, M, Q, NEXT = 0;
int l, r, cp;
int hits = 0, dt = 0;
vector<bool> vis ( nax );
vector<node> g[nax];
vector<int> hitv ( nax ), rtoc ( nax ), disco ( nax );
vector<int> q, g2[nax], parents, depth;

void sparse_table ( int n ) {
    for ( int i = 0; i < n; ++i )
        par[i][0] = parents[i];
    for ( int k = 1; k < blog; ++k ) {
        for ( int i = 0; i < n; ++i ) {
            par[i][k] = par[par[i][k - 1]][k - 1];
        }
    }
    nodes = n;
}

int get_nth_par ( int node, int _n ) {
    int _par = node;
    for ( int i = blog - 1; i > -1; --i )
        if ( _n & ( 1 << i ) ) _par = par[_par][i];
    return _par;
}

int get_lca ( int a, int b ) {
    if ( a == b ) return a;
    for ( int i = blog - 1; i > -1; --i )
        if ( par[a][i] != par[b][i] ) {
            a = par[a][i];
            b = par[b][i];
        }
    return par[a][0];
}

void bfs ( int me ) {
    fill ( vis.begin (), vis.end (), false );
    q.clear ();
    q.eb ( me );
    for ( int i = 0; i < int ( q.size () ); ++i ) {
        cp = q[i];
        if ( vis[cp] ) continue;
        vis[cp] = true;
        for ( auto &next : g[cp] )
            if ( !vis[next.id] && !next.bridge ) q.eb ( next.id );
    }
}

int dfs ( int me, int parent = -1 ) {
    assert ( vis[me] == false );
    vis[me] = true;
    disco[me] = ++dt;
    int mnt = INT_MAX;
    for ( auto &next : g[me] ) {
        if ( next.id == parent ) continue;
        if ( vis[next.id] ) {
            mnt = min ( mnt, disco[next.id] );
        } else {
            int tmn = dfs ( next.id, me );
            if ( tmn > disco[me] ) {
                next.bridge = true;
                g[next.id][next.rev_ind].bridge = true;
            }
            mnt = min ( mnt, tmn );
        }
    }
    // if ( parent != -1 )
    //     if ( disco[parent] < mnt )
    //         for ( auto &item : g[me] )
    //             if ( item.id == parent ) item.bridge = true;
    return mnt;
}

int main ( void ) {
    scanf ( "%d%d%d", &N, &M, &Q );
    for ( int i = 0; i < N; ++i )
        g[i].clear ();
    for ( int i = 0; i < M; ++i ) {
        scanf ( "%d%d", &l, &r );
        --l;
        --r;
        g[l].eb ( r );
        g[r].eb ( l );
        g[l].back ().rev_ind = g[r].size () - 1;
        g[r].back ().rev_ind = g[l].size () - 1;
    }
    // mark the bridges
    fill ( hitv.begin (), hitv.begin () + N, 0 );
    fill ( vis.begin (), vis.begin () + N, false );
    fill ( disco.begin (), disco.begin () + N, INT_MAX );
    dfs ( 0 );

    // compressing the graph
    fill ( rtoc.begin (), rtoc.begin () + N, -1 );
    for ( int i = 0; i < N; ++i ) {
        if ( rtoc[i] == -1 ) {
            // do bfs and compress
            bfs ( i );
            for ( auto &item : q )
                rtoc[item] = NEXT;
            ++NEXT;
        }
    }

    // creating new graph
    for ( int i = 0; i < N; ++i )
        for ( auto &next : g[i] ) {
            l = rtoc[next.id];
            r = rtoc[i];
            if ( l != r ) {
                g2[l].eb ( r );
                g2[r].eb ( l );
            }
        }

    // sparse table
    // as now g2 is tree so finding parents using bfs
    parents.resize ( NEXT );
    depth.resize ( NEXT );
    fill ( depth.begin (), depth.end (), 0 );
    fill ( vis.begin (), vis.end (), false );
    q.clear ();
    depth[0] = 0;
    parents[0] = 0;
    q.eb ( 0 );
    for ( int i = 0; i < int ( q.size () ); ++i ) {
        cp = q[i];
        if ( vis[cp] ) continue;
        vis[cp] = true;
        for ( auto &next : g2[cp] )
            if ( !vis[next] ) {
                parents[next] = cp;
                q.eb ( next );
                depth[next] = depth[cp] + 1;
            }
    }

    sparse_table ( NEXT );
    for ( int qq = 0; qq < Q; ++qq ) {
        scanf ( "%d%d", &l, &r );
        int _l = rtoc[l - 1], _r = rtoc[r - 1];
        if ( depth[_l] > depth[_r] ) {
            _l = get_nth_par ( _l, depth[_l] - depth[_r] );
        } else if ( depth[_l] < depth[_r] ) {
            _r = get_nth_par ( _r, depth[_r] - depth[_l] );
        }
        int lca = get_lca ( _l, _r );
        printf ( "%d\n", ( depth[rtoc[l - 1]] + depth[rtoc[r - 1]] ) -
                             ( 2 * depth[lca] ) );
    }

    return 0;
}
