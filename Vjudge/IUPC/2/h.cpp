#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

struct proposal {
    char name[ 85 ];
    double price;
    int number, index;
};

bool operator < ( proposal a, proposal b ) {
    if ( a.number != b.number ) return a.number > b.number;
    if ( a.price != b.price ) return a.price < b.price;
    return a.index < b.index;
}

int main() {
    FI FO
    int n, p, tc = 0;

    while ( cin >> n >> p ) {
        cin.ignore();
        if ( n == 0 && p == 0 ) break;

        char s[ 85 ];
        for ( int i = 0; i < n; i++ ) cin.getline( s, 85);

        proposal arr[ p ];
        for ( int i = 0; i < p; i++ ) {
			scanf ( "%[[^\n]\n", arr[i].name );
            cin >> arr[ i ].price >> arr[ i ].number;
            arr[ i ].index = i;
            cin.ignore();

            for ( int j = 0; j < arr[ i ].number; j++ ) cin.getline( s, 85);
        }
        sort( arr, arr+p );

//        for ( int i = 0; i < p; i++ ) {
//            cout << arr[ i ].index space arr[ i ].name space arr[ i ].price space arr[ i ].number << endl;
//        }
        tc++;
        if ( tc > 1 ) cout << endl;

        cout << "RFP #" << tc << endl;
        for ( int i = 0; arr[ 0 ].name[i] != '\0'; i++ )
            cout << arr[ 0 ].name[ i ];
        cout << endl;
    }

    return 0;
