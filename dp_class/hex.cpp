#include "bits/stdc++.h"
using namespace std;

using ll = long long int;

const int nax = 10005;

ll memo[nax];

int a, b, c, d, e, f;
ll fn(int n) {
	if ( memo[n] != -1 ) return memo[n];
    if (n == 0) return a;
    if (n == 1) return b;
    if (n == 2) return c;
    if (n == 3) return d;
    if (n == 4) return e;
    if (n == 5) return f;
    memo[n] = fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6);
	memo[n] %= 10000007;
	return memo[n];
}
int main() {
    int n, cases;
    scanf("%d", &cases);
    for (int caseno = 1; caseno <= cases; ++caseno) {
		for ( int i = 0 ; i < nax ; ++i ) memo[i] = -1;
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %d\n", caseno, fn(n) % 10000007);
    }
    return 0;
}
