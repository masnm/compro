#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long double ld;
typedef long long int ll;
typedef unsigned long long ull;

template<typename T> void chmax ( T& a, T b ) { if ( a < b ) a = b; }
template<typename T> void chmin ( T& a, T b ) { if ( a > b ) a = b; }

void prepare_lookup_table ()
{
}

string gstr ( ld a, ll flen = 6 )
{
	string str = to_string(a);
	int len = str.length(), ind = 0;
	while ( ind < len && str[ind] != '.' ) {
		++ind;
	}
	bool b = false;
	for ( ll i = ind+1 ; i < len ; ++i ) {
		if ( str[i] != '0' ) {
			b = true;
			break;
		}
	}
	if ( b ) {
		if ( str[ind+2] > '4' ) {
			if ( str[ind+1] < '9' ) ++str[ind+1];
		}
		str = str.substr(0,ind+2);
		reverse(str.begin(),str.end());
		ll l = str.length();
		for ( int i = l ; i < flen ; ++i ) {
			str += " ";
		}
		reverse(str.begin(),str.end());
	} else {
		str = str.substr(0,ind);
		reverse(str.begin(),str.end());
		ll l = str.length();
		for ( int i = l ; i < flen ; ++i ) {
			str += " ";
		}
		reverse(str.begin(),str.end());
	}
	return str;
}

string nm ( string str, ll flen = 6 )
{
	ll l = str.length();
	reverse ( str.begin(), str.end() );
	for ( ll i = l ; i < flen ; ++i ) str += " ";
	reverse ( str.begin(), str.end() );
	return str;
}

void pi ( vector<pair<ld,pair<ld,ld>>>& vp, bool b = false ) {
	if ( b ) cout << "The initial table is " << endl;
	cout << nm ( "Pi" );
	for ( auto& i : vp ) {
		cout << gstr ( i.second.first ) << " ";
	}
	cout << endl;
	cout << nm ( "Wi" );
	for ( auto& i : vp ) {
		cout << gstr ( i.second.second ) << " ";
	}
	cout << endl;
}

void ui ( vector<pair<ld,pair<ld,ld>>>& vp, bool b = false ) {
	if ( b ) {
		cout << "Calculate all the  Ui using formula." << endl;
		cout << "        Pi" << endl;
		cout << " Ui = ------" << endl;
		cout << "        Wi"  << endl;
	
		cout << "The table after Calculation all the Ui" << endl;
	}
	pi(vp);
	cout << nm ( "Ui" );
	for ( auto& i : vp ) {
		cout << gstr ( i.first ) << " ";
	}
	cout << endl;
}

void si ( vector<pair<ld,pair<ld,ld>>>& vp, bool b = false )
{
	if ( b ) {
		cout << "Now lets sort the table in decreasing order," << endl;
		cout << "By comparing Ui." << endl;
		cout << "The table after sorting is." << endl;
	}
	ui ( vp );
}

void xi ( vector<pair<ld,pair<ld,ld>>>& vp, vector<ld>& x, bool b = false )
{
	if ( b ) {
		cout << "Table after calculation all the Xi is" << endl;
	}
	si(vp);
	cout << nm ( "Xi" );
	for ( auto& i : x ) {
		cout << gstr ( i ) << " ";
	}
	cout << endl;
}

vector<ld> calculate_x ( vector<pair<ld,pair<ld,ld>>>& vp, ll n, ld bag )
{
	cout << "The total capacity of our bag is " << gstr(bag) << endl;
	vector<ld> x(n,0);
	ll xind = 0;
	for ( auto& i : vp ) {
		ld bb = bag, mns;
		cout << "for i=" << xind << "," << endl;
		if ( i.second.second < bag ) {
			x[xind] = 1;
			bag -= i.second.second;
			mns = i.second.second;
			cout << "As " << nm("W"+to_string(xind), 0) << " = ";
			cout << i.second.second << " Which is < " << gstr(bb,0) << endl;
			cout << "So, " << nm("X"+to_string(xind), 0) << " = 1 , and " << endl;
			cout << "Rest capacity U = " << bb << " - " << mns << " = " << gstr(bag,0) << endl;
		} else if ( bag <= i.second.second ) {
			x[xind] = bag / i.second.second;
			bag = 0;
			cout << "As " << nm("W"+to_string(xind), 0) << " = ";
			cout << i.second.second << " Which is ≮ " << gstr(bb,0) << endl;
			cout << "So, " << nm("X"+to_string(xind), 0) << " = ( " ;
			cout << gstr(bb,0) << " / " << gstr(i.second.second,0) << " ) = " << gstr(x[xind],0) << " , and" << endl;
			cout << "Rest capacity U = " << bb << " -" << " ( " << gstr(i.second.second, 0) << " * ( ";
			cout << gstr(bb,0) << " / " << gstr(i.second.second,0) << " ) ) = " << gstr(bag,0) << endl;
			cout << endl;
			break;
		}
		cout << endl;
		++xind;
	}
	return x;
}

void do_task ()
{
	ll n; ld w; cin >> n >> w;
	vector<pair<ld,pair<ld,ld>>> vp(n);
	for ( auto& i : vp ) cin >> i.second.first;
	for ( auto& i : vp ) cin >> i.second.second;
	pi(vp, true); cout << endl;

	for ( auto& i : vp ) i.first = i.second.first/i.second.second;
	ui(vp, true); cout << endl;

	sort ( vp.begin(), vp.end() ); reverse(vp.begin(), vp.end());
	si(vp, true); cout << endl;

	vector<ld> x = calculate_x ( vp, n, w );
	xi(vp,x, true); cout << endl;

	ld ans = 0;
	for ( ll i = 0 ; i < n ; ++i ) {
		ans += vp[i].second.first * x[i];
	}
	cout << "The maximum profit is " << gstr(ans,0) << endl;
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	prepare_lookup_table();

	int t = 1;
	for ( int i = 1 ; i <= t ; ++i ) {
		//cout << "Case " << i << ": " ;
		do_task();
	}


	return 0;
}
// resize-pane -L 30 
