#include <iostream>
using namespace std;

enum SpectatorType { CHILD, TEENAGER, STUDENT, ADULT, SENIOR};
//senior = any person 60 years or over

class Ticket {
private:
	int uniqueID = 0;
	int price = 0;
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

	Ticket(int uniqueID, int price, int noRow, int noSeat, SpectatorType type, int* tickets, int noTickets)
	{
		this->uniqueID = generateUniqueID();
		this->isVIP = false;
		this->price = price;
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
		this->price = t.price;
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

	bool getIsVIP() //bool vipStatus = ticket.getIsVIP();
	{
		return isVIP;
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

	void setIsVIP(bool vip) //ticket.setIsVIP(true);
	{
		this->isVIP = vip;
	}

	virtual int getPrice()
	{
		return this->price;
	}

	virtual SpectatorType getType() 
	{ 
		return this->type;
	}

	virtual void setPrice(int p)
	{
		this->price = p;
	}

	virtual void setType(SpectatorType t) 
	{ 
		this->type = t; 
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

	int operator*()
	{
		return price * noTickets;
	}

	bool operator>=(const Ticket& t) //compare the prices between objects
	{
		return price >= t.price;
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
	out << endl << "Ticket type: " << t.type;
	out << endl << "Row number: " << t.noRow;
	out << endl << "Seat number: " << t.noSeat;
}

void operator>>(istream& in, Ticket& t)
{
	cout << "VIP Ticket: " << endl;
	in >> t.isVIP;
	cout << "Ticket type: " << endl;
	string type;
	in >> type;
	if (type == "CHILD") t.type = CHILD;
	else if (type == "TEENAGER") t.type = TEENAGER;
	else if (type == "STUDENT") t.type = STUDENT;
	else if (type == "ADULT") t.type = ADULT;
	else if (type == "SENIOR") t.type = SENIOR;
	else 
	{
		cout << "Invalid spectator type. Please enter a valid type." << endl;
	}
	cout << "Row number: " << endl;
	in >> t.noRow;
	cout << "Seat number: " << endl;
	in >> t.noSeat;
}

class VIPTicket : public Ticket {
private:
	string VIP_service;
public:
	string getVIPService()
	{
		return VIP_service;
	}
};


class SpectatorTicket : public Ticket {
private:
	int price;
	SpectatorType typeS;
public:
	SpectatorTicket(int price, SpectatorType typeS)
	{
		this->price = price;
		this->typeS = typeS;
	}

	int getPrice() 
	{
		return price;
	}

	SpectatorType getType()
	{ 
		return this->typeS;
	}

	SpectatorType getSpectatorType()
	{
		return typeS;
	}
};