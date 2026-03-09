#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **emptyGrid();
int checkRow(const int **grid, const int row, const int check);
int checkCol(const int **grid, const int col, const int check);
int validFill(const int **grid, const int fillVal);
void fillBox(int **grid, const int fillVal);
void printGrid(const int **grid);

int main(int argc, char *argv){
//Command line argument for difficulty
	srand(time(NULL));

	int **grid = emptyGrid();

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

int validFill(const int **grid, const int fillVal){

}

void fillBox(int **grid, const int fillVal){

}

void printGrid(const int **grid){
	printf("\n--- --- --- --- --- --- --- --- ---\n");
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			printf("| %d ", grid[i][j]);
		}
		printf("\n--- --- --- --- --- --- --- --- ---\n");
	}
}

int **emptyGrid(){

}
