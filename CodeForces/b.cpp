#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long double ld;
typedef long long int ll;
typedef unsigned long long ull;

const ll inf = 1e18 + 5;

template<typename T> void chmax ( T& a, T b ) { if ( a < b ) a = b; }
template<typename T> void chmin ( T& a, T b ) { if ( a > b ) a = b; }

const int nax = 1000006;
bitset<nax> bits;
vector<int> prms;
void prepare_lookup_table ()
{
	bits[0] = bits[1] = true;
	for ( int i = 2 ; i * i < nax ; ++i ) {
		if ( !bits[i] ) {
			for ( int j = i * i ; j < nax ; j += i ) {
				bits[j] = true;
			}
		}
	}
	for ( int i = 0 ; i < nax ; ++i ) if ( !bits[i] ) prms.emplace_back(i);
}

void do_task ()
{
	int l, h; cin >> l >> h;
	int idc = 0, ind;
	int limit = h - l + 1;
	vector<int> id ( limit + 1, -1 );
	for ( const int& x : prms ) {
		if ( x >= h ) break;
		bool idf = false; int chid;
		for ( int i = l ; i <= h ; ++i ) {
			ind = i-l;
			if ( i % x == 0 && id[ind] != -1 ) {
				idf = true;
				chid = id[ind];
				break;
			}
		}
		if ( idf ) {
			for ( int i = l ; i <= h ; ++i ) {
				ind = i - l;
				if ( i % x == 0 ) {
					id[ind] = chid;
				}
			}
		} else {
			for ( int i = l ; i <= h ; ++i ) {
				ind = i - l;
				if ( i % x == 0 ) {
					id[ind] = idc;
				}
			}
			++idc;
		}
	}
	//cout << idc << endl;
	//return;
	vector<int> v ( idc, 0 );
	for ( int i = 0 ; i < limit ; ++i ) if ( id[i] != -1 ) ++v[id[i]];
	int sum = accumulate ( v.begin(), v.end(), 0 );
	sort ( v.begin(), v.end() );
	int alone = limit - sum ;
	int compo = alone + v.size();
	cout << compo << endl;
	for ( int i = 0 ; i < alone ; ++i ) cout << 1 << endl;
	for ( int i = 0 ; i < idc ; ++i ) cout << v[i] << endl;
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	prepare_lookup_table();

	int t = 1;
	cin >> t;
	for ( int i = 1 ; i <= t ; ++i ) {
//		cout << "Case " << i << ": " ;
		do_task();
	}


	return 0;
}
