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

ll find_y ( ld x , ld &a )
{
	ld expo = 2.718281828;
	#warning Put your function on the next line
	// Your equation goes here.. 
	// the equation is used  "(X^3+X^2+X+7)"
	ld ans = (x*x*x) + (x*x) + x + 7;
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

void do_task ()
{
	ld value_for_plus, value_for_minus;

	#warning Initialize the next two variables
	// initialuze the next two variables with the their name suggested.
	value_for_plus = -2.00;
	value_for_minus = -3.00;
	// replace the 'X' from the next line with the limit of accuracy

	#warning Put the precission limit
	// don't delete the char 'e'. 'e' is nacessary
	ld precission = (1.0/2.0) * (1.0/(1e3));

	cout << "Itera." << "\t" <<
		"Plus value." << "\t" <<
		"Minus value." << "\t" <<
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
			value_for_plus << "\t" <<
			value_for_minus << "\t" <<
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
