#include <iostream>
#define SIZE 3
using namespace std;
class Sudoku {
	int table[SIZE][SIZE];
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
	//int Check(int table[9][9]);
};
/*//int Complexity();
int** CreateMatrix();
void Transpose(int** table[9]);
void SwapRows(int** table[9]);
void SwapColumns(int** table[9]);
void SwapRowAreas(int** table[9]);
void SwapColumnAreas(int** table[9]);
void DeleteCells(int ind, int** table[9]);
void Out(int table[9][9]);
//int Check(int table[9][9]);*/
