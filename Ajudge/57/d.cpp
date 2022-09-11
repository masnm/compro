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

string read_string ()
{
	static char ch[1000005];
	scanf ( "%s", ch );
	return string ( ch );
}

using ll = long long int;

const int nax = 10005;
int n;
vector<int> v;
vector<vector<int>> vc;
vector<bool> ph;
vector<int> primes;
map<pair<int,int>,int> mp;

int get_ncr ( int _n, int r )
{
	if ( _n == r ) return 1;
	if ( r == 1 ) return _n;
	auto src = mp.find(make_pair(_n,r));
	if ( src != mp.end() )
		return src->S;
	int ans = get_ncr ( _n-1, r-1 ) + get_ncr ( _n-1, r );
	mp[make_pair(_n,r)] = ans;
	return ans;
}

void pre ()
{
	ph.resize ( nax );
	fill ( ph.begin(), ph.end(), true );
	primes.clear();
	ph[2] = true;
	for ( int i = 2 ; i < nax ; ++i ) {
		if ( ph[i] ) {
			for ( int j = i ; j < nax ; j += i )
				ph[j] = false;
			primes.eb ( i );
		}
	}
}

void solve ()
{
	scanf ( "%d", &n );
	v.resize ( n ); vc.resize(n);
	for ( auto& i : vc ) i.clear();
	for ( auto& i : v ) scanf ( "%d", &i );
	for ( auto i : primes ) {
		for ( int j = 0 ; j < n ; ++j ) {
			if ( v[j] < 2 ) continue;
			if ( v[j] % i == 0 ) {
				vc[j].eb ( i );
				while ( v[j] % i == 0 ) v[j] /= i;
			}
		}
	}
	int ans = 0;
	for ( int i = 0 ; i < n ; ++i ) {
		int cnt = 0;
		for ( int j = 0 ; j < n ; ++j ) {
			if ( j == i ) continue;
			bool ok = true;
			for ( auto& k : vc[i] ) {
				auto src = lower_bound ( vc[j].begin(), vc[j].end(), k );
				if ( src != vc[j].end() && *src == k ) {
					ok = false;
					break;
				}
			}
			if ( ok ) ++cnt;
		}
		if ( cnt >= 3 ) ans += get_ncr ( cnt, 3 );
	}
	printf ( "%d\n", ans );
}

int main ( int argc, char* argv[] )
{
	pre ();
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

