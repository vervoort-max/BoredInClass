#include <iostream>
#include <fstream>
using namespace std;

struct Room {
	int floor, number, capacity;
	float price;
	bool full, cleaned, maintenance;
	Room(int floor, int number, int capacity, float price) : floor{floor}, number{number}, capacity{capacity}, price{price} {} 
};

struct Customer {
	int id, groupSize;
	bool checkIn;
	float bill;
};

struct Hotel {
	int rooms;
	float percentFull, expenses;
	Room r[];
	Hotel(){}
};


Hotel conFile();
Hotel con();
void booking();
Room findRoom(const int size, const Room r[]);
void maintenance();
void billing();
void printReport();
Hotel startUp();

int main(){
	Hotel myHotel;
	myHotel = startUp();

	return 0;
}

Hotel conFile();

Hotel con(){
	int numRoom;
	cout << "\nHow many rooms are in your hotel?: ";
	cin >> numRoom;
	Hotel h;
	cout << "Please enter the details for the rooms in the following order: floor# room# capacity price" << endl;
	for(int i = 0; i < numRoom; ++i){
		cout << "Room #" << i << ": ";
		cin >> h.r[i].floor >> h.r[i].number >> h.r[i].capacity >> h.r[i].price;
	}
	return h;
}

void booking();
Room findRoom(const int size, const Room r[]);
void maintenance();
void billing();
void printReport();

Hotel startUp(){
	char c;
	cout << "Welcome! Are you working off an existing HotelBooky database? (y/n): ";
	cin >> c;
	Hotel maker;
	if(c == 'y'){
		maker = conFile();
	}else{
		maker = con();
	}
	return maker;
}
