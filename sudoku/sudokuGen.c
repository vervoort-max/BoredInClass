#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **emptyGrid();
int checkRow(const int **grid);
int checkCol(const int **grid);
int validFill(const int **grid);
void fillBox(int **grid);
void printGrid(const int **grid);

int main(int argc, char *argv){
//Command line argument for difficulty
	srand(time(NULL));

	int **grid = emptyGrid();

  return 0;
}

int checkRow(const int **grid){
}

int checkCol(const int **grid){

}

int validFill(const int **grid){

}

void fillBox(int **grid){

}

void printGrid(const int **grid){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){

		}
	}
}

int **emptyGrid(){

}
