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

template<typename T>
struct FenwickTree {
	int n;
	vector<T> tree;
	FenwickTree ( vector<int>& _v )
	{
		n = _v.size();
		tree = vector<T>(n);
		for ( int i = 0 ; i < n ; ++i ) {
			int ind = i + 1, val = _v[i];
			while ( ind < n ) {
				tree[ind] += val;
				ind += ( ind & -ind );
			}
		}
	}
	FenwickTree ( int _n )
	{
		n = _n;
		tree = vector<T>(n);
	}
	void add ( int ind, T val )
	{
		++ind;
		for ( ; ind < n ; ind += ( ind & -ind ) )
			tree[ind] += val;
	}
	T sum ( int r )
	{
		T s{};
		for ( ; r > 0 ; r -= ( r & -r ) )
			s += tree[r];
		return s;
	}
};

const int nax = 2e5 + 5;
int n, q, a, b;
vector<int> v ( nax );

void solve ()
{
	scanf ( "%d%d", &n, &q );
	for ( int i = 0 ; i < n ; ++i ) scanf ( "%d", &v[i] );
	FenwickTree<ll> ft ( v );
	for ( int i = 0 ; i < q ; ++i ) {
		scanf ( "%d%d", &a, &b );
		printf ( "%lld\n", ft.sum(b) - ft.sum(a-1) );
	}
}

int main ()
{
	int t = 1;
//	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

