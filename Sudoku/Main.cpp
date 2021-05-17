#include "header.h"
int main()
{
	Sudoku matrix;
	matrix.CreateMatrix();
	/*matrix.Solve();
	matrix.Game();*/
	if(matrix.Solve())
		matrix.Game();
	return 0;
}
