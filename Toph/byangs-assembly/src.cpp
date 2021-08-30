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
// debug & operator << (debug & dd, P p) { dd << imie(p.x) imie(p.y); return dd; }

using ll = long long;
using ld = long double;

ll a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, p = 0;
bool end_file = true;

string read_string ()
{
	static char ch[15];
	if ( scanf ( "%s", ch ) == EOF ) end_file = false;
	return string(ch);
}

void read_ins ( vector<string>& vs )
{
	string r = read_string();
	vs.emplace_back ( r );
	if ( r == "HLT" ) return;
	if ( r=="LOD" || r=="ADD" || r=="MUL" || r=="CMP" ) {
		r = read_string();
		vs.emplace_back ( r );
		r = read_string();
		vs.emplace_back ( r );
	} else {
		r = read_string();
		vs.emplace_back ( r );
	}
	return;
}

void inc ( string& s )
{
	assert ( s.length() == 1 );
	if ( s[0] == 'A' ) ++a;
	else if ( s[0] == 'B' ) ++b;
	else if ( s[0] == 'C' ) ++c;
	else if ( s[0] == 'D' ) ++d;
	else if ( s[0] == 'E' ) ++e;
	else if ( s[0] == 'F' ) ++f;
	else if ( s[0] == 'P' ) ++p;
	else assert(false);
}

ll jmp ( string& s )
{
	ll x = stoi(s.c_str());
	return x-1;
}

ll vat ( string& s )
{
	if ( s[0] == 'A' ) return a;
	else if ( s[0] == 'B' ) return b;
	else if ( s[0] == 'C' ) return c;
	else if ( s[0] == 'D' ) return d;
	else if ( s[0] == 'E' ) return e;
	else if ( s[0] == 'F' ) return f;
	else if ( s[0] == 'P' ) return p;
	else assert(false);
}


void cmp ( string& s, string& t )
{
	c = vat(s) - vat(t);
	if ( c > 0 ) c = 1;
	if ( c < 0 ) c = -1;
}

void mul ( string& s, string& t )
{
	ll ml = vat(s) * vat(t);
	if ( s[0]=='A' ) a = ml;
	else if ( s[0]=='B' ) b = ml;
	else if ( s[0]=='C' ) c = ml;
	else if ( s[0]=='D' ) d = ml;
	else if ( s[0]=='E' ) e = ml;
	else if ( s[0]=='F' ) f = ml;
	else if ( s[0]=='P' ) p = ml;
	else assert(false);
}

void add ( string& s, string& t )
{
	ll ml = vat(s) + vat(t);
	if ( s[0]=='A' ) a = ml;
	else if ( s[0]=='B' ) b = ml;
	else if ( s[0]=='C' ) c = ml;
	else if ( s[0]=='D' ) d = ml;
	else if ( s[0]=='E' ) e = ml;
	else if ( s[0]=='F' ) f = ml;
	else if ( s[0]=='P' ) p = ml;
	else assert(false);
}

void lod ( string& s, string& t )
{
	ll ml = atoi(t.c_str());
	if ( s[0]=='A' ) a = ml;
	else if ( s[0]=='B' ) b = ml;
	else if ( s[0]=='C' ) c = ml;
	else if ( s[0]=='D' ) d = ml;
	else if ( s[0]=='E' ) e = ml;
	else if ( s[0]=='F' ) f = ml;
	else if ( s[0]=='P' ) p = ml;
	else assert(false);
}

int main ( int argc, char** argv )
{
	vector<vector<string>> vss;
	while ( end_file ) {
		vss.emplace_back ( vector<string>() );
		read_ins ( vss.back() );
	}

	ll sz = vss.size();
	while ( p < sz && vss[p][0] != "HLT" ) {
		if ( vss[p][0] == "INC" ) inc ( vss[p][1] );
		else if ( vss[p][0] == "JMP" ) p = jmp ( vss[p][1] );
		else if ( vss[p][0] == "JCZ" ) { if ( c == 0 ) p = jmp ( vss[p][1] ); }
		else if ( vss[p][0] == "JCP" ) { if ( c > 0 ) p = jmp ( vss[p][1] ); }
		else if ( vss[p][0] == "JCN" ) { if ( c < 0 ) p = jmp ( vss[p][1] ); }
		else if ( vss[p][0] == "CMP" ) cmp ( vss[p][1], vss[p][2] );
		else if ( vss[p][0] == "MUL" ) mul ( vss[p][1], vss[p][2] );
		else if ( vss[p][0] == "ADD" ) add ( vss[p][1], vss[p][2] );
		else if ( vss[p][0] == "LOD" ) lod ( vss[p][1], vss[p][2] );
		else assert(false);
		++p;
	}

	printf ( "%lld %lld %lld %lld %lld %lld %lld", a, b, c, d, e, f, p );

	debug() << imie ( vss );

	puts("");
	return 0;
}
