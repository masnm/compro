#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long double ld;
typedef long long int ll;
typedef unsigned long long ull;

const ll inf = 1e18 + 5;
const ll mod = 1e9 + 7;

template<typename T> void chmax ( T& a, T b ) { if ( a < b ) a = b; }
template<typename T> void chmin ( T& a, T b ) { if ( a > b ) a = b; }

void prepare_lookup_table ()
{
}

void build_tree ( vector<vector<int>>& tree, int nn )
{
	int l, r;
	for ( int i = nn - 1 ; i > 0 ; --i ) {
		l = 2 * i;
		r = 2*i + 1;
		for ( int j = 0 ; j < 26 ; ++j ) {
			tree[i][j] = tree[l][j] + tree[r][j];
		}
	}
}

void update_tree ( vector<vector<int>>& tree, int me, int ms, int mf, int qs, int qe, char add, char neg )
{
	if ( qs > mf || qe < ms ) return;
	if ( ms >= qs && mf <= qe ) {
	//if ( qs >= ms && qe <= mf ) {
		--tree[me][neg-'a'];
		++tree[me][add-'a'];
		return;
	}
	int mid = ( ms + mf ) / 2;
	update_tree ( tree, 2*me, ms, mid, qs, qe, add, neg );
	update_tree ( tree, 2*me+1, mid+1, mf, qs, qe, add, neg );
}

int count_tree ( vector<vector<int>>& tree, int me, int ms, int mf, int qs, int qf, char ch )
{
	if ( qs > mf || qf < ms ) return 0;
	if ( ms >= qs && mf <= qf ) {
	//if ( qs >= ms && qf <= mf ) {
		return tree[me][ch-'a'];
	}
	int mid = ( ms + mf ) / 2;
	return count_tree ( tree, 2*me, ms, mid, qs, qf, ch ) + count_tree ( tree, 2*me+1, mid+1, mf, qs, qf, ch );
}

void do_task ()
{
	int n, q; cin >> n >> q;
	string s; cin >> s;
	int nn = __builtin_popcount(n) == 1 ? n : (1<<(32-__builtin_clz(n)));
	vector<vector<int>> tree ( 2 * nn, vector<int>( 26 ) );
	for ( int i = 0 ; i < n ; ++i ) {
		++tree[nn+i][s[i]-'a'];
	}
	build_tree ( tree, nn );
	int x, l, r, xx;
	char ch;
	for ( int i = 0 ; i < q ; ++i ) {
		cin >> xx;
		if ( xx == 1 ) {
			cin >> x >> ch;
			update_tree ( tree, 1, 0, nn-1, x-1, x-1, ch, s[x-1] );
			s[x-1] = ch;
		} else {
			cin >> l >> r >> ch;
			x = count_tree ( tree, 1, 0, nn-1, l-1, r-1, ch );
			cout << x << endl;
		}
	}
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	prepare_lookup_table();

	int t = 1;
	for ( int i = 1 ; i <= t ; ++i ) {
//		cout << "Case " << i << ": " ;
		do_task();
	}


	return 0;
}

