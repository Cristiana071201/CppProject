#include <iostream>
using namespace std;

class Location
{
private:
	//zones
	bool VIPzone = true;
	//number of rows
	int noRows = 0;
	//number of seats per row
	int* seatsPerRow = nullptr;
	int noSeatsPerRow = 0;
	//maximum number of seats
	static int MAXIMUM_SEATS_NUMBER;
public:

};
int Location::MAXIMUM_SEATS_NUMBER = 300;