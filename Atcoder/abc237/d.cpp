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
string read_string ()
{
	static char ch[500005];
	scanf ( "%s", ch );
	return string ( ch );
}

struct node {
	int val;
	node* prev;
	node* next;
};
debug & operator << (debug & dd, node p) { dd << "(" << p.val << ", " << p.prev << ", " << p.next << ")"; return dd; }

node* get_new ( int data )
{
	node* n = new node;
	n->val = data;
	n->next = NULL;
	n->prev = NULL;
	return n;
}

void solve ()
{
	int n; scanf ( "%d", &n );
	string s = read_string();
	node* start = get_new ( 0 );
	for ( int i = 1 ; i <= n ; ++i ) {
		node* nt = get_new ( i );
		if ( s[i-1] == 'R' ) {
			if ( start->next != NULL ) {
				node* nnx = start->next;
				start->next = nt;
				start->next->next = nnx;
				start->next->next->prev = start->next;
				start->next->prev = start;
				start = start->next;
			} else {
				start->next = nt;
				start->next->prev = start;
				start = start->next;
			}
		} else if ( s[i-1] == 'L' ) {
			if ( start->prev != NULL ) {
				node* nnx = start->prev;
				start->prev = nt;
				start->prev->prev = nnx;
				start->prev->prev->next = start->prev;
				start->prev->next = start;
				start = start->prev;
			} else {
				start->prev = nt;
				start->prev->next = start;
				start = start->prev;
			}
		} else {
			assert ( false );
		}
	}
	while ( start->prev != NULL ) {
		start = start->prev;
	}
	while ( start != NULL ) {
		printf ( "%d ", start->val );
		node* ntd = start;
		start = start->next;
		delete ntd;
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

