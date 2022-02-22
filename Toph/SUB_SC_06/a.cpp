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

int n, x, y;
int sum = 0, pro = 1, start;

int main ()
{
	scanf ( "%d%d%d", &n, &x, &y );
	if ( x == 0 && y == 0 ) {
		puts("Yes");
		start = 2;
		for ( int i = 0 ; i < n ; ++i ) {
			printf ( "%d ", start );
			sum += start;
			pro *= start;
			sum %= 2;
			pro %= 2;
			start += 2;
		}
		assert(sum == 0 && pro == 0);
	} else if ( x == 1 && y == 0 ) {
		if ( n < 2 ) { puts("No"); return 0; }
		puts("Yes");
		start = 1;
		for ( int i = 1 ; i <= n ; ++i ) {
			printf ( "%d ", start );
			sum += start;
			pro *= start;
			sum %= 2;
			pro %= 2;
			if ( start==1 ) start += 1;
			else start += 2;
		}
		assert(sum == 1 && pro == 0);
	} else if ( x == 0 && y == 1 ) {
		if ( n & 1 ) { puts("No"); return 0; }
		puts("Yes");
		start = 1;
		for ( int i = 0 ; i < n ; ++i ) {
			printf ( "%d ", start );
			sum += start;
			pro *= start;
			sum %= 2;
			pro %= 2;
			start += 2;
		}
		assert(sum == 0 && pro == 1);
	} else if ( x == 1 && y == 1 ) {
		if ( !(n&1) ) { puts("No"); return 0; }
		puts("Yes");
		start = 1;
		for ( int i = 0 ; i < n ; ++i ) {
			printf ( "%d ", start );
			sum += start;
			pro *= start;
			sum %= 2;
			pro %= 2;
			start += 2;
		}
		assert(sum == 1 && pro == 1);
	} else {
		assert ( false );
	}

	return 0;
}

//int main ()
//{
//	vector<int> v;
//	v.clear();
//	set<vector<int>> svi;
//	int size = 12;
//	for ( int i = 1 ; i <= size ; ++i ) v.eb(i);
//	map<pair<int,int>,set<int>> mp;
//	for ( int mask = 0 ; mask < (1<<size) ; ++mask ) {
//		if ( __builtin_popcount(mask) == 0 ) continue;
//		int sum = 0; int pro = 1;
//		for ( int i = 0 ; i < size ; ++i )
//			if ( mask & (1<<i) )
//				sum += v[i], pro *= v[i], pro %= 2;
//		mp[{sum%2,pro%2}].insert(__builtin_popcount(mask));
//		vector<int> xv;
//		if ( sum%2==1 && pro%2==0 ) {
//			for ( int i = 0 ; i < size ; ++i )
//				if ( mask & (1<<i) )
//					xv.eb(v[i]);
//			sort(xv.begin(),xv.end());
//			svi.insert(xv);
//		}
//	}
//	for ( auto& i : mp )
//		debug() << imie(i);
//	debug() << imie(svi.size());
//	for ( auto& i : svi )
//		if ( i[0]==1 )
//		debug() << imie(i);
//
//
//	return 0;
//}
