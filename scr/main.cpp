#include <stdio.h>

const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

int staticQuery(int L, int R) {
 L += n; R += n;
 int sum = 0;
 for (; L <= R; L = (L + 1) >> 1, R = (R - 1) >> 1) {
  if (L & 1) { sum += t[L]; }
  if (!(R & 1)) { sum += t[R]; }
 }
 return sum;
}

int main() {
	const int x = 3e5 + 5;
	printf ( "%d\n", x );
	return 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
  build();
  //modify(0, 1);
  int l = 2 + n;
  printf(" 1 -> 2 = %d\n", query(1,2));
  printf(" 2 -> 3 = %d\n", query(2,3));
  printf(" 3 -> 4 = %d\n", query(3,4));
  printf(" 1 -> 4 = %d\n", query(1,4));
  printf(" 2 -> 4 = %d\n", query(2,4));
  printf("%d\n", staticQuery(1, 8));
  return 0;
}
