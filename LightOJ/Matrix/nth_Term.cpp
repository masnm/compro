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

string read_string ( void )
{
	static char ch[1000005];
	scanf ( "%s", ch );
	return string ( ch );
}

using ll = long long int;

const ll mod = 10007;

struct Matrix {
	Matrix () = default;
	Matrix ( size_t _r, size_t _c ) {
		row = _r; col = _c;
		data.resize ( row );
		for ( auto& i : data )
			i.resize ( col );
		for ( auto& i : data )
			for ( auto& j : i )
				j = 0;
	}
	Matrix ( vector<vector<ll>> _d ) {
		data = _d;
		row = data.size();
		col = data[0].size();
	}
	size_t row = 0, col = 0;
	vector<vector<ll>> data;
	Matrix operator* ( Matrix& that ) {
		Matrix out ( this->row, that.col );
		for ( size_t i = 0 ; i < this->row ; ++i )
			for ( size_t j = 0 ; j < that.col ; ++j )
				for ( size_t k = 0 ; k < this->col ; ++k ) {
					out.data[i][j] += this->data[i][k] * that.data[k][j];
					out.data[i][j] %= mod;
				}
		return out;
	}
};

ll n, a, b, c;

Matrix get_there ( Matrix& base, ll por )
{
	if ( por == 1 ) return base;
	ll mid = por / 2;
	Matrix ans = get_there ( base, mid );
	ans = ans * ans;
	if ( por & 1LL ) ans = ans * base;
	return ans;
}

inline void solve ( int _case )
{
	(void) _case;
	scanf ( "%lld%lld%lld%lld", &n, &a, &b, &c );
	if ( n <= 2 ) { puts ( "0" ); return; }
	Matrix base ( { { a, 0, b, c },
					{ 1, 0, 0, 0 },
					{ 0, 1, 0, 0 },
					{ 0, 0, 0, 1 } } );
	Matrix there = get_there ( base, n - 2 );
	Matrix st ( { { 0 }, { 0 }, { 0 }, { 1 } } );
	there = there * st;
	printf ( "%lld\n", there.data[0][0] );
}

int main ( void )
{
	int _t = 1;
	scanf ( "%d" , &_t );
	for ( int i = 0 ; i < _t ; ++i ) {
		printf ( "Case %d: ", i+1 );
		solve ( i+1 );
	}


	return 0;
}

