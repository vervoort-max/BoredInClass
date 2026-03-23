#include <iostream>
#include <sqlite3.h>
using namespace std;

//Should I do an update struct?
struct Update{
	int cap;
	char *occu;
	float price;
	Update(int cap, char *occu, float price) : cap{cap},
    occu{occu}, price{price} {}
};

int callback(void *NotUsed, int argc, char **argv, char **azColName);
void makeDB(sqlite3 *db);
void createTable(sqlite3 *db);
void booking();
void maintenance();
void billing();
void fullReport(sqlite3 *db);
void menu(sqlite3 *db);
void menuPrint();
void operate(sqlite3 *db);

int main(){
	sqlite3 *db;
	char c;
	cout << "Do you have a hotel database already? (y/n): ";
	cin >> c;

	if(c == 'y' || c == 'Y'){
		char *dbName;
		cout << "Enter the database name (ex. exampleDB.db): ";
		cin >> dbName;
		sqlite3_open(dbName, &db);
		operate(db);
	} else {
		makeDB(db);
	}

	sqlite3_close(db);
	return 0;
}

int menu(){
	int choice;
	menuPrint();
	cin >> choice;
	while(choice > 5 || choice < 1){
		cout << "\nInvalid Input" << endl;
		menuPrint();
		cin >> choice;
	}
	return choice;
}

void operate(sqlite3 *db){
	int operation;
	operation = menu();
	switch(operation){
	case 1:
		fullReport(db);
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

int checkRoomExists(const int floor, const int num, sqlite3 *db){


	return 0;
}

void booking(sqlite3 *db){
	char *sql;
	int num, floor;
	char *name;
	char c;
	cout << "Enter Room (ex. 2 01 <- Level 2, Number 1): ";
	cin >> floor >> c >> num;
	while(!checkRoomExists(floor, num db)){
		cout << "Room does not exist" << endl;
		cout << "Enter Room (ex. 2 01 <- Level 2, Number 1): ";
  	cin >> floor >> c >> num;
	}

	cout << "Enter Occupant Name: ";
	cin >> name;
	Update newBooking(floor, num, name);
}

void maintenance();
void billing(){

}

void fullReport(sqlite3 *db){

}

int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

void menuPrint(){
	cout << "            *** ACTIONS ***           " << endl;
	cout << "======================================" << endl;
	cout << "1. Full Report" << endl;
	cout << "2. Booking" << endl;
	cout << "3. Billing" << endl;
	cout << "4. Maintenance" << endl;
	cout << "======================================" << endl;
	cout << "Please make a selection: ";
}
