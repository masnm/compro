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

ll x, y, z;
ll _x, _y, _z;

bool ok ()
{
	for ( int i = 0 ; i < 4 ; ++i ) {
		if ( _x > _y ) swap ( _x, _y );
		if ( _y > _z ) swap ( _y, _z );
	}
	return ( x==_x && y==_y && z==_z );
}

ll get ( vector<ll>& v, int sz )
{
	ll count = 0;
	vector<ll> ps(sz,0);
	ps[0] = v[0];
	for ( int i = 1 ; i < sz ; ++i )
		ps[i] = ps[i-1] + v[i];
	for ( int i = 0 ; i < sz ; ++i ) {
		for ( int j = i + 1 ; j < sz ; ++j ) {
			for ( int k = j + 1 ; k < sz ; ++k ) {
				_x = ps[i];
				_y = ps[j] - ps[i];
				_z = ps[k] - ps[j];
				if ( ok () ) ++count;
			}
		}
	}
	return count;
}

void solve ()
{
	int a, b;
	scanf ( "%d%d", &a, &b );
	vector<ll> l(a), u(b);
	ll t;
	for ( int i = 0 ; i < a ; ++i )
		for ( int j = 0 ; j < b ; ++j ) {
			scanf ( "%lld", &t );
			l[i] += t;
			u[j] += t;
		}
	scanf ( "%lld%lld%lld", &x, &y, &z );
	for ( int i = 0 ; i < 4 ; ++i ) {
		if ( x > y ) swap ( x, y );
		if ( y > z ) swap ( y, z );
	}
	ll ans = get ( l, a );
	ans += get ( u, b );
	printf ( "%lld", ans );
}

int main ()
{
	int t = 1;
	for ( int i = 0 ; i < t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

