#include "header.h"
void Sudoku::Game() {
	int numCol, numRow, num, lives;
	char buffNumCol, buffNumRow, buffNum;
	lives = LIVES;
	while (missingCells > 0 && lives > 0) {
		Out();
		cout << "Enter number of column, row and what number you want to write\n";
		cin >> buffNumCol >> buffNumRow >> buffNum;
		if (isalpha(buffNumCol) || isalpha(buffNumRow) || isalpha(buffNum)) {
			cout << "You should enter numbers, not string!\n";
			continue;
		}
		numCol = buffNumCol - '0';
		numRow = buffNumRow - '0';
		num = buffNum - '0';
		if (numCol > SizeBig || numRow > SizeBig || num > SizeBig) {
			cout << "This is too big!\n You should enter numbers smaller than " << SizeBig << endl;
			continue;
		}
		else if (numCol < 0 || numRow < 0 || num < 0) {
			cout << "This is too small!\n You should enter numbers bigger than 0\n";
			continue;
		}
		if (matrix[numRow][numCol] != 0) {
			cout << "Wrong! The cell is already filled!\n";
		}
		else if (num != answer[numRow][numCol]) {
			lives--;
			cout << "Wrong number! Lives left: " << lives << endl;
		}
		else {
			matrix[numRow][numCol] = num;
			missingCells--;
		}
	}
	if (missingCells == 0) {
		cout << "Congratulations! You won!\n";
	}
	else {
		cout << "You lox!\n";
		//ShowSolution(); Знизу код
		for(int i=0;i<SizeBig;i++){
			for(int j=0;j<SizeBig;j++){
				matrix[i][j]=answer[i][j];
			}
		}
		cout << "Solution :\n";
		Out();
	}
}
