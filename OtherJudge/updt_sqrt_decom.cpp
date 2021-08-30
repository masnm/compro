#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	scanf("%d", &n);
	vector<int> v ( n );
	for ( int i = 0 ; i < n ; ++i ) {
		scanf("%d",&v[i]);
	}
	
	int sq = sqrt( n + .0 );
	vector<int> b ( sq + 1 );
	
	for ( int i = 0 ; i < n ; ++i ) {
		b[i/sq] += v[i];
	}
	
	int q;
	scanf("%d",&q);
	while ( q-- ) {
		int type;
		scanf("%d",&type);
		if ( type == 2 ) {
			int s, e;
			scanf ( "%d%d", &s , &e );
			--s; --e;
			int sum = 0;
			if ( e - s <= sq ) {
				for ( int i = s ; i <= e ; ++i ) {
					sum += v[i];
				}
			} else {
				int ni, nj;
				if ( s % sq ) {
					ni = s / sq + 1;
					ni *= sq;
					for ( int i = s ; i < ni ; ++i ) {
						sum += v[i];
					}
					s = ni;
				}
				nj = e / sq;
				for ( int i = s/sq ; i < nj ; ++i ) {
					sum += b[i];
				}
				for ( int i = nj * sq ; i <= e ; ++i ) {
					sum += v[i];
				}
			}
			printf("%d\n",sum);
		} else {
			int ind, val;
			scanf("%d%d",&ind,&val);
			--ind;
			val -= v[ind];
			b[ind/sq] += val;
			v[ind] += val;
		}
	}

	return 0;
}
