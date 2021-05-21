#include "header.h"
void Sudoku::Out(){
	cout << "  y";
	int row = 0;
	int col;
	for(int i=0;i<SizeSmall;i++){
		for(int j=0;j<SizeSmall;j++){
			cout.width(SizeWid);
			cout << row++;
		}
		cout << "    ";
	}
	cout << '\n';
	row = 0;
	for(int i=0;i<SizeSmall;i++){
		if(!i){
			cout << "x ";
		}else{
			cout << "  ";
		}
		cout.width(Line);
		cout.fill('-');
		cout << '-' << '\n';
		for(int a=0;a<SizeSmall;a++){
			col = 0;
			cout << row << " ||";
			cout.fill(' ');
			for(int r=0;r<SizeSmall;r++){
				cout.width(SizeWid-1);
				if(matrix[row][col] == 0){
					cout << '-';
				}else{
					cout << matrix[row][col];
				}
				col++;
				for(int k=0;k<SizeSmall-1;k++){
					cout.width(SizeWid);
					if(matrix[row][col] == 0){
						cout << '-';
					}else{
						cout << matrix[row][col];
					}
					col++;
				}
				cout.width(SizeWid);
				cout << '|';
			}
			row++;
			cout << "|\n";
		}
	}
	cout << "  ";
	cout.width(Line);
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
