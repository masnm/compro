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
	int n; scanf ( "%d", &n );
	vector<int> v(n);
	for ( auto& i : v ) scanf ( "%d", &i );
	unordered_map<int,int> ump; ump.reserve(1<<18);
	for ( auto& i : v ) ump[i]=0;
	int ac = 0, av = -1;
	for ( auto& i : v ) {
		auto src = ump.find(i-1);
		auto pr = ump.find(i);
		pr->S = max ( pr->S, 1);
		if ( src != ump.end() ) {
			pr->S = max ( pr->S, src->S+1 );
		}
		if ( pr->S > ac ) {
			ac = pr->S;
			av = i;
		}
	}
	int s = av - ac + 1, e = av, ind = 1;
	printf ( "%d\n", ac );
	for ( auto i : v ) {
		if ( s > e ) break;
		if ( i == s ) {
			printf ( "%d ", ind );
			s++;
		}
		ind ++;
	}
	debug() << imie(ac) imie(av);

	return 0;
}

