#include "bits/stdc++.h"
using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

#define F first
#define S second
#define eb emplace_back

using ll = long long int;

#warning change nax before submit
const int nax = 5005;
const int inf = 1e9+5;
int v, c, k;
vector<int> va ( nax ), ca ( nax );
vector<int> da ( nax );
//vector<vector<int>> dp(nax, vector<int>(nax));

void solve ()
{
	scanf("%d%d%d", &v, &c, &k );
	for ( int& i : va ) i=0;
	for ( int& i : ca ) i=0;
	for ( int i = 0 ; i < v ; ++i ) scanf("%d", &va[i] );
	for ( int i = 0 ; i < c ; ++i ) scanf("%d", &ca[i] );
	int sum = 0;
	map<int,int> mp;
	map<int,int> ans;
	for ( int i = 0 ; i < k-1 ; ++i ) ++mp[va[i]], sum += va[i];;
	++mp[ca[0]]; sum += ca[0];
	int fl = 1, fr = k - 1;
	ans = mp;
	int l = 1, r = k - 2;
	int cs = sum;
	while ( l < k - 1 ) {
		cs -= va[r];
		cs += ca[l];
		if ( cs > sum ) {
			--mp[va[r--]];
			++mp[ca[l++]];
			sum = cs;
			ans = mp;
			fl = l-1;
			fr = r+1;
		} else if ( cs == sum ) {
			int ind = 0;
			for ( auto & i : mp )
				for ( int x = 0 ; x < i.second ; ++x )
					da[ind++] = i.first;
			--mp[va[r--]];
			++mp[ca[l++]];
			ind = 0;
			bool df = false;
			bool less = true;
			for ( auto & i : mp )
				for ( int x = 0 ; x < i.second ; ++x ) {
					if ( da[ind] != i.first ) df = true;
					if ( da[ind++] > i.first )
						less = false;
				}
			if ( less && df ) {
				ans = mp;
				fl = l-1;
				fr = r+1;
			}
		} else {
			--mp[va[r--]];
			++mp[ca[l++]];
		}
	}
	printf ( "%d\n", sum );
	int sl = 0, sr = 0;
	bool printed = true;
	debug() << imie(ans);
	while ( printed ) {
		printed = false;
		for ( auto & i : ans ) {
			if ( i.second == 0 ) continue;
			if ( i.first == va[sl] ) {
				++sl;
				printf ( "%d ", i.first );
				printed = true;
				--i.second;
				break;
			} else if ( i.first == ca[sr] ) {
				++sr;
				printf ( "%d ", i.first );
				printed = true;
				--i.second;
				break;
			}
		}
	}
	puts("");
	debug() << imie(fl) imie(fr);
}

int main ()
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}
//void solve ()
//{
//	scanf("%d%d%d", &v, &c, &k );
//	for ( int i = 0 ; i < nax ; ++i ) for ( int j = 0 ; j < nax ; ++j ) dp[i][j] = -1;
//	for ( int i = 0 ; i < v ; ++i ) scanf("%d", &va[i] );
//	for ( int i = 0 ; i < c ; ++i ) scanf("%d", &ca[i] );
//	dp[0][0] = 0;
//	for ( int i = 0 ; i <= k ; ++i ) {
//		for ( int j = 0 ; j <= k ; ++j ) {
//			dp[i][j] = max ( i>0?dp[i-1][j]+va[i]:0, j>0?dp[i][j-1]+ca[j]:0 );
//		}
//	}
//	for ( int i = 0 ; i < nax ; ++i ) {
//		debug() << imie(dp[i]);
//	}
//	printf ( "%d\n", dp[k][k] );
//}
