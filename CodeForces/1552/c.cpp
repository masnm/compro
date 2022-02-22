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

vector<bool> v;
vector<pair<int,int>> vp;
int _l, _r;

void solve ()
{
	debug() << imie("SS");
	int n, k; scanf ( "%d%d", &n, &k );
	v.clear(); v.assign(n*2,false);
	vp.clear();
	for ( int i = 0 ; i < k ; ++i ) {
		scanf ( "%d%d", &_l, &_r );
		--_l; --_r;
		v[_l] = v[_r] = true;
		vp.eb ( _l, _r );
	}
	vector<int> av;
	for ( int i = 0 ; i < 2 * n ; ++i ) {
		if ( !v[i] ) av.eb ( i );
	}
	int sz = int(av.size()), dv = int(av.size())/2;
	for ( int i = 0 ; i < dv ; ++i )
		vp.eb ( av[i], av[i+dv] );
	auto cross = [](pair<int,int>& l, pair<int,int>& r) {
		int up = max ( l.F, l.S ), dwn = min ( l.F, l.S );
		if ( r.F < up && r.F > dwn && ( r.S > up || r.S < dwn ) ) return 1;
		if ( r.S < up && r.S > dwn && ( r.F > up || r.F < dwn ) ) return 1;
		return 0;
	};
	sz = vp.size();
	int cnt = 0;
	for ( int i = 0 ; i < sz ; ++i ) {
		for ( int j = 0 ; j < sz ; ++j ) {
			if ( i == j ) continue;
			cnt += cross ( vp[i], vp[j] );
		}
		debug() << imie(i) imie(vp[i]) imie(cnt);
	}
	printf ( "%d\n", cnt/2 );
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

