#include <iostream>
using namespace std;

//int Complexity();
int** CreateMatrix();
void Transpose(int** table[9]);//
void SwapRows(int** table[9]);//
void SwapColumns(int** table[9]);//
void SwapRowAreas(int** table[9]);//
void SwapColumnAreas(int** table[9]);//
void DeleteCells(int ind, int** table[9]);
void Out(int table[9][9]);
//int Check(int table[9][9]);
