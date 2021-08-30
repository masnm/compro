#include<bits/stdc++.h>

using namespace std;

void input( vector<int> **g,int node)
{
    for(int i = 0; i < node; i++)
    {
        cout << "Enter Edge for node "<<i<<" :";
        int edge;
        cin >> edge;
        for(int j = 0; j < edge; j++)
        {
            int temp;
            cin >> temp;
            (*g[i]).push_back(temp);
        }
    }


    for (int i=0; i<node; i++)
    {
        cout << "parent node "<< i<<" : ";
        for(int j=0; j<(*g[i]).size(); j++)
        {
            cout<<(*g[i])[j]<< " ";
        }
        cout << endl;
    }

}

void bfs(vector<int>** g,int source)
{
//    queue<int> q;
//
//    q.push(source)
//
//    int x= q.front();
//
//    q.pop();

    while(true)
    {
        int i;
        for(int j=0; j<(*g[i]).size(); j++)
        {
            cout<<(*g[i])[j]<< " ";
        }
        cout << endl;

        i++;


    }

//

  //  for(i=0;, )




}







int main()
{

    int node ;

    cin>> node;
    vector<int> g[node];

   // input(&g, node);

   // bfs(&g, node);





   for(int i = 0; i < node; i++)
    {
        cout << "Enter Edge for node "<<i<<" :";
        int edge;
        cin >> edge;
        for(int j = 0; j < edge; j++)
        {
            int temp;
            cin >> temp;
            g[i].push_back(temp);
        }
    }


    for (int i=0; i<node; i++)
    {
        cout << "parent node "<< i<<" : ";
        for(int j=0; j<g[i].size(); j++)
        {
            cout<<g[i][j]<< " ";
        }
        cout << endl;
    }

	const int size = 25;
    vector<int> v(size, 0);
    
    queue<int> q;
    q.push(0);
    v[0] = 0;
    while ( !q.empty() ) {
    	int cp = q.front();
    	// for ( int i : g[cp] ) 
    	for ( int i = 0 ; i < g[cp].size() ; ++i ) {
    		v[g[cp][i]] = v[cp] + 1;
    	}
    }
    
    int cdepth = -1;
    //q.clear();
    q.push(0);
    while ( !q.empty() ) {
    	int cp = q.front();
    	if ( v[cp] != cdepth ) {
    		cdepth = v[cp];
    		cout << endl;
    	}
    	// for ( int i : g[cp] ) 
    	for ( int i = 0 ; i < g[cp].size() ; ++i ) {
    		cout << g[cp][i] << " ";
    	}
    }
    
    /*
    6
    1 2
    3 4
    5
    0
    0
    0
    */
    /*0 12 345*/

    /*
        BFS


    /*
    0
    12
    235
    */



    return 0;
}


