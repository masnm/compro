#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

struct LSQ {
	int n, len;
	vector<ll> a, b, lp;
	LSQ ( int _n, int _a ) : n ( _n ) {
		len = (int) sqrt ( n + .0 ) + 1;
		b.assign ( len, 0 );
		lp.assign ( len, 0 );
		a.assign ( n, 0 );
	}
	LSQ ( int _n ) : n ( _n ) {
		len = (int) sqrt ( n + .0 ) + 1;
	}
	LSQ ( const vector<ll>& v ) : LSQ ( v.size() ) {
		b.assign ( len, 0 );
		lp.assign ( len, 0 );
		a = v;
		for ( int i = 0 ; i < n ; ++i )
			b [ i / len ] += a[i];
	}
	void update ( int l, int r, ll val ) {
		int c_l = l / len, c_r = r / len;
		if ( c_l == c_r )
			for ( int i = l ; i <=r ; ++i ) {
				a[i] += val;
				b [ i/len ] += val;
			}
		else {
			for ( int i = l, end = ( c_l + 1 ) * len - 1 ; i <= end ; ++i ) {
				a[i] += val;
				b [ i/len ] += val;
			}
			for ( int i = c_l + 1 ; i <= c_r - 1 ; ++i )
				lp[i] += val;
			for ( int i = c_r * len ; i <= r ; ++i ) {
				a[i] += val;
				b [ i/len ] += val;
			}
		}
	}
	ll sum ( int l, int r ) {
		ll sum = 0;
		int c_l = l / len, c_r = r / len;
		if ( c_l == c_r )
			for ( int i = l ; i <= r ; ++i )
				sum += a[i], sum += lp [ i/len ];
		else {
			for ( int i = l, end = (c_l + 1) * len - 1; i <= end ; ++i )
				sum += a[i], sum += lp[i/len];
			for ( int i = c_l + 1 ; i <= c_r - 1 ; ++i )
				sum += b[i], sum += lp[i/len]*len;
			for ( int i = c_r * len ; i <= r ; ++i )
				sum += a[i], sum += lp[i/len];
		}
		return sum;
	}
};

void solve ()
{
	int n, c;
	scanf ( "%d%d", &n, &c );
	LSQ lsq ( n, c );
	int zo, p, q;
	ll v;
	for ( int cc = 0 ; cc < c ; ++cc ) {
		scanf ( "%d", &zo );
		if ( zo == 0 ) {
			scanf ( "%d%d%lld", &p, &q, &v );
			lsq.update ( p-1, q-1, v );
		} else {
			scanf ( "%d%d", &p, &q );
			printf ( "%lld\n", lsq.sum ( p-1, q-1 ) );
		}
	//}
	debug() << imie ( lsq.a );
	debug() << imie ( lsq.b );
	debug() << imie ( lsq.lp );
	debug() << imie ( lsq.len );
	}
}

int main ( int argc, char** argv )
{
	int t;
	scanf ( "%d", &t );
	while ( t-- ) {
		solve();
	}


	puts("");
	return 0;
}
