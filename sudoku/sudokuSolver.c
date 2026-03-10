#include <stdio.h>
#include <stdlib.h>

int **readIn();
int *getLine();
void printGrid(int **grid);
void freeGrid(int **grid);
void solve(int **grid);
int checkRow(int **grid, const int row, const int check);
int checkCol(int **grid, const int col, const int check);
int fillBox(int **grid, const int row, const int col);
int countUnsolved(int **grid);

int main(){

	int **grid = readIn();
	solve(grid);
	printGrid(grid);
	freeGrid(grid);

	return 0;
}

int checkRow(int **grid, const int row, const int check){
	for(int i = 0; i < 9; i++){
		if(grid[row][i] == check){
			return 0;
		}
	}
	return 1;
}

int checkCol(int **grid, const int col, const int check){
  for(int i = 0; i < 9; i++){
    if(grid[i][col] == check){
      return 0;
    }
  }
  return 1;
}

int **readIn(){
	int **grid = malloc(9*sizeof(int*));
	for(int i = 0; i < 9; i++){
		grid[i] = getLine();
	}
	return grid;
}

int *getLine(){
	int *line = malloc(9*sizeof(int));
	for(int i = 0; i < 9; i++){
		scanf("%d", &line[i]);
	}
	return line;
}

void printGrid(int **grid){
	printf("--- --- --- --- --- --- --- --- ---\n");
	for(int i = 0; i < 9; i++){
		printf("| ");
		for(int j = 0; j < 9; j++){
			printf("%d |", grid[i][j]);
		}
		printf("--- --- --- --- --- --- --- --- ---\n");
	}

}

void freeGrid(int **grid){

}

void solve(int **grid){
	while(countUnsolved(grid) > 10){
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				if(grid[i][j] == 0){
					int num = fillBox(grid, i, j);
					if(num != -1){
          	grid[i][j] = num;
        	}
				}
			}
		}
	}
}

int fillBox(int **grid, const int row, const int col){
//counter for potential values, if potential values > 1 -> skip
	int numPotentials = 0;
	int fillNum = 0;

	for(int i = 1; i <= 9; i++){
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

int countUnsolved(int **grid){
	int emptyBox = 0;

//The concept is that unsolved boxes will be stored as 0
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(grid[i][j] == 0){
				emptyBox++;
			}
		}
	}
	return emptyBox;
}
