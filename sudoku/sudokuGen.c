#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct space {
  int value;
};

struct squares {
  struct space (*box)[3];
};

struct grid {
  struct squares (*square)[3];
};

int checkRow(const struct grid *g);
int checkCol(const struct grid *g);
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

int checkRow(const struct grid *g){

}

int checkCol(const struct grid *g){

}

int validFill(const struct grid *g);

void fillBox();

void constructSquare(){

}

void constructGrid(){

}

void printGrid(const struct grid *finalGrid);
