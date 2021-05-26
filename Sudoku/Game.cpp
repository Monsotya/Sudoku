#include "header.h"
void Sudoku::Welcome(){
	cout << "\n\n\t******************************\n";
	cout << "\t*                            *\n";
	cout << "\t*          Welcome!          *\n";
	cout << "\t*    To the puzzle Game of   *\n";
	cout << "\t*          -SUDOKU-          *\n";
	cout << "\t*                            *\n";
	cout << "\t******************************\n\n\n";
	cout << "\t  <= Press Enter to Start =>\n";
	cin.unsetf(ios::skipws);
	char ch;
	cin >> ch;
	cin.clear();
	cin.ignore(32727,'\n');
	cin.setf(ios::skipws);
	//fseek(stdin, 0, SEEK_END);
}

void Sudoku::Game() {
	int numCol, numRow, num, lives = LIVES, stepsUser = 0;
	char* buffNumCol = new char, *buffNumRow = new char, *buffNum = new char;	
	time_t start = time(NULL);
	while (missingCells > 0 && lives > 0) {
		PrintingSudoku();
		cout << "Enter number of column you want to write in\n";
		cin >> buffNumCol;
		fseek(stdin, 0, SEEK_END);
		if (*buffNumCol == 'q')
			break;
		if (CheckAnswer(buffNumCol))
			continue;
		cout << "Enter number of row you want to write in\n";
		cin >> buffNumRow;
		fseek(stdin, 0, SEEK_END);
		if (*buffNumCol == 'q')
			break;
		if (CheckAnswer(buffNumRow))
			continue;
		cout << "Enter number you want to write\n";
		cin >> buffNum;
		fseek(stdin, 0, SEEK_END);
		if (*buffNumCol == 'q')
			break;
		if (CheckAnswer(buffNum))
			continue;
		numCol = atoi(buffNumCol);
		numRow = atoi(buffNumRow);
		num = atoi(buffNum);
		if (num < 1) {
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
		stepsUser++;
	}
	time_t end = time(NULL);
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
	cout << "Number of Computer Steps : " << stepsProgramm << endl;
	cout << "Number of User Steps : " << stepsUser << endl;
	cout << "Time you spended playing this game : " << (end - start) / SECONDS << " min " << (end - start) % SECONDS << " sec\n";

}
bool Sudoku::CheckAnswer(char* str) {
	int ind = 1, count = 0, buff;
	while (ind && str[count] != '\0') {
		if (str[count] < '0' || str[count] > '9')
			ind = 0;
		count++;
	}
	if (!ind) {
		cout << "You should enter numbers, not string!\n";
		return true;
	}
	buff = atoi(str);
	if (buff > SIZEBIG) {
		cout << "This is too big!\nYou should enter numbers smaller than " << SIZEBIG + 1<< endl;
		return true;
	}
	return false;
}
