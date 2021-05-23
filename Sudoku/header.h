#include <iostream>
#include <ctime>
#define SIZESMALL 3
#define SIZEBIG (SIZESMALL * SIZESMALL)
#define LIVES 5
#define LINE 61
#define SIZEWID 5
using namespace std;
class Sudoku {
	int matrix[SIZEBIG][SIZEBIG];
	int complexity;
	int missingCells;
	int answer[SIZEBIG][SIZEBIG];
public:
	void Complexity();
	void CreateMatrix();
	void Transpose();
	void SwapRows();
	void SwapColumns();
	void SwapRowAreas();
	void SwapColumnAreas();
	void DeleteCells();
	void PrintingSudoku();
	bool Solve();
	int Check(int element,int row, int col);
	int StepCheck(int row,int col);
	void Game();
};

