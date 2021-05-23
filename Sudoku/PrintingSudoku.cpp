#include "header.h"
void Sudoku::PrintingSudoku() {
	cout << "  y";
	int row = 0;
	int col;
	for (int i = 0;i < SIZESMALL;i++) {
		for (int j = 0;j < SIZESMALL;j++) {
			cout.width(SIZEWID);
			cout << row++;
		}
		cout << "    ";
	}
	cout << '\n';
	row = 0;
	for (int i = 0;i < SIZESMALL;i++) {
		if (!i) {
			cout << "x ";
		}
		else {
			cout << "  ";
		}
		cout.width(LINE);
		cout.fill('-');
		cout << '-' << '\n';
		for (int j = 0;j < SIZESMALL;j++) {
			col = 0;
			cout << row << " ||";
			cout.fill(' ');
			for (int k = 0;k < SIZESMALL;k++) {
				cout.width(SIZEWID - 1);
				if (matrix[row][col] == 0) {
					cout << '-';
				}
				else {
					cout << matrix[row][col];
				}
				col++;
				for (int r = 0;r < SIZESMALL - 1;r++) {
					cout.width(SIZEWID);
					if (matrix[row][col] == 0) {
						cout << '-';
					}
					else {
						cout << matrix[row][col];
					}
					col++;
				}
				cout.width(SIZEWID);
				cout << '|';
			}
			row++;
			cout << "|\n";
		}
	}
	cout << "  ";
	cout.width(LINE);
	cout.fill('-');
	cout << '-' << '\n';
	cout.fill(' ');
}
