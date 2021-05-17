#include "header.h"
void Sudoku::CreateMatrix() {
	srand(time(NULL));
	for (int i = 0; i < SizeBig; i++) {
		for (int j = 0; j < SizeBig; j++) {
			matrix[i][j] = (i * SizeSmall + i / SizeSmall + j) % SizeBig + 1;
		}
	}
	Out();
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
	Out();
	DeleteCells();
	/*for (int i = 0; i < SizeBig; i++) {
		for (int j = 0; j < SizeBig; j++) {
			if (matrix[i][j] == 0) cout << "     ";
			else cout << matrix[i][j] << "    ";
		}
		cout << "\n\n";
	}*/
}
void Sudoku::Transpose() {
	int temp, k = 0;
	for (int i = k; i < SizeBig; i++) {
		for (int j = k; j < SizeBig; j++) {
			temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
		k++;
	}
}
void Sudoku::SwapRows() {
	int temp = rand() % SizeSmall, firstRow = rand() % SizeSmall, secondRow = rand() % SizeSmall;
	while (firstRow == secondRow) secondRow = rand() % SizeSmall;
	firstRow = firstRow + temp * SizeSmall;
	secondRow = secondRow + temp * SizeSmall;
	for (int i = 0; i < SizeBig; i++) {
		temp = matrix[firstRow][i];
		matrix[firstRow][i] = matrix[secondRow][i];
		matrix[secondRow][i] = temp;
	}
}
void Sudoku::SwapRowAreas() {
	int temp, i, j, k = 0, firstArea = rand() % SizeSmall, secondArea = rand() % SizeSmall;
	while (firstArea == secondArea) secondArea = rand() % SizeSmall;
	for (i = 0; i < SizeBig; i++) {
		for (j = 0; j < SizeSmall; j++) {
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
		temp = rand() % (SizeBig * SizeBig + 1);
		while (matrix[temp % SizeBig][temp / SizeBig] == 0) temp = rand() % (SizeBig * SizeBig + 1);
		numCol = numRow = 0;
		for (int j = 0; j < SizeBig; j++) {
			if (matrix[j][temp / SizeBig] != 0)	numRow++;
			if (matrix[temp % SizeBig][j] != 0)	numCol++;
		}
		if (numCol > 1 && numRow > 1 || complexity > 0) {
			matrix[temp % SizeBig][temp / SizeBig] = 0;
			if (numCol == 1) complexity--;
			if (numRow == 1) complexity--;
		}
		else { i--; }
	}
}