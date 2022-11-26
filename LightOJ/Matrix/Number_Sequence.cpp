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

int mod;
struct Matrix {

	int row = 0, col = 0;
	vector<vector<ll>> data;

	Matrix () = default;
	Matrix ( int _r, int _c ) {
		row = _r;
		col = _c;
		data.resize ( row );
		for ( int i = 0 ; i < row ; ++i )
			data[i].resize ( col );
		for ( auto& i : data )
			for ( auto& j : i )
				j = 0;
	}

	Matrix operator * ( const Matrix& that )
	{
		Matrix out ( this->row, that.col );
		for ( int i = 0 ; i < this->row ; ++i )
			for ( int j = 0 ; j < that.col ; ++j )
				for ( int k = 0 ; k < this->col ; ++k ) {
					out.data[i][j] += this->data[i][k] * that.data[k][j];
					out.data[i][j] %= 1000000LL;
				}
		return out;
	}

	Matrix operator % ( int md )
	{
		Matrix out ( this->row, this->col );
		for ( int i = 0 ; i < out.row ; ++i )
			for ( int j = 0 ; j < out.col ; ++j ) {
				out.data[i][j] = this->data[i][j] % md;
			}
		return out;
	}
};

int a, b, m;
ll n;
Matrix take[35];

inline void pre ()
{
	Matrix base ( 2, 2);
	base.data[0][0] = 1; base.data[0][1] = 1;
	base.data[1][0] = 1; base.data[1][1] = 0;
	take[0] = base;
	for ( int i = 1 ; i < 35 ; ++i )
		take[i] = take[i-1] * take[i-1];
}

inline void solve ( int _case )
{
	(void) _case;
	scanf ( "%d%d%lld%d", &a, &b, &n, &m );
	if ( n == 0 ) { printf ( "%d\n", a ); return; }
	if ( n == 1 ) { printf ( "%d\n", b ); return; }
	Matrix here( 2, 2);
	here.data[0][0] = 1; here.data[0][1] = 0;
	here.data[1][0] = 0; here.data[1][1] = 1;
	for ( ll p = 33 ; p > -1 ; --p ) {
		if ( n >= (1LL<<p) ) {
			n -= (1LL<<p);
			here = here * take[p];
		}
	}
	Matrix start ( 2, 1 );
	start.data[0][0] = b;
	start.data[1][0] = a;
	here = here * start;
	mod = 10;
	for ( int i = 1 ; i < m ; ++i ) mod *= 10;
	printf ( "%lld\n", here.data[1][0] % mod );
}

int main ( void )
{
	pre ();
	int _t = 1;
	scanf ( "%d" , &_t );
	for ( int i = 0 ; i < _t ; ++i ) {
		printf ( "Case %d: ", i+1 );
		solve ( i+1 );
	}


	return 0;
}

