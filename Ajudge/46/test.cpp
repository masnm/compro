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

void solve ()
{
}

int main ()
{
	vector<int> v;
	for ( int i = 3 ; i < 100000 ; i += 3 ) v.eb ( i );
	cout << v.size() << endl;
	for ( int i = 0 ; i < int(v.size()) ; ++i ) {
		bool erased = false;
		for ( int j = i + 1 ; j < int(v.size()) ; ++j ) {
			int l = v[i], r = v[j];
			bool ok = true;
			while ( l > 0 ) {
				int ld = l%10, rd = r%10;
				l /= 10; r /= 10;
				if ( ld != rd ) {
					ok = false;
					break;
				}
			}
			if ( ok ) { erased = true; v.erase ( v.begin()+j ); --j; }
		}
		if ( erased ) --i;
	}
	cout << v.size() << endl;
	cout << v.back() << endl;
	return 0;
}

