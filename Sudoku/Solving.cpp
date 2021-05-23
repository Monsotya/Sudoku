#include "header.h"

int Sudoku::Check(int element, int row, int col) {
	//int rowcol;
	for (int rowcol = 0;rowcol < SIZEBIG;rowcol++) {
		/*if(answer[a][i] != element && answer[i][b] != element);
		else
			return 0;*/
		if (answer[row][rowcol] == element || answer[rowcol][col] == element)
			return 0;
	}
	// int i,j;
	int rowUpLim, rowDownLim;
	if (row < SIZESMALL) {
		rowUpLim = 0;
		rowDownLim = SIZESMALL;
	}
	else if (row < 2 * SIZESMALL) {
		rowUpLim = SIZESMALL;
		rowDownLim = 2 * SIZESMALL;
	}
	else {
		rowUpLim = 2 * SIZESMALL;
		rowDownLim = SIZEBIG;
	}
	int colLeftLim, colRightLim;
	//int r,k;
	if (col < SIZESMALL) {
		colLeftLim = 0;
		colRightLim = SIZESMALL;
	}
	else if (col < 2 * SIZESMALL) {
		colLeftLim = SIZESMALL;
		colRightLim = 2 * SIZESMALL;
	}
	else {
		colLeftLim = 2 * SIZESMALL;
		colRightLim = SIZEBIG;
	}
	/*for(int s=i;s<j;s++){
		for(int h=r;h<k;h++){
			if(answer[s][h] != element);
			else
				return 0;
		}
	}*/
	for (int i = rowUpLim;i < rowDownLim;i++) {
		for (int j = colLeftLim;j < colRightLim;j++) {
			if (answer[i][j] == element)
				return 0;
		}
	}
	return 1;
}

int Sudoku::StepCheck(int row, int col) {
	if (row >= SIZEBIG - 1 && col >= SIZEBIG)
		return 1;
	if (col >= SIZEBIG) {
		col = 0;
		row++;
	}
	if (answer[row][col] != 0)
		return StepCheck(row, col + 1);

	for (int num = 1;num <= SIZEBIG;num++) {
		if (Check(num, row, col)) {
			answer[row][col] = num;
			if (StepCheck(row, col + 1)) {
				return 1;
			}
			else {
				answer[row][col] = 0;
			}
		}
	}
	return 0;
}

bool Sudoku::Solve() {
	if (!StepCheck(0, 0)) {
		cout << "Error.Solving failed!\n";
		return false;
	}
	return true;
}
