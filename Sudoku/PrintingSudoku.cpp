#include "header.h"
void Sudoku::Out(){
	cout << "  y";
	int row = 0;
	int col;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout.width(5);
			cout << row++;
		}
		cout << "    ";
	}
	cout << '\n';
	row = 0;
	for(int i=0;i<3;i++){
		if(!i){
			cout << "x ";
		}else{
			cout << "  ";
		}
		cout.width(61);
		cout.fill('-');
		cout << '-' << '\n';
		for(int a=0;a<3;a++){
			col = 0;
			cout << row << " ||";
			cout.fill(' ');
			for(int r=0;r<3;r++){
				cout.width(4);
				if(matrix[row][col] == 0){
					cout << '-';
				}else{
					cout << matrix[row][col];
				}
				col++;
				for(int k=0;k<2;k++){
					cout.width(5);
					if(matrix[row][col] == 0){
						cout << '-';
					}else{
						cout << matrix[row][col];
					}
					col++;
				}
				cout.width(5);
				cout << '|';
			}
			row++;
			cout << "|\n";
		}
	}
	cout << "  ";
	cout.width(61);
	cout.fill('-');
	cout << '-' << '\n';
	cout.fill(' ');
}

/*
void Sudoku::ShowSolution(){
	for(int i=0;i<SizeBig;i++){
		for(int j=0;j<SizeBig;j++){
			matrix[i][j]=answer[i][j];
		}
	}
	cout << "Solution :\n";
	Out();
}
*/
