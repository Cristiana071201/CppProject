#include <iostream>
using namespace std;

enum ZoneType { VIP, NORMAL};

class Location
{
private:
	string locationName = " ";
	ZoneType type = NORMAL;
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
		locationName = "";
		noRows = 10;
		seatsPerRow = nullptr;
		noSeatsPerRow = 10;
	}

	Location(string locationName, ZoneType type, int noRows, int* seatsPerRow, int noSeatsPerRow)
	{
		this->locationName = locationName;
		this->type = type;
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
		this->locationName = l.locationName;
		this->type = l.type;
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
			this->locationName = l.locationName;
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
	out << endl << "Location name: " << l.locationName;
	out << endl << "Rows: " << l.noRows;
	out << endl << "Seats per row: " << l.noSeatsPerRow << endl;
}

void operator>>(istream& in, Location& l)
{
	cout << "Location name: ";
	in >> l.locationName;
	cout << "Number of rows: ";
	in >> l.noRows;
	cout << "Number of seats per row: ";
	in >> l.noSeatsPerRow;
	cout << "Zone type: ";
	in >> l.locationName;
}