#include <iostream>
#include <sqlite3.h>

class Hotel {
	struct Update{
  	int cap;
  	char *occu;
  	float price;
    ~Update();
	};
	sqlite3 *db;
	char *fileName;
	public:
	Hotel() : db{nullptr} {}
	int checkRoomExists(const int floor, const int num, sqlite3 *db);
	int callback(int argc, char **argv, char **azColName);
	void makeDB(sqlite3 *db);
	void createTable(sqlite3 *db);
	void booking(sqlite3 *db);
	void maintenance();
	void billing();
	void fullReport(sqlite3 *db);
};
