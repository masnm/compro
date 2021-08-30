#include "bits/stdc++.h"
using namespace std;

using ll = long long int;

bool inln ( pair<int,int> l, pair<int,int> m, pair<int,int> r )
{
	if ( l > m ) swap ( l, m );
	if ( m > r ) swap ( m, r );
	if ( l > m ) swap ( l, m );
	if ( m > r ) swap ( m , r );
	if ( ( r.second-m.second == r.first-m.first ) && ( m.second-l.second == m.first-l.first ) ) {
//	if ( (r.second-m.second == m.second-l.second) && (r.first-m.first == m.first-l.first) ) {
		return true;
	} else {
		return false;
	}
}

void solve ()
{
	int a, b, c, d, e, f, g, h;
	scanf ( "%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h );
	if ( (a==c&&b!=d) || (b==h&&a!=g) || (d==f&&c!=e) || (e==g&&f!=h) ) {
		vector<pair<int,int>> vp;
		vp.emplace_back(a,b);
		vp.emplace_back(c,d);
		vp.emplace_back(e,f);
		vp.emplace_back(g,h);
		bool ans = true;
		int len = 4;
		for ( int rep = 0 ; rep < 41 ; ++rep ) {
			for ( int i = 0 ; i < len ; ++i ) {
				pair<int,int> l;
				if ( i == 0 ) l = vp[len-1];
				else l = vp[i-1];
				pair<int,int> r;
				if ( i == len-1 ) r = vp[0];
				else r = vp[i+1];
				if ( inln ( l, vp[i], r ) ) {
					ans = false;
				}
			}
			random_shuffle ( vp.begin(), vp.end() );
			if ( !ans ) break;
		}
		if ( ans ) {
			puts ( "yes" );
		} else {
			puts ( "no" );
		}
	} else {
		puts ( "no" );
	}
}

int main ()
{
	int t;
	scanf ( "%d", &t );
	while ( t-- ) solve();


	return 0;
}

