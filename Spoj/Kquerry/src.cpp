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

struct BIT {
	int n;
	vector<int> v;
	BIT ( int _n ) : n ( _n+1 ) {
		v.assign ( n, 0 );
	}
	BIT ( const vector<int>& a ) : BIT ( a.size() ) {
		for ( int i = 0 ; i < n - 1 ; ++i ) {
			add ( i, a[i] );
		}
	}
	void add ( int ind, int val ) {
		for ( ++ind ; ind < n ; ind += ( ind & ( -ind ) ) ) {
			v[ind] += val;
		}
	}
	int sum ( int r ) {
		int sum = 0;
		for ( ++r ; r > 0 ; r -= ( r & ( -r ) ) ) {
			sum += v[r];
		}
		return sum;
	}
	int sum ( int l, int r ) {
		return sum ( r ) - sum ( l - 1 );
	}
};

struct tri {
	int l, r, x;
	tri ( int _l, int _r, int _x )
		: l(_l), r(_r), x(_x)
	{ }
};

int main ( int argc, char** argv )
{
	int n;
	scanf ( "%d", &n );
	vector<int> v ( n ), vc ( n ), si ( n );
	vector<pair<int,int>> vp ( n );
	for ( int i = 0 ; i < n ; ++i ) {
		scanf ( "%d", &v[i] );
		vc[i] = v[i];
		vp[i].first = v[i];
		vp[i].second = i;
	}
	sort ( vp.begin(), vp.end() );
	sort ( vc.begin(), vc.end() );
	for ( int i = 0 ; i < n ; ++i ) {
		si[vp[i].second] = i;
	}
	int q;
	scanf ( "%d", &q );
	vector<tri> vt;
	vector<vector<pair<int,int>>> vdq ( n + 1, vector<pair<int,int>>() );
	int l, r, x;
	for ( int i = 0 ; i < q ; ++i ) {
		scanf ( "%d%d%d", &l, &r, &x );
		--l, --r, --l;
		vt.emplace_back ( l, r, x );
		if ( l > -1 ) vdq[l].emplace_back ( x, 0 );
		vdq[r].emplace_back ( x, 0 );
	}
	BIT bit ( n );
	for ( int i = 0 ; i < n ; ++i ) {
		bit.add ( si[i], 1 );
		for ( pair<int,int>& pp : vdq[i] ) {
			int tk = pp.first;
			int indx = int (distance ( vc.begin(), upper_bound ( vc.begin(), vc.end(), tk ) ));
			pp.second = bit.sum ( indx, n-1 );
		}
	}
	for ( tri& i : vt ) {
		// i.l i.r i.x
		int lv = 0, rv = 0;
		if ( i.l > -1 ) {
			for ( pair<int,int>& j : vdq[i.l] ) {
				if ( j.first == i.x ) {
					lv = j.second;
					break;
				}
			}
		}
		for ( pair<int,int>& j : vdq[i.r] ) {
			if ( j.first == i.x ) {
				rv = j.second;
				break;
			}
		}
		//printf ( "%d %d %d %d %d %d\n", i.l, i.r, i.x, rv, lv, rv - lv );
		printf ( "%d\n", rv-lv );
	}


	puts("");
	return 0;
}
