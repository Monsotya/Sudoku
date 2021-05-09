#include "header.h"
void Sudoku::CreateMatrix() {
	/*int** matrix = new int* [9];
	
	/*for (int i = 0; i < 9; i++) {
		matrix[i] = new int[9];
	}*/
	srand(time(NULL));
	for (int i = 0; i < SIZE*SIZE; i++) {
		for (int j = 0; j < SIZE * SIZE; j++) {
			matrix[i][j] = (i * SIZE + (i / SIZE) + j) % (SIZE * SIZE) + 1;
		}
	}
	for (int i = 0; i < rand() % 25 + 15; i++) {
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
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (matrix[i][j] == 0) cout << "     ";
			else cout << matrix[i][j] << "    ";
		}
		cout << "\n\n";
	}
}
void Sudoku::Transpose() {
	int temp, k = 0;
	for (int i = k; i < SIZE * SIZE; i++) {
		for (int j = k; j < SIZE * SIZE; j++) {
			temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
		k++;
	}
}
void Sudoku::SwapRows() {
	//srand(time(NULL));
	int temp, firstRow = rand() % SIZE * SIZE, secondRow = rand() % (SIZE * SIZE);
	while (firstRow == secondRow) secondRow = rand() % (SIZE * SIZE);
	for (int i = 0; i < SIZE * SIZE; i++) {
		temp = matrix[firstRow][i];
		matrix[firstRow][i] = matrix[secondRow][i];
		matrix[secondRow][i] = temp;
	}
}
void Sudoku::SwapRowAreas() {
	//srand(time(NULL));
	int temp, i, j, k = 0, firstArea = rand() % SIZE, secondArea = rand() % SIZE;
	while (firstArea == secondArea) secondArea = rand() % SIZE * SIZE;
	for (i = 0; i < SIZE * SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
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
	//srand(time(NULL));
	for (int i = 0; i < rand() % 10 + 50; i++) {
		temp = rand() % 81;
		while (matrix[temp % (SIZE * SIZE)][temp / (SIZE * SIZE)] == 0) temp = rand() % 81;
		numCol = numRow = 0;
		for (int j = 0; j < SIZE * SIZE; j++) {
			if (matrix[j][temp / (SIZE * SIZE)] != 0)	numRow++;
			if (matrix[temp % (SIZE * SIZE)][j] != 0)	numCol++;
		}
		/*for (int j = 0; j < SIZE * SIZE; j++) {
			if (matrix[temp % (SIZE * SIZE)][j] != 0)
				numCol++;
		}*/
		if (numCol > 1 && numRow > 1 || complexity > 0) {
			matrix[temp % (SIZE * SIZE)][temp / (SIZE * SIZE)] = 0;
			if (numCol == 1) complexity--;
			if (numRow == 1) complexity--;
		}
		else {
			//i--;
		}
	}
}