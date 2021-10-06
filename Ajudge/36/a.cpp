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
	static char ch[30];
	scanf ( "%s", ch );
	return string ( ch );
}

vector<vector<int>> vvi;
map<string,int> mp;

void low ( string& s )
{
	for ( char& c : s ) {
		if ( c >= 'A' && c <= 'Z' ) {
			c = c - 'A' + 'a';
		}
	}
}

void solve ()
{
	int n;
	scanf ( "%d", &n );
	mp.clear();
	vvi.resize(n+2);
	mp["polycarp"] = 0;
	int N = 0;
	for ( int i = 0 ; i < n ; ++i ) {
		string s = read_string ();
		string t = read_string ();
		t = read_string ();
		low ( s );
		low ( t );
		int sid, tid;
		auto search = mp.find ( s );
		if ( search == mp.end () ) {
			mp[s] = ++N;
			sid = N;
		} else {
			sid = search -> second;
		}
		search = mp.find ( t );
		if ( search == mp.end () ) {
			mp[t] = ++N;
			tid = N;
		} else {
			tid = search -> second;
		}
		debug() << imie(s) imie(t) imie(sid) imie(tid);
		vvi[tid].eb (sid);
	}
	debug() << imie(mp);
	debug() << imie(vvi);
	vector<int> ans ( n + 50, 0 );
	vector<bool> v ( n + 50, false );
	queue<int> q;
	q.push(0);
	while ( !q.empty() ) {
		int cp = q.front ();
		q.pop();
		for ( int i : vvi[cp] ) {
			if ( !v[i] ) {
				v[i] = true;
				ans[i] = ans[cp] + 1;
				q.push(i);
			}
		}
	}
	printf ( "%d\n", 1 + *max_element ( ans.begin(), ans.end() ) );
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

