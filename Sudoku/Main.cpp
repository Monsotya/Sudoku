#include "header.h"
int main()
{
	Sudoku matrix;
	char ans;
	do {
		matrix.CreateMatrix();
		if (matrix.Solve())
			matrix.Game();
		do {
			cout << "Do you want to play again?(y/n)\n";
			cin >> ans;
		} while (ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N');
	} while (ans == 'y' || ans == 'Y');
	return 0;
}
