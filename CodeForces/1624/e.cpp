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
	static char ch[1005];
	scanf ( "%s", ch );
	return string ( ch );
}

int t = 1;

struct st {
	st () : l(0), r(0), ind(0) { }
	st ( int _l, int _r, int _ind ) :
		l(_l), r(_r), ind(_ind) { }
	int l, r, ind;
};
debug & operator << (debug & dd, st p) { dd << "(" << p.l << ", " << p.r << ", " << p.ind << ")"; return dd; }

struct tpl {
	tpl () : a(0), b(0), c(0) {}
	tpl ( char _a, char _b, char _c ) :
		a(_a), b(_b), c(_c) {}
	char a, b, c;
	bool operator< (const tpl& r) const {
		if ( a != r.a ) return a<r.a;
		else if ( b != r.b ) return b<r.b;
		else if ( c != r.c ) return c<r.c;
		else return false;
	}
	bool operator== ( const tpl& r) const {
		return (a==r.a && b==r.b && c==r.c);
	}
};
debug & operator << (debug & dd, tpl p) { dd << "(" << p.a << ", " << p.b << ", " << p.c << ")"; return dd; }

void solve ( int me )
{
	map<pair<char,char>,st> mp;
	map<tpl,st> mpt;
	int n, m;
	scanf ( "%d%d", &n, &m );
	string s;
	for ( int i = 0 ; i < n ; ++i ) {
		s = read_string ();
		for ( int j = 0 ; j < m - 1 ; ++j )
			mp[{s[j],s[j+1]}] = {j+1,j+2, i+1};
		for ( int j = 0 ; j < m - 2 ; ++j )
			mpt[{s[j],s[j+1],s[j+2]}] = { j+1, j+3, i+1 };
	}
	s = read_string ();
	vector<st> ans;
	if ( m & 1 && m > 2 ) {
		bool dn = false;
		int tind = -1;
		for ( int i = 0 ; i < m - 3 ; i += 2 ) {
			auto src = mpt.find ( tpl(s[i],s[i+1],s[i+2]) );
			if ( src != mpt.end() ) {
				ans.eb(src->S);
				dn = true;
				s.erase ( i, 3 );
				tind = i;
				break;
			}
		}
		if ( !dn ) {
			auto src = mpt.find ( tpl(s[m-3],s[m-2],s[m-1]) );
			if ( src != mpt.end() ) {
				dn = true;
				ans.eb ( src->S );
				tind = m - 3 - 1;
				s.erase ( m - 3, 3 );
			} else {
				puts ( "-1" );
				return;
			}
		}
		for ( int i = 0 ; i < m - 3 ; i += 2 ) {
			auto src = mp.find ( make_pair( s[i], s[i+1] ) );
			if ( src != mp.end() )
				ans.eb ( src->S );
			else {
				puts ( "-1" );
				return;
			}
		}
		if ( tind == m - 3 - 1 ) {
			st l = *ans.begin();
			ans.erase ( ans.begin() );
			ans.eb(l);
		} else {
			for ( int i = 0 ; i < tind ; ++i )
				swap ( ans[i], ans[i+1] );
		}
		printf ( "%d\n", int(ans.size()) );
		for ( st& i : ans )
			printf ( "%d %d %d\n", i.l, i.r, i.ind );
	} else if ( m > 1 ) {
		for ( int i = 0 ; i < m ; i += 2 ) {
			auto src = mp.find ( make_pair( s[i], s[i+1] ) );
			if ( src != mp.end() )
				ans.eb ( src->S );
			else {
				puts ( "-1" );
				return;
			}
		}
		printf ( "%d\n", int(ans.size()) );
		for ( st& i : ans )
			printf ( "%d %d %d\n", i.l, i.r, i.ind );
	} else {
		puts ( "-1" );
		return;
	}
}

int main ()
{
	scanf ( "%d" , &t );
	for ( int i = 0 ; i < t ; ++i ) {
//		printf ( "Case %d: ", i+1 );
		solve ( i + 1 );
	}


	return 0;
}

