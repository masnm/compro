#include "bits/stdc++.h"
using namespace std;

#define F first
#define S second
#define eb emplace_back

using ll = long long int;

int n, t, k, _t;
map<pair<int,int>,int> ump;

int main ()
{
	scanf ( "%d%d", &n, &t );
	while ( t-- ) {
		scanf ( "%d", &k );
		int low = 1, high = n, mid, lzc = 0, zh;
		while ( low < high ) {
			mid = low + (high - low)/2;
			auto src = ump.find(make_pair(low,mid));
			if ( src == ump.end() ) {
				printf ( "? %d %d\n", low, mid );
				fflush ( stdout );
				scanf ( "%d", &_t );
				ump[make_pair(low,mid)] = _t;
			}
			src = ump.find(make_pair(low,mid));
			zh = lzc + (mid - low + 1) - src->second;
			if ( zh < k ) {
				low = mid+1;
				lzc = zh;
			} else {
				++ump[make_pair(low,mid)];
				high = mid;
			}
		}
		++ump[make_pair(low,low)];
		printf ( "! %d\n", low );
		fflush ( stdout );
	}

	return 0;
}
