#include <stdio.h>
#include <stdlib.h>

int **readIn();
int *getLine(int **grid);
void printGrid(const int **grid);
void freeGrid(int **grid);
void solve(int **grid);
int checkRow(const int **grid, const int row, const int check);
int checkCol(const int **grid, const int col, const int check);
int fillBox(const int **grid, const int row, const int col);
int countUnsolved(const int **grid);

int main(){

	int **grid = readIn();



	return 0;
}

int checkRow(const int **grid, const int row, const int check){
	for(int i = 0; i < 9; i++){
		if(grid[row][i] == check){
			return 0;
		}
	}
	return 1;
}

int checkCol(const int **grid, const int col, const int check){
  for(int i = 0; i < 9; i++){
    if(grid[i][col] == check){
      return 0;
    }
  }
  return 1;
}

int **readIn(){
	int **grid = malloc(9*sizeof(int*));

}

int *getLine(int **grid){

}

void printGrid(const int **grid){

}

void freeGrid(int **grid){

}

void solve(int **grid){

	while(countUnsolved > 0){
		
	}

}

int fillBox(const int **grid, const int row, const int col){
//counter for potential values, if potential values > 1 -> skip
	int numPotentials = 0;
	int fillNum = 0;

	for(int i = 0; i < 9; i++){
		if(checkRow(grid, row, i) && checkCol(grid, col, i)){
			++numPotentials;
			fillNum = i;
		}
	}

	if(numPotentials > 1){
		return -1;
	}else{
		return fillNum;
	}
}

int countUnsolved(const int **grid){
	int emptyBox = 0;

//The concept is that unsolved boxes will be stored as 0

	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(grid[i][j] == 0){
				++emptyBox;
			}
		}
	}
	return emptyBox;
}
