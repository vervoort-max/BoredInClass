#include <iostream>
#include <sqlite3.h>

class Hotel {
	struct Update{
  	int cap;
  	char *occu;
  	float price;
  	Update(int cap, char *occu, float price) : cap{cap},
    	occu{occu}, price{price} {}
	};
	public:
	int checkRoomExists(const int floor, const int num, sqlite3 *db);
	int callback(void *NotUsed, int argc, char **argv, char **azColName);
	void makeDB(sqlite3 *db);
	void createTable(sqlite3 *db);
	void booking(sqlite3 *db);
	void maintenance();
	void billing();
	void fullReport(sqlite3 *db);
};
