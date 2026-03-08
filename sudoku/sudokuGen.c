#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct squares {
  int (*box)[3];
};

struct grid {
  struct squares (*square)[3];
};

int checkRow(const struct grid *g, const int checkVal, const int squareX, const int squareY, const int x, const int y);
int checkCol(const struct grid *g, const int checkVal);
int validFill(const struct grid *g);
void fillBox();
void constructSquare();
void constructGrid();
void printGrid(const struct grid *finalGrid);

int main(int argc, char *argv){
//Command line argument for difficulty

	srand(time(NULL));


  return 0;
}

int checkRow(const struct grid *g, const int checkVal, const int squareX, const int squareY, const int x, const int y){
	for(int i = 0; i < 9; i++){
		if(i == y && i < 8){
			i++;
		}else if(i == y && i == 8){
			return 1;
		}

		if(g->square[squareX][squareY].box[x][i] == checkVal){
			return 0;
		}
	}

	return 1;
}

int checkCol(const struct grid *g, const int checkVal){
	for(int i = 0; i < 9; i++){

		if(i == ){

		}else if(){

		}

		if(){
			return 0;
		}

	}

	return 1;
}

int validFill(const struct grid *g){

}

void fillBox(){

}

void constructSquare(){

}

void constructGrid(){

}

void printGrid(const struct grid *finalGrid){

}
