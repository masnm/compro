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
	int size;
	vector<T> bit;
	vector<int> vals;
	FenwickTree ( vector<int> arr )
	{
		vals = arr;
		size = arr.size() + 1;
		bit.assign ( size, 0 );
		for ( int i = 0 ; i < (int)arr.size() ; ++i ) {
			int ind = i + 1, val = arr[i];
			for ( ; ind < size ; ind += ( ind & -ind ) )
				bit[ind] += val;
		}
	}
	void add ( int ind, int val )
	{
		int diff = val - vals[ind]; vals[ind] = val;
		for ( ++ind ; ind < size ; ind += ( ind & -ind ) )
			bit[ind] += diff;
	}
	T sum ( int ind )
	{
		T s{};
		for ( ++ind ; ind > 0 ; ind -= ( ind & -ind ) )
			s += bit[ind];
		return s;
	}
};

int n, q, l, r, x, op;
vector<int> v;

int main ()
{
	scanf ( "%d%d", &n, &q );
	v = vector<int>(n);
	for ( int i = 0 ; i < n ; ++i ) scanf ( "%d", &v[i] );
	FenwickTree<ll> ft ( v );
	while ( q-- ) {
		scanf ( "%d", &op );
		if ( op == 1 ) {
			scanf ( "%d%d", &l, &x );
			ft.add ( --l, x );
		} else if ( op == 2 ) {
			scanf ( "%d%d", &l, &r );
			--l; --r;
			printf ( "%lld\n", ft.sum(r) - ft.sum(l-1) );
		} else assert(false);
	}

	return 0;
}

