#include "header.h"

int Sudoku::Check(int element,int a,int b){
	int i,j;
	for(i=0;i<9;i++){
		if(answer[a][i] != element && answer[i][b] != element);
		else
			return 0;
	}
	if(a<SizeSmall){
		i=0;
		j=SizeSmall;
	}else if(a<2*SizeSmall){
		i=SizeSmall;
		j=2*SizeSmall;
	}else{
		i=2*SizeSmall;
		j=SizeBig;
	}
	int r,k;
	if(b<SizeSmall){
		r=0;
		k=SizeSmall;
	}else if(b<2*SizeSmall){
		r=SizeSmall;
		k=2*SizeSmall;
	}else{
		r=2*SizeSmall;
		k=SizeBig;
	}
	for(int s=i;s<j;s++){
		for(int h=r;h<k;h++){
			if(answer[s][h] != element);
			else
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

void Sudoku::Solve(){
	if(!StepCheck(0,0)){
		cout << "Error.Solving failed!\n";
	}
}
