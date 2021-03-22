#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long
#define ld long double

#define chmax(a,b) if ( a < b ) a = b
#define chmin(a,b) if ( a > b ) a = b

void prepare_lookup_table ()
{
}

void neg ( int& a )
{
	if ( a == 0 ) a = 2;
	if ( a == 2 ) a = 0;
}

int sor ( int a, int b ) { return max(a, b); }
int sand ( int a, int b ) { return min(a, b); }

struct stk {
	char a[81];
	int c = -1;
	char top() { return a[c]; }
	void push ( char ch ) { a[++c] = ch; }
	void pop () { a[c]=0;--c; }
	bool empty () { return c==-1; }
	void clear () { c = -1; }
} st ;

ll ans, len, cntt;
string s;

void solve ( int i )
{
	if ( i >= len ) {
		++cntt;
		//cout << int(st.top()-'a') ;
		if ( st.top() == 'a'+2 ) ++ans;
		return;
	}
	if ( s[i] == '-' ) {
		st.push(s[i]);
		solve ( i+1 );
	} else if ( s[i] == 'P' ) {
		for ( int pp = 0 ; pp < 3 ; ++pp ) {
		char bkp[81] = { };
		for ( int ii = 0 ; ii < 81 ; ++ii ) bkp[ii] = st.a[ii];
		int cbkp = st.c;
		int c = pp;
		if ( !st.empty() ) {
			while ( st.top() == '-' ) {
				neg(c);
				st.pop();
			}
		}
		if ( st.empty() ) {
			st.push('a'+c);
		} else if ( st.top() == '*' || st.top() == '+' ) {
			int cal;
			char sign = st.top(); st.pop();
			int left = st.top()-'a'; st.pop();
			if ( sign == '+' ) {
				cal = sor ( left, c );
			} else {
				cal = sand ( left, c );
			}
			st.push('a'+cal);
		} else if ( st.top() == '(' ) {
			st.push('a'+c);
		}
		solve ( i+1 );
		st.c = cbkp;
		for ( int ii = 0 ; ii < 81 ; ++ii ) st.a[ii] = bkp[ii];
		}
	} else if ( s[i] == 'Q' ) {
		for ( int qq = 0 ; qq < 3 ; ++qq ) {
		char bkp[81] = { };
		for ( int ii = 0 ; ii < 81 ; ++ii ) bkp[ii] = st.a[ii];
		int cbkp = st.c;
		int c = qq;
		if ( !st.empty() ) {
			while ( st.top() == '-' ) {
				neg(c);
				st.pop();
			}
		}
		if ( st.empty() ) {
			st.push('a'+c);
		} else if ( st.top() == '*' || st.top() == '+' ) {
			int cal;
			char sign = st.top(); st.pop();
			int left = st.top()-'a'; st.pop();
			if ( sign == '+' ) {
				cal = sor ( left, c );
			} else {
				cal = sand ( left, c );
			}
			st.push('a'+cal);
		} else if ( st.top() == '(' ) {
			st.push('a'+c);
		}
		solve ( i+1 );
		st.c = cbkp;
		for ( int ii = 0 ; ii < 81 ; ++ii ) st.a[ii] = bkp[ii];
		}
	} else if ( s[i] == 'R' ) {
		for ( int rr = 0 ; rr < 3 ; ++rr ) {
		char bkp[81] = { };
		for ( int ii = 0 ; ii < 81 ; ++ii ) bkp[ii] = st.a[ii];
		int cbkp = st.c;
		int c = rr;
		if ( !st.empty() ) {
			while ( st.top() == '-' ) {
				neg(c);
				st.pop();
			}
		}
		if ( st.empty() ) {
			st.push('a'+c);
		} else if ( st.top() == '*' || st.top() == '+' ) {
			int cal;
			char sign = st.top(); st.pop();
			int left = st.top()-'a'; st.pop();
			if ( sign == '+' ) {
				cal = sor ( left, c );
			} else {
				cal = sand ( left, c );
			}
			st.push('a'+cal);
		} else if ( st.top() == '(' ) {
			st.push('a'+c);
		}
		solve ( i+1 );
		st.c = cbkp;
		for ( int ii = 0 ; ii < 81 ; ++ii ) st.a[ii] = bkp[ii];
		}
	} else if ( s[i] == ')' ) {
		char ch = st.top();
		st.pop(); st.pop();
		st.push(ch);
		solve ( i+1 );
	} else if ( s[i] == '(' || s[i] == '*' || s[i] == '+' ) {
		st.push(s[i]);
		solve ( i+1 );
	} else if ( s[i] == '0' || s[i] == '1' || s[i] == '2' ) {
		int c = s[i]-'0';
		if ( !st.empty() ) {
			while ( st.top() == '-' ) {
				neg ( c );
				st.pop();
			}
		}
		if ( st.empty() ) {
			st.push('a' + c);
		} else if ( st.top() == '(' ) {
			st.push('a'+c);
		} else if ( st.top() == '*' || st.top() == '+' ) {
			int cal;
			char ch = st.top(); st.pop();
			int left = st.top()-'a'; st.pop();
			if ( ch == '+' ) {
				cal = sor ( left, c );
			} else {
				cal = sand ( left, c );
			}
			st.push('a'+cal);
		}
		solve ( i+1 );
	}
}

void do_task ()
{
	while ( cin >> s && s != "." ) {
		st.clear();
		len = s.length();
		cntt = 0;
		ans = 0;
		solve ( 0 );
		cout << ans << " " << cntt << endl;
	}
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	prepare_lookup_table();

	ll t = 1;
	while ( t-- ) {
		do_task();
	}


	return 0;
}
