#include <iostream>
#include <sqlite3.h>
#include "hotel.h"
using namespace std;

int menu();
void menuPrint();
void operate(Hotel h);

int main(){
	Hotel h;
	char c;
	cout << "Do you have a hotel database already? (y/n): ";
	cin >> c;

//This could also be in the class??
	if(c == 'y' || c == 'Y'){
		char *dbName;
		cout << "Enter the database name (ex. exampleDB.db): ";
		cin >> dbName;
		sqlite3_open(dbName, &h.db);
		operate(h.db);
	} else {
		h.makeDB(h.db);
	}

	sqlite3_close(h.db); //This could be in the class
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

void operate(Hotel h){
	int operation;
	operation = menu();
	switch(operation){
	case 1:
		h.fullReport(h.db);
		break;
	}
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
