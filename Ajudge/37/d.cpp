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
	static char ch[105];
	scanf ( "%s", ch );
	return string ( ch );
}

void solve ()
{
	int k;
	scanf ( "%d", &k );
	string s = read_string ();
	vector<int> v ( 30, 0 );
	for ( char c : s ) {
		int x = c - 'a';
		v[x] = 1;
	}
	int sum = accumulate ( v.begin(), v.end(), 0 );
	if ( sum < k ) {
		puts ( "NO" );
		return;
	} else {
		puts ( "YES" );
		v.assign ( 30, 0 );
		v[(int)*s.begin()-'a'] = 1;
		string t = "";
		vector<string> vs;
		for ( int i = (int)s.length() - 1 ; i > -1 ; --i ) {
			if ( k == 1 ) {
				// puts ( s.c_str() );
				vs.eb(s);
				break;
			}
			t += s[i];
			int x = s[i] - 'a';
			if ( v[x] == 0 ) {
				--k;
				v[x] = 1;
				reverse ( t.begin(), t.end() );
				// puts( t.c_str() );
				vs.eb(t);
				t = "";
			}
			s.pop_back();
		}
		reverse ( vs.begin(), vs.end() );
		for ( const string& ss : vs ) {
			puts ( ss.c_str() );
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

