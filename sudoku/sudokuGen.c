#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **emptyGrid();
int checkRow(const int **grid, const int row, const int check);
int checkCol(const int **grid, const int col, const int check);
int validFill(const int **grid, const int fillVal, const int row, const int col);
void fillBox(int **grid, const int fillVal);
void printGrid(int **grid);
void filler(const int **grid);
void gen(int **grid, const char diff);
void saveIt(int **grid);

int main(int argc, char *argv){
//Command line argument for difficulty
	if(argc < 3){
		printf("\nMust include 2 flags(ex. e p)");
		exit(1);
	}

	srand(time(NULL));

	int **grid = emptyGrid();
	gen(grid, argv[1]);

	switch(argv[2]){
		case 'p':
			printGrid(grid);
			break;
		case 's':
			saveIt(grid);
			break;
	}

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

int validFill(const int **grid, const int fillVal, const int row, const int col){
	if(checkRow(grid, row, fillVal) && checkCol(grid, col, fillVal)){
		return 1;
	}else{
		return 0;
	}
}

void fillBox(int **grid, const int fillVal){

}

void printGrid(int **grid){
	printf("\n--- --- --- --- --- --- --- --- ---\n");
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			printf("| %d ", grid[i][j]);
		}
		printf("\n--- --- --- --- --- --- --- --- ---\n");
	}
}

int **emptyGrid(){
//Add malloc stuff here I guess

	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){

		}
	}
}

void gen(int **grid, const char diff){
	int totFills = 0;
	int filled = 0;
	const int skip = rand();

	switch(diff){
		case 'e':
			totFills = 60;
			break;
		case 'm':
			totFills = 40;
			break;
		case 'h':
			totFills = 17;
			break;
	}

	while(filled != totFills){

	}

}


void saveIt(int **grid){

}
