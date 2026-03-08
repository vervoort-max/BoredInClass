#include <stdio.h>
#include <stdlib.h>

struct box {
	int solved;
	int value;
};

struct square {
	int solved;
	struct box[3][3];
};

struct grid {
	int solved;
	struct square[3][3];
};

void readInGrid();
void constructSquare();

int main(){



	return 0;
}
