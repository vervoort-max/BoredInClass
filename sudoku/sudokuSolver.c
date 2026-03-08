#include <stdio.h>
#include <stdlib.h>

struct space {
	int solved;
	int value;
};

struct squares {
	int solved;
	struct space (*box)[3];
};

struct grid {
	int solved;
	struct squares (*square)[3];
};

void readInGrid();
void constructSquare();

int main(){



	return 0;
}
