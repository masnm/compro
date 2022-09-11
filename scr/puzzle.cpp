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

bool can_make ( vector<int> v, int num )
{
	for ( int i = 0 ; i < v.size() ; ++i ) {
		int ls = 0, rs = 0;
		for ( int j = 0 ; j < i ; ++j ) ls += v[j];
		for ( int j = i ; j < v.size() ; ++j ) rs += v[j];
		if ( ls == num || rs == num ) return true;
		if ( abs ( max ( ls, rs ) - min ( ls, rs ) ) == num )
			return true;
		for ( auto i : v ) {
			if ( ls + i == num ) return true;
			if ( rs + i == num ) return true;
			if ( ls - i == num ) return true;
			if ( rs - i == num ) return true;
		}
	}
	return false;
}

bool ok ( vector<int> v )
{
	vector<int> vcp = v;
	bool full_ok = true;
	for ( int num = 1 ; num <= 40 ; ++num ) {
		v = vcp;
		bool ok = false;
		for ( int itr = 0 ; itr < 500 ; ++itr ) {
			if ( can_make ( v, num ) ) ok = true;
			next_permutation ( v.begin(), v.end() );
		}
		if ( !ok ) full_ok = false;
	}
	return full_ok;
}

int main ( int argc, char* argv[] )
{
	for ( int a = 1 ; a < 40 ; ++a ) {
		for ( int b = 0 ; b < 40 ; ++b ) {
			for ( int c = 0 ; c < 40 ; ++c ) {
				if ( a + b + c >= 40 ) continue;
				vector<int> v = { a, b, c, 40 - a - b - c, 40 };
				if ( ok ( v ) ) {
					cerr << "T : " << a << " " << b << " " << c << endl;
				}
			}
		}
	}

	return 0;
}

