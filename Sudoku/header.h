#include <iostream>
#include <ctime>
#define SIZESMALL 3
#define SIZEBIG (SIZESMALL * SIZESMALL)
#define LIVES 5
#define LINE 51
#define SIZEWID 4
#define SECONDS 60
#define EASYPERCENT 0.5
#define MEDIUMPERCENT 0.6
#define HARDPERCENT 0.7
using namespace std;
class Sudoku {
	int matrix[SIZEBIG][SIZEBIG];
	int complexity;
	int stepsProgramm;
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
	bool CheckAnswer(char* str);
	void Welcome();
};

