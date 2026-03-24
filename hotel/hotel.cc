#include <iostream>
#include <sqlite3.h>
#include "hotel.h"
using namespace std;

Hotel::Update::~Update(){
	delete this;
}

void Hotel::makeDB(sqlite3 *db){
  int rc;
  char *zErrMsg = 0;
  rc = sqlite3_open("test.db", &db);
  if(rc){
    cout << "Can not open hotel database\n" << sqlite3_errmsg(db);
  } else {
    cout << "Opened hotel database successfully\n";
  }
  createTable(db);
}

void Hotel::createTable(sqlite3 *db){
  int rc;
  char *zErrMsg = 0;
  const char* sql;
  const char* data = "Callback Called";
  sql = "CREATE TABLE ROOM(" \
  "ID INT PRIMARY KEY NOT NULL," \
  "LEVEL INT NOT NULL," \
  "NUMBER INT NOT NULL," \
  "CAPACITY INT NOT NULL," \
  "PRICE REAL NOT NULL," \
  "OCCUPIED TEXT);";
  rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
  cout << rc << endl;
  if(rc != SQLITE_OK){
    cout << "SQL Error: " << zErrMsg << endl;
    sqlite3_free(zErrMsg);
  } else{
    cout << "Table created successfully" << endl;
  }

}

int Hotel::checkRoomExists(const int floor, const int num, sqlite3 *db){


  return 0;
}

void Hotel::booking(sqlite3 *db){
  char *sql;
  int num, floor;
  char *name;
  char c;
  cout << "Enter Room (ex. 2 01 <- Level 2, Number 1): ";
  cin >> floor >> c >> num;
  while(!checkRoomExists(floor, num, db)){
    cout << "Room does not exist" << endl;
    cout << "Enter Room (ex. 2 01 <- Level 2, Number 1): ";
    cin >> floor >> c >> num;
  }

  cout << "Enter Occupant Name: ";
  cin >> name;
  Update newBooking(0, name, 0);
}

void Hotel::maintenance(){

}

void Hotel::billing(){

}

void Hotel::fullReport(sqlite3 *db){

}

int Hotel::callback(void *notUsed, int argc, char **argv, char **azColName){
	int i;
	for(i = 0; i < argc; ++i){
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	cout << endl;
	return 0;
}
