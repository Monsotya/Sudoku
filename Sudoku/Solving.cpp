#include "header.h"

int Sudoku::Check(int element,int row,int col){
	int rowcol;
	for(rowcol=0;rowcol<SizeBig;rowcol++){
		/*if(answer[a][i] != element && answer[i][b] != element);
		else
			return 0;*/
		if(answer[row][rowcol] == element && answer[rowcol][col] == element)
			return 0;
	}
	// int i,j;
	int rowUpLim,rowDownLim;
	if(row<SizeSmall){
		rowUpLim=0;
		rowDownLim=SizeSmall;
	}else if(row<2*SizeSmall){
		rowUpLim=SizeSmall;
		rowDownLim=2*SizeSmall;
	}else{
		rowUpLim=2*SizeSmall;
		rowDownLim=SizeBig;
	}
	int colLeftLim,colRightLim;
	//int r,k;
	if(col<SizeSmall){
		colLeftLim=0;
		colRightLim=SizeSmall;
	}else if(col<2*SizeSmall){
		colLeftLim=SizeSmall;
		colRightLim=2*SizeSmall;
	}else{
		colLeftLim=2*SizeSmall;
		colRightLim=SizeBig;
	}
	/*for(int s=i;s<j;s++){
		for(int h=r;h<k;h++){
			if(answer[s][h] != element);
			else
				return 0;
		}
	}*/
	for(int i=rowUpLim;i<rowDownLim;i++){
		for(int j=colLeftLim;j<colRightLim;j++){
			if(answer[i][j] == element)
				return 0;
		}
	}
	return 1;
}

int Sudoku::StepCheck(int i,int j){
	if(i >= SizeBig-1 && j >= SizeBig)
		return 1;
	if(j >= SizeBig){
		j = 0;
		i++;
	}
	if(answer[i][j] != 0)
		return StepCheck(i,j+1);
	
	for(int k=1;k<10;k++){
		if(Check(k,i,j)){
			answer[i][j]=k;
			if(StepCheck(i,j+1)){
				return 1;
			}else{
				answer[i][j]=0;
			}
		}
	}
	return 0;
}

bool Sudoku::Solve(){
	if(!StepCheck(0,0)){
		cout << "Error.Solving failed!\n";
		return false;
	}
	return true;
}
