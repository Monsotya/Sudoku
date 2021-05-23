#include "header.h"
void Sudoku::Game() {
	int numCol, numRow, num, lives, ind = 1, count = 0;
	char* buffNumCol = new char, *buffNumRow = new char, *buffNum = new char;
	lives = LIVES;
	while (missingCells > 0 && lives > 0) {
		ind = 1;
		count = 0;
		PrintingSudoku();
		cout << "Enter number of column you want to write in\n";
		cin >> buffNumCol;
		fseek(stdin, 0, SEEK_END);
		while (ind && buffNumCol[count] != '\0') {
			if (buffNumCol[count] < '0' || buffNumCol[count] > '9')
				ind = 0;
			count++;
		}
		if (!ind) {
			cout << "You should enter numbers, not string!\n";
			continue;
		}
		cout << "Enter number of row you want to write in\n";
		cin >> buffNumRow;
		fseek(stdin, 0, SEEK_END);
		count = 0;
		while (ind && buffNumRow[count] != '\0'){
			if (buffNumRow[count] < '0' || buffNumRow[count] > '9')
				ind = 0;
			count++;
		}
		if (!ind) {
			cout << "You should enter numbers, not string!\n";
			continue;
		}
		cout << "Enter number you want to write\n";
		cin >> buffNum;
		fseek(stdin, 0, SEEK_END);
		count = 0;
		while (ind && buffNum[count] != '\0') {
			if (buffNum[count] < '0' || buffNum[count] > '9')
				ind = 0;
			count++;
		}
		if (!ind) {
			cout << "You should enter numbers, not string!\n";
			continue;
		}
		/*cin.putback(buffNumCol);
		cin.putback(' ');
		cin.putback(buffNumRow);
		cin.putback(' ');
		cin.putback(buffNum);
		cin >> numCol >> numRow >> num;*/
		numCol = atoi(buffNumCol);
		numRow = atoi(buffNumRow);
		num = atoi(buffNum);
		if (numCol > SIZEBIG || numRow > SIZEBIG || num > SIZEBIG) {
			cout << "This is too big!\nYou should enter numbers smaller than " << SIZEBIG << endl;
			continue;
		}
		else if (numCol < 0 || numRow < 0 || num < 0) {
			cout << "This is too small!\nYou should enter numbers bigger than 0\n";
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
		cout << "Sorry, you lost.\n";
		for (int i = 0;i < SIZEBIG;i++) {
			for (int j = 0;j < SIZEBIG;j++) {
				matrix[i][j] = answer[i][j];
			}
		}
		cout << "Solution :\n";
		PrintingSudoku();
	}
}
