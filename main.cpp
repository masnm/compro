#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

#define sl(a) scanf("%lld",&a)
#define pl(a) printf("%lld ",a)
#define nln printf("\n")

const long long INF = 1e18;
const long long mod = 1000000007;

//#warning need array limit
//ll A[long(1e7+5)];
//ll B[long(1e7+5)];

void prepare_lookup_table ()
{
}

ld find_y ( ld x )
{
	ld expo = 2.718281828;
	#warning Put your function on the next line
	// Your equation goes here.. 
	// the equation is used  "(X^3+X^2+X+7)"
	ld ans = ( x * x * x ) - ( x * x ) - 1;
	return ans;
}

ld absf ( ld a ) { return a < 0.0 ? -a : a; }

bool need_to_iterate ( ld a, ld b, ld c )
{
	a = absf ( a );
	b = absf ( b );
	ld x = a > b ? a-b : b-a;
	return c <= x;
}

ld calculate_mid ( ld x2, ld x1 )
{
	ld mid = ( ( x1 * find_y(x2) ) - ( x2 * find_y(x1) ) ) / ( find_y(x2) - find_y(x1) );
	return mid;
}

bool found_values ( ld &m, ld &p, ld d, ld s )
{
	m = s;
	p = m + d;
	if ( find_y(m) < 0.0 && find_y(p) > 0.0 ) {
		return true;
	}
	if ( find_y(m) > 0.0 && find_y(p) < 0.0 ) {
		swap ( m, p );
		return true;
	}
	return false;
}

void find_values_for_pm ( ld& plus, ld& minus )
{
	plus = 0.0; minus = 0.0;
	ld des = 1.0, start = -100;
	while ( plus == 0.0 && minus == 0.0 && des <= 10.0 ) {
		start = -100;
		while ( start < 101 ) {
			start += des;
			if ( found_values ( minus, plus, des, start ) ) {
				cout << "Negative : " << minus << " " << find_y(minus) << "\n";
				cout << "Positive : " << plus << " " << find_y(plus) << "\n";
				break;
			}
			minus = plus = 0.0;
		}
		des += 0.1;
	}
}

void do_task ()
{
	ld value_for_plus, value_for_minus;

	#warning Initialize the next two variables
	// initialuze the next two variables with the their name suggested.
//	value_for_plus = 1.0;
//	value_for_minus = 0.0;
	find_values_for_pm ( value_for_plus, value_for_minus );
	if ( value_for_plus == 0.0 && value_for_minus == 0.0 ) {	
		cout << "Failed to find the values\n"
			"please enter the values you would like to use\n";
		cout << "Minus : "; cin >> value_for_minus;
		cout << "Plus : "; cin >> value_for_plus;
	}
//	value_for_plus = 1.0;
//	value_for_minus = 0.5;
	// replace the 'X' from the next line with the limit of accuracy

	#warning Put the precission limit
	// don't delete the char 'e'. 'e' is nacessary
	ld precission = (1.0/2.0) * (1.0/(1e4));

	cout << "Itera." << "\t" <<
		"Minus value." << "\t" <<
		"Plus value." << "\t" <<
		"Mid" << "\t" <<
		"f(x)" << endl;

	ll iteration = 1;
	while ( true ) {
		if ( !need_to_iterate ( value_for_plus, value_for_minus, precission ) ) {
			break;
		}

		ld mid = calculate_mid ( value_for_plus, value_for_minus );

		ld y = find_y ( mid );

		cout << iteration++ << "\t" <<
			value_for_minus << "\t" <<
			value_for_plus << "\t" <<
			mid << "\t" <<
			y << endl;

		if ( y < 0.0 ) {
			value_for_minus = mid;
		} else if ( y > 0.0 ) {
			value_for_plus = mid;
		} else {
			value_for_plus = value_for_minus = mid;
		}

		// if you don't want to press enter for every iteration
		// just delete the next line 
		cin.get();
	}
}

int main ()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);

	prepare_lookup_table();

	ll t = 1;
//	sl(t);
	while ( t-- ) {
		do_task();
	}


	return 0;
}
