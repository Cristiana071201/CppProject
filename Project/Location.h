#include <iostream>
using namespace std;

class Location
{
private:
	//zones
	bool isVIP = true;
	//number of rows
	int noRows = 0;
	//number of seats per row
	int* seatsPerRow = nullptr;
	int noSeatsPerRow = 0;
	//maximum number of seats
	static int MAXIMUM_SEATS_NUMBER;
public:
	Location()
	{
		isVIP = false;
		noRows = 10;
		seatsPerRow = nullptr;
		noSeatsPerRow = 10;
	}

	Location(bool isVIP, int noRows, int* seatsPerRow, int noSeatsPerRow)
	{
		this->isVIP = isVIP;
		this->noRows = noRows;
		if (seatsPerRow != nullptr && noSeatsPerRow > 0)
		{
			this->seatsPerRow = new int[noSeatsPerRow];
			for (int i = 0; i < noSeatsPerRow; i++)
			{
				this->seatsPerRow[i] = seatsPerRow[i];
			}
			this->noSeatsPerRow = noSeatsPerRow;
		}
		else
		{
			this->seatsPerRow = nullptr;
			this->noSeatsPerRow = 0;
		}
	}

	Location(const Location& l)
	{
		this->isVIP = l.isVIP;
		this->noRows = l.noRows;
		if (l.seatsPerRow != nullptr && l.noSeatsPerRow > 0)
		{
			this->seatsPerRow = new int[l.noSeatsPerRow];
			for (int i = 0; i < l.noSeatsPerRow; i++)
			{
				this->seatsPerRow[i] = l.seatsPerRow[i];
			}
			this->noSeatsPerRow = l.noSeatsPerRow;
		}
		else
		{
			this->seatsPerRow = nullptr;
			this->noSeatsPerRow = 0;
		}
	}

	~Location()
	{
		delete[] seatsPerRow;
	}

	Location& operator=(const Location& l)
	{
		if (this != &l)
		{
			delete[] seatsPerRow;
			this->isVIP = l.isVIP;
			this->noRows = l.noRows;
			if (l.seatsPerRow != nullptr && l.noSeatsPerRow > 0)
			{
				this->seatsPerRow = new int[l.noSeatsPerRow];
				for (int i = 0; i < l.noSeatsPerRow; i++)
				{
					this->seatsPerRow[i] = l.seatsPerRow[i];
				}
				this->noSeatsPerRow = l.noSeatsPerRow;
			}
			else
			{
				this->seatsPerRow = nullptr;
				this->noSeatsPerRow = 0;
			}
		}
		return *this;
	}

	void setVIP(bool isVIP)
	{
		if (isVIP != true)
		{
			this->isVIP = true;
		}
	}
	void setNoRows(int rows)
	{
		if (rows < 1 && rows > 100)
		{
			cout << endl << "Cannot change number of rows. We only have a maximum number of 100 rows.";
		}
		else
			this->noRows = rows;
	}
	
	int getNoRows()
	{
		return this->noRows;
	}
	int getNoSeats()
	{
		int noSeats = noRows * noSeatsPerRow;
		return noSeats;
	 }



	friend void operator<<(ostream& out, Location l);
	friend void operator>>(istream& in, Location& l);
};
int Location::MAXIMUM_SEATS_NUMBER = 300;

void operator<<(ostream& out, Location l)
{
	if (l.isVIP = false)
	{
		out << endl << "The zone is not VIP.";
	}
	else
	{
		out << endl << "The zone is VIP.";
	}
	out << endl << "Rows: " << l.noRows;
	out << endl << "Seats per row: " << l.noSeatsPerRow << endl;
}

void operator>>(istream& in, Location& l)
{
	cout << "Is the zone VIP?";
	in >> l.isVIP;
	cout << "Number of rows: ";
	in >> l.noRows;
	cout << "Number of seats per row: ";
	in >> l.noSeatsPerRow;
}