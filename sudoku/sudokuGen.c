#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void emptyGrid();
int checkRow();
int checkCol();
int validFill();
void fillBox();
void printGrid(const int (*grid)[9]);

int main(int argc, char *argv){
//Command line argument for difficulty
	srand(time(NULL));

	int (*grid)[9];
	emptyGrid(&grid);

  return 0;
}

int checkRow(){
}

int checkCol(){

}

int validFill(){

}

void fillBox(){

}

void printGrid(const int (*grid)[9]){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){

		}
	}
}

void emptyGrid(int (*grid)[9]){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			grid[i][j] = 0;
		}
	}
}
