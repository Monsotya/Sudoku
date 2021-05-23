#include "header.h"
void Sudoku::CreateMatrix() {
	srand(time(NULL));
	for (int i = 0; i < SIZEBIG; i++) {
		for (int j = 0; j < SIZEBIG; j++) {
			matrix[i][j] = (i * SIZESMALL + i / SIZESMALL + j) % SIZEBIG + 1;
		}
	}
	for (int i = 0; i < rand() % 25 + 25; i++) {
		SwapColumnAreas();
		SwapColumns();
	}	
	for (int i = 0; i < rand() % 2; i++) {
		Transpose();
	}
	for (int i = 0; i < rand() % 25 + 25; i++) {
		SwapRowAreas();
		SwapRows();
	}
	DeleteCells();
	for (int i = 0; i < SIZEBIG; i++) {
		for (int j = 0; j < SIZEBIG; j++) {
			answer[i][j] = matrix[i][j];
		}
	}
	/*for (int i = 0; i < SIZEBIG; i++) {
		for (int j = 0; j < SIZEBIG; j++) {
			if (matrix[i][j] == 0) cout << "     ";
			else cout << matrix[i][j] << "    ";
		}
		cout << "\n\n";
	}*/
}
void Sudoku::Transpose() {
	int temp, k = 0;
	for (int i = k; i < SIZEBIG; i++) {
		for (int j = k; j < SIZEBIG; j++) {
			temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
		k++;
	}
}
void Sudoku::SwapRows() {
	int temp = rand() % SIZESMALL, firstRow = rand() % SIZESMALL, secondRow = rand() % SIZESMALL;
	while (firstRow == secondRow) secondRow = rand() % SIZESMALL;
	firstRow = firstRow + temp * SIZESMALL;
	secondRow = secondRow + temp * SIZESMALL;
	for (int i = 0; i < SIZEBIG; i++) {
		temp = matrix[firstRow][i];
		matrix[firstRow][i] = matrix[secondRow][i];
		matrix[secondRow][i] = temp;
	}
}
void Sudoku::SwapRowAreas() {
	int temp, i, j, firstArea = rand() % SIZESMALL * SIZESMALL, secondArea = rand() % SIZESMALL * SIZESMALL;
	while (firstArea == secondArea) secondArea = rand() % SIZESMALL * SIZESMALL;
	for (i = 0; i < SIZEBIG; i++) {
		for (j = 0; j < SIZESMALL; j++) {
			temp = matrix[firstArea + j][i];
			matrix[firstArea + j][i] = matrix[secondArea + j][i];
			matrix[secondArea + j][i] = temp;
		}
	}
}
void Sudoku::SwapColumns() {
	Transpose();
	SwapRows();
	Transpose();
}
void Sudoku::SwapColumnAreas() {
	Transpose();
	SwapRowAreas();
	Transpose();
}
void Sudoku::DeleteCells() {
	int temp, numCol, numRow;
	Complexity();
	for (int i = 0; i < missingCells; i++) {
		temp = rand() % (SIZEBIG * SIZEBIG + 1);
		while (matrix[temp % SIZEBIG][temp / SIZEBIG] == 0) temp = rand() % (SIZEBIG * SIZEBIG + 1);
		numCol = numRow = 0;
		for (int j = 0; j < SIZEBIG; j++) {
			if (matrix[j][temp / SIZEBIG] != 0)	numRow++;
			if (matrix[temp % SIZEBIG][j] != 0)	numCol++;
		}
		if ((numCol > 1 && numRow > 1) || complexity > 0) {
			matrix[temp % SIZEBIG][temp / SIZEBIG] = 0;
			if (numCol == 1) complexity--;
			if (numRow == 1) complexity--;
		}
		else { i--; }
	}
}