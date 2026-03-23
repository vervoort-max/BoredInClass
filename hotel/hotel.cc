#include <iostream>
#include <sqlite3.h>
using namespace std;

void makeDB(sqlite3 *db);
void createTable(sqlite *db);
void booking();
void maintenance();
void billing();
void printReport();

int main(){
	sqlite3 *db;
	makeDB(db);

	sqlite3_close(db);
	return 0;
}

void makeDB(sqlite3 *db){
  int rc;
  rc = sqlite3_open("test.db", &db);
  if(rc){
    cout << "Can not open hotel database\n" << sqlite3_errmsg(db);
  } else {
    cout << "Opened hotel database successfully\n";
  }
	sql = "CREATE TABLE ROOM(" \
	"ID INT PRIMARY KEY NOT NULL" \
	"FLOOR INT NOT NULL," \
	"NUMBER INT NOT NULL" \
	"CAPACITY INT NOT NULL" \
	"" \
}

void createTable(sqlite *db){
	



}

void booking();
void maintenance();
void billing();
void printReport();
