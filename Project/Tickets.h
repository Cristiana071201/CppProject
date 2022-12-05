#include <iostream>
using namespace std;

enum SpectatorType { CHILD, TEENAGER, STUDENT, ADULT, SENIOR};
//senior = any person 60 years or over

class Ticket {
private:
	bool VIP = false;
	int noRow;
	int noSeat;
	SpectatorType type;
	int* tickets;
	int noTickets;
	static int MINIMUM_TICKETS_NUMBER;
	const int uniqueId;
public:
	Ticket():uniqueId(0)
	{
		noRow = 0;
		noSeat = 0;
		type = ADULT;
		tickets = nullptr;
		noTickets = 0;
	}

	Ticket(int noRow, int noSeat, SpectatorType type, int* tickets, int noTickets, int uniqueId):uniqueId(uniqueId)
	{
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
};
int Ticket::MINIMUM_TICKETS_NUMBER = 1;