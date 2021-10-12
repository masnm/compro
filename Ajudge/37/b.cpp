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

void dig ( int n )
{
	switch ( n ) {
		case 0: printf("zero"); break;
		case 1: printf("one"); break;
		case 2: printf("two"); break;
		case 3: printf("three"); break;
		case 4: printf("four"); break;
		case 5: printf("five"); break;
		case 6: printf("six"); break;
		case 7: printf("seven"); break;
		case 8: printf("eight"); break;
		case 9: printf("nine"); break;
	}
}

void tdig ( int n )
{
	switch ( n ) {
		case 10: printf("ten"); break;
		case 11: printf("eleven"); break;
		case 12: printf("twelve"); break;
		case 13: printf("thirteen"); break;
		case 14: printf("fourteen"); break;
		case 15: printf("fifteen"); break;
		case 16: printf("sixteen"); break;
		case 17: printf("seventeen"); break;
		case 18: printf("eighteen"); break;
		case 19: printf("nineteen"); break;
	}
}

void solve ()
{
	int n;
	scanf ( "%d", &n );
	if ( n < 20 ) {
		if ( n < 10 ) dig ( n );
		else tdig ( n );
	} else {
		int bkp = n % 10;
		n /= 10;
		switch ( n ) {
			case 2: printf("twenty"); break;
			case 3: printf("thirty"); break;
			case 4: printf("forty"); break;
			case 5: printf("fifty"); break;
			case 6: printf("sixty"); break;
			case 7: printf("seventy"); break;
			case 8: printf("eighty"); break;
			case 9: printf("ninety"); break;
		}
		if ( bkp != 0 ) {
			printf ( "-" );
			dig(bkp);
		}
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

