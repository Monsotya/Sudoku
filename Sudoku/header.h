#include <iostream>
#define SIZE 3
using namespace std;
class Sudoku {
	int matrix[9][9];
	int complexity;
	int missingCells;
public:
	void Complexity();
	void CreateMatrix();
	void Transpose();
	void SwapRows();
	void SwapColumns();
	void SwapRowAreas();
	void SwapColumnAreas();
	void DeleteCells();
	void Out();
	//int Check(int matrix[9][9]);
};
/*//int Complexity();
int** CreateMatrix();
void Transpose(int** matrix[9]);
void SwapRows(int** matrix[9]);
void SwapColumns(int** matrix[9]);
void SwapRowAreas(int** matrix[9]);
void SwapColumnAreas(int** matrix[9]);
void DeleteCells(int ind, int** matrix[9]);
void Out(int matrix[9][9]);
//int Check(int matrix[9][9]);*/
