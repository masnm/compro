#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	char cc = 36;
	long double d = 0, t;
	for ( int i = 0 ; i < 12 ; ++i ) {
		scanf("%LF",&t);
		d += t;
	}
	t = d/12.0;
	long long lo = (long long)(t*1000);
	lo %= 10;
	if ( 
	cout << (char)cc << fixed << std::setprecision(2) << d/12.0f << endl;
	return true;
}
