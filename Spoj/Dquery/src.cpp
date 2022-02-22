#include <bits/stdc++.h>
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

//struct BIT {
//	int n;
//	vector<int> v;
//	BIT ( int _n ) : n ( _n )
//	{
//		v.clear();
//		v.resize ( n );
//	}
//	BIT ( const vector<int> _v ) : BIT ( _v.size() )
//	{
//		for ( int i = 0 ; i < n ; ++i ) {
//			add ( i, _v[i] );
//		}
//	}
//	int sum ( int r )
//	{
//		int ans = 0;
//		for ( ; r > -1 ; r = ( (r & ( r + 1 ) ) - 1 ) ) {
//			ans += v[r];
//		}
//		return ans;
//	}
//	int sum ( int l, int r )
//	{
//		return sum ( r ) - sum ( l - 1 );
//	}
//	void add ( int ind, int diff )
//	{
//		for ( ; ind < n ; ind |= ( ind + 1 ) ) {
//			v[ind] += diff;
//		}
//	}
//};

struct BIT {
	int n;
	vector<int> v;
	BIT ( int _n ) : n ( _n + 1 ) {
		v.assign(n,0);
	}
	int sum ( int r ) {
		int ans = 0;
		for ( ++r ; r > 0 ; r -= ( r & ( -r ) ) ) {
			ans += v[r];
		}
		return ans;
	}
	int sum ( int l, int r ) {
		return sum ( r ) - sum ( l - 1 );
	}
	void add ( int i, int diff ) {
		for ( ++i ; i < n ; i += ( i & ( -i ) ) ) {
			v[i] += diff;
		}
	}
};

int main ( int argc, char** argv )
{
	const int nax = 1000005;
	vector<int> pos_of_last(nax, -1);
	int n;
	scanf ( "%d", &n );
	vector<int> a(n, 0), cnt(nax, 0);
	for ( int i = 0 ; i < n ; ++i ) scanf ( "%d", &a[i] );
	int qq, l, r;
	scanf ( "%d", &qq );
	vector<pair<int,int>> vp;
	vector<vector<pair<int,int>>> vv ( n, vector<pair<int,int>>() );
	for ( int i = 0 ; i < qq ; ++i ) {
		scanf ( "%d%d", &l, &r ); --l; --r;
		vp.emplace_back ( l, r );
		vv[r].emplace_back ( l, 0 );
	}
	BIT bit( n );
	for ( int i = 0 ; i < n ; ++i ) {
		if ( pos_of_last [ a[i] ] != -1 ) {
			//-- cnt [ pos_of_last [ a[i] ] ];
			bit.add ( pos_of_last[a[i]], -1 );
		}
		pos_of_last [ a[i] ] = i;
		//++ cnt [ pos_of_last [ a[i] ] ];
		bit.add ( pos_of_last[a[i]], 1 );
		for ( pair<int,int>& q : vv[i] ) {
		//	int sum = 0;
		//	for ( int j = q.first ; j <= i ; ++j ) {
		//		sum += cnt[j];
		//	}
		//	q.second = sum;
			q.second = bit.sum ( q.first, i );
		}
	}
	for ( pair<int,int>& i : vp ) {
		for ( pair<int,int>& j : vv[i.second] ) {
			if ( j.first == i.first ) {
				printf ( "%d\n", j.second );
				break;
			}
		}
	}

	return 0;
}
