#include "bits/stdc++.h"
using namespace std;

class cla {
	public:
		cla ( int _a, int _b ) :
			a(_a), b(_b) { }
		int a;
		int b;
};

class clb: public cla {
	public:
		clb ( int _a, int _b, int _c ) :
			cla ( _a, _b ), c(_c) { }
		int c;
};

int main ()
{
	cla c(1,2);
	cout << c.a << " " << c.b << endl;
	clb a(4,5,6);
	cout << a.a << " " << a.b << " " << a.c << endl;


	return 0;
}

