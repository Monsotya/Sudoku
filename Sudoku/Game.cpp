#include "header.h"
void Sudoku::Game() {
	char numCol, numRow, num;
	while (missingCells > 0 && lives > 0) {
		Out();
		cout << "Enter number of column, row and what number you want to write\n";
		cin >> numCol >> numRow >> num;
		if (isalpha(numCol) || isalpha(numRow) || isalpha(num)) {
			cout << "You should enter numbers, not string!\n";
			continue;
		}
		else if (numCol > SizeBig || numRow > SizeBig || num > SizeBig) {
			cout << "This is too big!\n You should enter numbers smaller than " << SizeBig;
			continue;
		}
		else if (numCol < 0 || numRow < 0 || num < 0) {
			cout << "This is too small!\n You should enter numbers bigger than 0";
			continue;
		}
		if (matrix[numRow - 1][numCol - 1] != 0) {
			cout << "Wrong! The cell is already filled!";
		}
		else if (matrix[numRow - 1][numCol - 1] != answer[numRow - 1][numCol - 1]) {
			lives--;
			cout << "Wrong number! Lives left: " << lives;
		}
		else {
			missingCells--;
		}
	}
	if (missingCells == 0) {
		cout << "Congratulations! You won!\n";
	}
	else {
		cout << "You lox!\n";
	}
}