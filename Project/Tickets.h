#include <iostream>
using namespace std;

enum SpectatorType { CHILD, TEENAGER, STUDENT, ADULT, SENIOR};
//senior = any person 60 years or over

class Ticket {
private:
	int uniqueID;
	bool isVIP = false;
	int noRow = 0;
	int noSeat = 0;
	SpectatorType type = ADULT;
	int* tickets = nullptr;
	int noTickets = 0;
	static int MINIMUM_TICKETS_NUMBER;
	static int MAXIMUM_ROWS_NUMBER;
	static int MAXIMUM_SEATS_NUMBER;
public:
	Ticket()
	{
		uniqueID = 0;
		isVIP = false;
		noRow = 1;
		noSeat = 1;
		type = ADULT;
	}

	Ticket(int uniqueId, int noRow, int noSeat, SpectatorType type, int* tickets, int noTickets)
	{
		this->uniqueID = generateUniqueID();
		this->isVIP = false;
		this->noRow = noRow;
		this->noSeat = noSeat;
		this->type = type;
		if (tickets != nullptr && noTickets > 0)
		{
			this->tickets = new int[noTickets];
			for (int i = 0; i < noTickets; i++)
			{
				this->tickets[i] = tickets[i];
			}
			this->noTickets = noTickets;
		}
		else
		{
			this->tickets = nullptr;
			this->noTickets = 0;
		}
	}

	Ticket(const Ticket& t)
	{
		this->uniqueID = t.uniqueID;
		this->isVIP = t.isVIP;
		this->noRow = t.noRow;
		this->noSeat = t.noSeat;
		this->type = t.type;
		if (t.tickets != nullptr && t.noTickets > 0)
		{
			this->tickets = new int[t.noTickets];
			for (int i = 0; i < t.noTickets; i++)
			{
				this->tickets[i] = t.tickets[i];
			}
			this->noTickets = t.noTickets;
		}
		else
		{
			this->tickets = nullptr;
			this->noTickets = 0;
		}
	}

	~Ticket()
	{
		delete[] tickets;
	}

	int generateUniqueID() //for this I have used information from https://cplusplus.com/reference/cstdlib/rand/
	{
		srand(time(nullptr));
		int uniqueID = rand() % 1000;
		return uniqueID;
	}

	int getUniqueID()
	{
		return uniqueID;
	}

	void markAsVIP()
	{
		isVIP = 0;
	}

	void setNoRow(int row)
	{
		if (row < 1 && row > 25)
		{
			cout << endl << "We only have a number of 25 rows.";
		}
		else
			this->noRow = row;
	}

	int getNoRow()
	{
		return this->noRow;
	}

	int getMaxRows()
	{
		return MAXIMUM_ROWS_NUMBER;
	}

	int getMaxSeats()
	{
		return MAXIMUM_SEATS_NUMBER;
	}

	int getTotalNoSeats()
	{
		return MAXIMUM_ROWS_NUMBER * MAXIMUM_SEATS_NUMBER;
	}

	friend void operator<<(ostream& out, Ticket t);
	friend void operator>>(istream& in, Ticket& t);

};

int Ticket::MINIMUM_TICKETS_NUMBER = 1;
int Ticket::MAXIMUM_ROWS_NUMBER = 25;
int Ticket::MAXIMUM_SEATS_NUMBER = 30;

void operator<<(ostream& out, Ticket t)
{
	out << endl << "VIP Ticket: " << t.isVIP;
	out << endl << "Row number: " << t.noRow;
	out << endl << "Seat number: " << t.noSeat;
}

void operator>>(istream& in, Ticket& t)
{
	cout << "VIP Ticket: ";
	in >> t.isVIP;
	cout << "Row number: ";
	in >> t.noRow;
	cout << "Seat number: ";
	in >> t.noSeat;
}