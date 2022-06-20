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

struct tpl {
	tpl () = default;
	tpl ( int _q, int _e, int _p ) :
		ques(_q), exam(_e), pre(_p) {}
	int ques = 0, exam = 0, pre = 0;
};

struct nt {
	nt () = default;
	nt ( int _e, int _p ) :
		exam(_e), pre(_p) {}
	int exam, pre;
};

int main ()
{
	int n, m; scanf ( "%d%d", &n, &m );
	vector<tpl> inp ( m );
	for_each ( inp.begin(), inp.end(), [](auto& i) {
			scanf ( "%d%d%d", &i.ques, &i.exam, &i.pre );
			});
	vector<int> ans;
	vector<nt> q;
	bool ok = true;
	for ( int current_time = 1 ; current_time <= n ; ++current_time ) {
		for ( int i = 0 ; i < int(inp.size()) ; ++i )
			if ( inp[i].ques >= current_time ) {
				q.eb ( inp[i].exam, inp[i].pre );
				inp.erase ( inp.begin() + i );
				--i;
			}
		if ( q.empty() ) {
			ans.eb ( 0 );
			continue;
		}
		for ( auto& i : q ) {
			if ( i.exam == current_time ) {
				ans.eb ( 1000 );
				q.erase ( find_if ( q.begin(), q.end(), [](auto& j) { return i.exam==j.exam&&i.pre==j.pre; }) );
				break;
			}
		}
		int curmin = INT_MAX;
	}

	return 0;
}

