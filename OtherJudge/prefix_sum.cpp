#include <bits/stdc++.h>
using namespace std;


int main ()
{
	int n; scanf("%d",&n);
	vector<int> v ( n );
	for ( int i = 0 ; i < n ; ++i ) {
		scanf("%d",&v[i]);
	}
	vector<int> prefix_sum ( n );
	prefix_sum[0] = v[0];
	for ( int i = 1 ; i < n ; ++i ) {
		prefix_sum[i] = prefix_sum[i-1] + v[i];
	}
	int q; scanf("%d",&q);
	for ( int i = 0 ; i < q ; ++i ) {
		int si, ei;
		scanf ( "%d%d", &si, &ei);
		--si;
		--ei;
		int sum = 0;
		int left = (si == 0 ? 0 : prefix_sum[si-1] );
		int right = prefix_sum[ei];
		sum = right - left;
		printf("%d\n",sum);
	}
}
