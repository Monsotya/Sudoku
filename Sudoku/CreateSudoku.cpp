#include "CreateSudoku.h"
/*int Complexity() {
	
}*/
int** CreateMatrix() {
	int** table = new int* [9];
	srand(time(NULL));
	for (int i = 0; i < 9; i++) {
		table[i] = new int[9];
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			table[i][j] = (i * 3 + (i / 3) + j) % 9 + 1;
		}
	}
	for (int i = 0; i < rand() % 25 + 25; i++) {
		SwapColumnAreas(&table);
		SwapColumns(&table);
	}	
	for (int i = 0; i < rand() % 2; i++) {
		Transpose(&table);
	}
	for (int i = 0; i < rand() % 25 + 25; i++) {
		SwapRowAreas(&table);
		SwapRows(&table);
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << table[i][j] << "    ";
		}
		cout << "\n\n";
	}
	return table;
}
void Transpose(int** table[9]) {
	int temp, k = 0;
	for (int i = k; i < 9; i++) {
		for (int j = k; j < 9; j++) {
			temp = *(*(*table + i) + j);
			*(*(*table + i) + j) = *(*(*table + j) + i);
			*(*(*table + j) + i) = temp;
		}
		k++;
	}
}
void SwapRows(int** table[9]) {
	srand(time(NULL));
	int temp, firstRow = rand() % 9, secondRow = rand() % 9;
	while (firstRow == secondRow) secondRow = rand() % 9;
	for (int i = 0; i < 9; i++) {
		temp = *(*(*table + firstRow) + i);
		*(*(*table + firstRow) + i) = *(*(*table + secondRow) + i);
		*(*(*table + secondRow) + i) = temp;
	}
}
void SwapRowAreas(int** table[9]) {
	srand(time(NULL));
	int temp, i, j, k = 0, firstArea = rand() % 3 * 3, secondArea = rand() % 3 * 3;
	while (firstArea == secondArea) secondArea = rand() % 3 * 3;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 3; j++) {
			temp = *(*(*table + firstArea + j) + i);
			*(*(*table + firstArea + j) + i) = *(*(*table + secondArea + j) + i);
			*(*(*table + secondArea + j) + i) = temp;
		}
	}
}
void SwapColumns(int** table[9]) {
	Transpose(table);
	SwapRows(table);
	Transpose(table);
}
void SwapColumnAreas(int** table[9]) {
	Transpose(table);
	SwapRowAreas(table);
	Transpose(table);
}
void DeleteCells(int ind, int** table[9]) {

}
void Out(int** table[9]) {

}