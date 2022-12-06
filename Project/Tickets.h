#include <iostream>
using namespace std;

enum SpectatorType { CHILD, TEENAGER, STUDENT, ADULT, SENIOR};
//senior = any person 60 years or over

class Ticket {
private:
	bool isVIP = false;
	int noRow = 0;
	int noSeat = 0;
	SpectatorType type = ADULT;
	int* tickets = nullptr;
	int noTickets = 0;
	static int MINIMUM_TICKETS_NUMBER;
	static int MAXIMUM_ROWS_NUMBER;
	static int MAXIMUM_SEATS_NUMBER;
	const int uniqueId;
public:
	Ticket(int noRow, int noSeat, SpectatorType type, int* tickets, int noTickets, int uniqueId):uniqueId(uniqueId)
	{
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

	Ticket(const Ticket& t) :uniqueId(t.uniqueId)
	{
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

	int getUniqueId()
	{
		return uniqueId;
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

	//friend void operator<<(ostream& out, Ticket t);
	//friend void operator>>(istream& in, Ticket& t);

};

int Ticket::MINIMUM_TICKETS_NUMBER = 1;
int Ticket::MAXIMUM_ROWS_NUMBER = 25;
int Ticket::MAXIMUM_SEATS_NUMBER = 30;

//void operator<<(ostream& out, Ticket t)
//{
//
//}
//
//void operator>>(istream& in, Ticket& t)
//{
//
//}
