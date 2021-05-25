#include "header.h"
int main()
{
	Sudoku matrix;
	char answer;
	welcome();
	//system("chcp 1251 & cls");
	do {
		matrix.CreateMatrix();
		if (matrix.Solve()) {
			cout << "\nSudoku constructed correctly!\nEnjoy solving sudoku, you have " << LIVES << " lives!\nIf you want to end game enter q\n";
			matrix.Game();
		}
		do {
			cout << "Do you want to play again?(y/n)\n";
			cin >> answer;
			fseek(stdin, 0, SEEK_END);
		} while (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N');
	} while (answer == 'y' || answer == 'Y');
	return 0;
}
