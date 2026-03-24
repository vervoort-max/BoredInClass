#include <iostream>
#include <sqlite3.h>

class Hotel {
	struct Update{
  	int cap;
  	char *occu;
  	float price;
  	Update(int cap, char *occu, float price) : cap{cap}, occu{occu}, price{price} {};
  	~Update();
	};
	public:
	sqlite3 *db;
  char *fileName;
	Hotel() : db{nullptr} {}
	Hotel(sqlite3 *db) : db{db} {}
	int checkRoomExists(const int floor, const int num, sqlite3 *db);
	static int callback(void *notUsed, int argc, char **argv, char **azColName);
	void makeDB(sqlite3 *db);
	void createTable(sqlite3 *db);
	void booking(sqlite3 *db);
	void maintenance();
	void billing();
	void fullReport(sqlite3 *db);
};
