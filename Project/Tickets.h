#include <iostream>
using namespace std;

enum SpectatorType { CHILD, TEENAGER, STUDENT, ADULT, SENIOR};
//senior = any person 60 years or over

class Tickets {
private:
	bool VIP = false;
	int noRow = 0;
	int noSeat;
	SpectatorType type;
	int* tickets = nullptr;
	int noTickets = 0;
	static int MINIMUM_TICKETS_NUMBER;
	const int uniqueId;
public:

};
int Tickets::MINIMUM_TICKETS_NUMBER = 1;