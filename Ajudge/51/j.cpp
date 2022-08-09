#include "bits/stdc++.h"
using namespace std;

#define F first
#define S second
#define eb emplace_back

string read_string ()
{
  static char ch[1000005];
  scanf ("%s", ch);
  return string (ch);
}

using ll = long long int;

static inline void solve ()
{
	ll n;
	scanf ("%lld", &n);
	n *= 567LL;
	n /= 9LL;
	n += 7492LL;
	n *= 235LL;
	n /= 47LL;
	n -= 498LL;
	n /= 10LL;
	printf ("%lld\n", abs (n % 10LL));
}

int main (int argc, char *argv[])
{
	int t = 1;
	scanf ("%d", &t);
	for (int i = 0; i < t; ++i) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}

	return 0;
}
