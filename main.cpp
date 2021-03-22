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
	if ( a == 0 ) return 2;
	if ( a == 2 ) return 0;
	return 1;
}

int sor ( int a, int b ) { return max(a, b); }
int sand ( int a, int b ) { return min(a, b); }

struct stk {
	char a[81];
	int c = -1;
	char top() { return a[c]; }
	void push ( char ch ) { a[++c] = ch; }
	void pop () { --c; }
	bool empty () { return c==-1; }
	void clear () { c = -1; }
};

void do_task ()
{
	string s;
	while ( cin >> s && s != "." ) {
		ll ans = 0;
		stk st;
		for ( auto i : s ) {
			if ( i == '-' ) {
				st.push(i);
			} else if ( i == 'P' ) {
				int c = 0;
				if ( !st.empty() ) {
					while ( st.top() == '-' ) {
						neg(c);
						st.pop();
					}
				}
				if ( st.empty() ) {
					st.push('a'+c);
				} else if ( st.top() == '*' || st == '+' ) {
					int cal;
					char sign = st.top(); st.pop();
					int left = st.top()-'a'; st.pop();
					if ( sign == '+' ) {
						cal = sor ( left, c );
					} else {
						cal = sand ( left, c );
					}
					stk.push((char)cal+'a');
				} else if ( st.top() == '(' ) {
					st.push('a'+c);
				}
			} else if ( i == 'Q' ) {
				int c = 0;
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
					stk.push((char)cal+'a');
				} else if ( st.top() == '(' ) {
					st.push('a'+c);
				}
			} else if ( i == 'R' ) {
				int c = 0;
				if ( !st.empty() ) {
					while ( st.top() == '-' ) {
						neg(c);
						st.pop();
					}
				}
				if ( st.empty() ) {
					st.push('a'+c);
				} else if ( st.top() == '*' || st == '+' ) {
					int cal;
					char sign = st.top(); st.pop();
					int left = st.top()-'a'; st.pop();
					if ( sign == '+' ) {
						cal = sor ( left, c );
					} else {
						cal = sand ( left, c );
					}
					stk.push((char)cal+'a');
				} else if ( st.top() == '(' ) {
					st.push('a'+c);
				}
			} else if ( i == ')' ) {
				char ch = st.top();
				st.pop();
				st.push(ch);
			} else if ( i == '(' || i == '*' || i == '+' ) {
				st.push(i);
			} else if ( i == '0' || i == '1' || i == '2' ) {
				int c = i-'0';
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
			}
		}
		if ( st.top() == '2' ) ++ans;
		for ( auto i : s ) {
			if ( i == '-' ) {
				st.push(i);
			} else if ( i == 'P' ) {
				int c = 0;
				if ( !st.empty() ) {
					while ( st.top() == '-' ) {
						neg(c);
						st.pop();
					}
				}
				if ( st.empty() ) {
					st.push('a'+c);
				} else if ( st.top() == '*' || st == '+' ) {
					int cal;
					char sign = st.top(); st.pop();
					int left = st.top()-'a'; st.pop();
					if ( sign == '+' ) {
						cal = sor ( left, c );
					} else {
						cal = sand ( left, c );
					}
					stk.push((char)cal+'a');
				} else if ( st.top() == '(' ) {
					st.push('a'+c);
				}
			} else if ( i == 'Q' ) {
				int c = 0;
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
					stk.push((char)cal+'a');
				} else if ( st.top() == '(' ) {
					st.push('a'+c);
				}
			} else if ( i == 'R' ) {
				int c = 1;
				if ( !st.empty() ) {
					while ( st.top() == '-' ) {
						neg(c);
						st.pop();
					}
				}
				if ( st.empty() ) {
					st.push('a'+c);
				} else if ( st.top() == '*' || st == '+' ) {
					int cal;
					char sign = st.top(); st.pop();
					int left = st.top()-'a'; st.pop();
					if ( sign == '+' ) {
						cal = sor ( left, c );
					} else {
						cal = sand ( left, c );
					}
					stk.push((char)cal+'a');
				} else if ( st.top() == '(' ) {
					st.push('a'+c);
				}
			} else if ( i == ')' ) {
				char ch = st.top();
				st.pop();
				st.push(ch);
			} else if ( i == '(' || i == '*' || i == '+' ) {
				st.push(i);
			} else if ( i == '0' || i == '1' || i == '2' ) {
				int c = i-'0';
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
			}
		}
		if ( st.top() == '2' ) ++ans;
		for ( auto i : s ) {
			if ( i == '-' ) {
				st.push(i);
			} else if ( i == 'P' ) {
				int c = 0;
				if ( !st.empty() ) {
					while ( st.top() == '-' ) {
						neg(c);
						st.pop();
					}
				}
				if ( st.empty() ) {
					st.push('a'+c);
				} else if ( st.top() == '*' || st == '+' ) {
					int cal;
					char sign = st.top(); st.pop();
					int left = st.top()-'a'; st.pop();
					if ( sign == '+' ) {
						cal = sor ( left, c );
					} else {
						cal = sand ( left, c );
					}
					stk.push((char)cal+'a');
				} else if ( st.top() == '(' ) {
					st.push('a'+c);
				}
			} else if ( i == 'Q' ) {
				int c = 0;
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
					stk.push((char)cal+'a');
				} else if ( st.top() == '(' ) {
					st.push('a'+c);
				}
			} else if ( i == 'R' ) {
				int c = 2;
				if ( !st.empty() ) {
					while ( st.top() == '-' ) {
						neg(c);
						st.pop();
					}
				}
				if ( st.empty() ) {
					st.push('a'+c);
				} else if ( st.top() == '*' || st == '+' ) {
					int cal;
					char sign = st.top(); st.pop();
					int left = st.top()-'a'; st.pop();
					if ( sign == '+' ) {
						cal = sor ( left, c );
					} else {
						cal = sand ( left, c );
					}
					stk.push((char)cal+'a');
				} else if ( st.top() == '(' ) {
					st.push('a'+c);
				}
			} else if ( i == ')' ) {
				char ch = st.top();
				st.pop();
				st.push(ch);
			} else if ( i == '(' || i == '*' || i == '+' ) {
				st.push(i);
			} else if ( i == '0' || i == '1' || i == '2' ) {
				int c = i-'0';
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
			}
		}
		if ( st.top() == '2' ) ++ans;
		for ( auto i : s ) {
			if ( i == '-' ) {
				st.push(i);
			} else if ( i == 'P' ) {
				int c = 0;
				if ( !st.empty() ) {
					while ( st.top() == '-' ) {
						neg(c);
						st.pop();
					}
				}
				if ( st.empty() ) {
					st.push('a'+c);
				} else if ( st.top() == '*' || st == '+' ) {
					int cal;
					char sign = st.top(); st.pop();
					int left = st.top()-'a'; st.pop();
					if ( sign == '+' ) {
						cal = sor ( left, c );
					} else {
						cal = sand ( left, c );
					}
					stk.push((char)cal+'a');
				} else if ( st.top() == '(' ) {
					st.push('a'+c);
				}
			} else if ( i == 'Q' ) {
				int c = 0;
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
					stk.push((char)cal+'a');
				} else if ( st.top() == '(' ) {
					st.push('a'+c);
				}
			} else if ( i == 'R' ) {
				int c = 0;
				if ( !st.empty() ) {
					while ( st.top() == '-' ) {
						neg(c);
						st.pop();
					}
				}
				if ( st.empty() ) {
					st.push('a'+c);
				} else if ( st.top() == '*' || st == '+' ) {
					int cal;
					char sign = st.top(); st.pop();
					int left = st.top()-'a'; st.pop();
					if ( sign == '+' ) {
						cal = sor ( left, c );
					} else {
						cal = sand ( left, c );
					}
					stk.push((char)cal+'a');
				} else if ( st.top() == '(' ) {
					st.push('a'+c);
				}
			} else if ( i == ')' ) {
				char ch = st.top();
				st.pop();
				st.push(ch);
			} else if ( i == '(' || i == '*' || i == '+' ) {
				st.push(i);
			} else if ( i == '0' || i == '1' || i == '2' ) {
				int c = i-'0';
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
			}
		}
		if ( st.top() == '2' ) ++ans;
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
