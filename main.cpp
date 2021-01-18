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

ll find_y ( ld x )
{
	ld expo = 2.718281828;
	#warning Put your function on the next line
	// Your equation goes here.. 
	// the equation is used  "(X^3+X^2+X+7)"
	ld ans = x*pow(expo,x) - 1;
	if ( ans < 0.0 ) return -1;
	if ( ans > 0.0 ) return 1;
	return 0;
}

ll find_y ( ld x , ld &a )
{
	ld expo = 2.718281828;
	#warning Put your function on the next line
	// Your equation goes here.. 
	// the equation is used  "(X^3+X^2+X+7)"
	ld ans = x*pow(expo,x) - 1;
	a = ans;
	if ( ans < 0.0 ) return -1;
	if ( ans > 0.0 ) return 1;
	return 0;
}

ld absf ( ld a ) { return a < 0.0 ? -a : a; }

bool need_to_iterate ( ld a, ld b, ld c )
{
	a = absf ( a );
	b = absf ( b );
	ld x = a > b ? a-b : b-a;
	return c <= x;
}

ld calculate_mid ( ld a, ld b ) {
	ld ans = a + b;
	return ans /= 2;
}

bool found_values ( ld &m, ld &p, ld d, ld s )
{
	m = s;
	p = m + d;
	if ( find_y(m) == -1 && find_y(p) == 1 ) {
		return true;
	}
	if ( find_y(m) == 1 && find_y(p) == -1 ) {
		swap ( m, p );
		return true;
	}
	return false;
}

void find_values_for_pm ( ld& plus, ld& minus )
{
	plus = 0.0; minus = 0.0;
	ld des = 0.1, start = -100;
	while ( plus == 0.0 && minus == 0.0 && des <= 10.0 ) {
		start = -100;
		while ( start < 101 ) {
			start += des;
			if ( found_values ( minus, plus, des, start ) ) {
				ld out;
				find_y ( minus, out );
				cout << "Negative : " << minus << " " << out << "\n";
				find_y ( plus, out );
				cout << "Positive : " << plus << " " << out << "\n";
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

		ld ans;
		ll y = find_y ( mid, ans );

		cout << iteration++ << "\t" <<
			value_for_minus << "\t" <<
			value_for_plus << "\t" <<
			mid << "\t" <<
			ans << endl;

		switch ( y ) {
			case -1 :
				value_for_minus = mid;
				break;
			case 1 :
				value_for_plus = mid;
				break;
			case 0 :
			default:
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
