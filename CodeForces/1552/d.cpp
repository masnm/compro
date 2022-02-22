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

int n;
bool ans;
vector<int> v, in;
set<int> mn;

bool ok ()
{
	vector<vector<int>> vvi ( 3, vector<int>(0) );
	for ( int i = 0 ; i < n ; ++i )
		vvi[v[i]].eb(in[i]);
	//for ( vector<int>& i : vvi )
	//	sort ( i.begin(), i.end() );
	set<int> s;
	for ( int x = 0 ; x < 2 ; ++x ) {
	// for ( vector<int>& i : vvi ) {
		vector<int>& i = vvi[x];
		if ( int ( i.size() ) < 2 ) {
			s.insert(0);
			for ( int j : i )
				s.insert(j);
		}
		else {
			s.insert(0);
			s.insert(i[0]);
			for ( int j = 1 ; j < int(i.size()) ; ++j )
				s.insert(i[j]+i[j-1]);
		}
	}
	for ( int i = 0 ; i < int(vvi[2].size()) ; ++i ) {
		for ( int j = 0 ; j < int(vvi[2].size()) ; ++j ) {
			if ( i == j ) continue;
			if ( s.count(vvi[2][i] + vvi[2][j]) != 0 ) ans = true;
		}
	}
	//if ( mn.size() > s.size() )
	//	mn = s;
	// ans = (int(s.size()) <= n);
	if ( ans ) debug() << imie(s);
	return ans;
}

bool recar ( int ind )
{
	if ( ind == n ) {
		ok ();
		return ans;
	}
	for ( int i = 0 ; i < 3 ; ++i ) {
		v[ind] = i;
		recar ( ind + 1 );
		if ( ans ) return ans;
	}
	return ans;
}

void solve ()
{
	vector<int> _v ( 15 );
	iota ( _v.begin(), _v.end(), 0 );
	mn = set<int>(_v.begin(), _v.end());
	scanf ( "%d", &n );
	in.assign ( n, 0 );
	for ( int i = 0 ; i < n ; ++i )
		scanf ( "%d", &in[i] );
	v.clear();
	v.assign ( n, 0 );
	ans = false;
	recar ( 0 );
	puts ( ans ? "Yes" : "No" );
}

int main ()
{
	int t = 1;
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ();
	}


	return 0;
}

