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
const int blog = 19;

int N, M, Q, NEXT = 0;
int l, r, cp;
int hits = 0, dt = 0;
vector<bool> vis ( nax );
vector<node> g[nax];
vector<int> hitv ( nax ), rtoc ( nax ), disco ( nax );
vector<int> q, g2[nax], parents, depth;
vector<pair<int, int>> vpq;

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
    fill ( hitv.begin (), hitv.end (), 0 );
    fill ( vis.begin (), vis.end (), false );
    fill ( disco.begin (), disco.end (), INT_MAX );
    dfs ( 0 );

    // compressing the graph
    fill ( rtoc.begin (), rtoc.end (), -1 );
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
    for ( int i = 0; i < NEXT; ++i ) {
        auto &next = g2[i];
        sort ( next.begin (), next.end () );
        next.resize ( unique ( next.begin (), next.end () ) - next.begin () );
    }

    vis.resize ( NEXT );
    for ( int qq = 0; qq < Q; ++qq ) {
        scanf ( "%d%d", &l, &r );
        l = rtoc[l - 1];
        r = rtoc[r - 1];
        // doing bfs
        vpq.clear ();
        vpq.eb ( l, 0 );
        fill ( vis.begin (), vis.end (), false );
        for ( int i = 0; i < int ( vpq.size () ); ++i ) {
            cp = vpq[i].F;
            if ( cp == r ) {
                printf ( "%d\n", vpq[i].S );
                break;
            }
            if ( vis[cp] ) continue;
            vis[cp] = true;
            for ( auto &x : g2[cp] ) {
                if ( !vis[x] ) {
                    vpq.eb ( x, vpq[i].S + 1 );
                }
            }
        }
    }

    return 0;
}
