#include "bits/stdc++.h"
using namespace std;

struct matrix {
	vector<vector<float>> vvf;
	matrix ( int row, int col ) {
		vvf.resize ( row );
		for ( auto& i : vvf )
			i.resize ( col );
	}
	void print ()
	{
		cout << "[" << endl;
		for ( auto& i : vvf ) {
			cout << "  [ ";
			for ( auto j : i ) {
				cout << j << " ";
			}
			cout << "]" << endl;
		}
		cout << "]" << endl;
	}
	~matrix ()
	{
		for ( auto i : vvf ) i.clear();
		vvf.clear();
	}
	matrix operator* ( const matrix& a, const matrix& b )
	{
		matrix m ( 1, 4 );
		for ( size_t i = 0 ; i < 1 ; ++i ) {
			for ( size_t j = 0 ; j < 4 ; ++j ) {
				for ( size_t k = 0 ; k < 4 ; ++k ) {
					m.vvf[i][j] += a[i][j] * b[j][k];
				}
			}
		}
		return m;
	}
};

int main ( void )
{
	float fov = 3.14159*2.0f;
	matrix proj ( 4, 4 );
	proj[0] = { 1.78*(1/tanf(fov/2)), 0, 0, 0 }
	proj[1] = { 0, 1/tanf(fov/2), 0, 0 }
	proj[2] = { 0, 0, zfar/(zfar-znear), 1 }
	proj[3] = { 0, 0, (-zfar*znear)/(zfar-znear), 0 }

	matrix in ( 1, 4 );
	in.vvf[0] = { 1, 1, 1, 1 }

	matrix ans = in * proj;

	return 0;
}

