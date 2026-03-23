#include <iostream>
#include <sqlite3.h>
using namespace std;

int callback(void *NotUsed, int argc, char **argv, char **azColName);
void makeDB(sqlite3 *db);
void createTable(sqlite3 *db);
void booking();
void maintenance();
void billing();
void printReport();
void menu(sqlite3 *db);

int main(){
	sqlite3 *db;
	char c;
	cout << "Do you have a hotel database already? (y/n): ";
	cin >> c;

	if(c == 'y' || c == 'Y'){
		char *dbName;
		cout << "Enter the database name (ex. exampleDB.db): ";
		cin >> dbName;
	} else {
		makeDB(db); //If there is no prexisting database
	}

	sqlite3_close(db);
	return 0;
}

void menu(sqlite3 *db){
	int choice;
	cout << "" << endl;
	cout << "" << endl;
	switch(choice){
	case 1:

		break;
	case 2:

		break;
	case 3:

		break;
	}
}

void makeDB(sqlite3 *db){
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

void createTable(sqlite3 *db){
	int rc;
	char *zErrMsg = 0;
	const char* sql;
  sql = "CREATE TABLE ROOM(" \
  "ID INT PRIMARY KEY NOT NULL," \
  "LEVEL INT NOT NULL," \
  "NUMBER INT NOT NULL," \
  "CAPACITY INT NOT NULL," \
  "PRICE REAL NOT NULL," \
  "OCCUPIED TEXT);";
  rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	cout << rc << endl;
	if(rc != SQLITE_OK){
		cout << "SQL Error: " << zErrMsg << endl;
		sqlite3_free(zErrMsg);
	}	else{
		cout << "Table created successfully" << endl;
	}

}

void booking();
void maintenance();
void billing();
void printReport();

int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}
