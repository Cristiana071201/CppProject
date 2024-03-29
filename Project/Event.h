#include <iostream>
using namespace std;

class Event
{
private:
	char* eventName = nullptr;
	//date
	int eventDay = 1;
	string eventMonth = " ";
	int eventYear = 2022;
	//time
	int eventHour = 00;
	int eventMinute = 00;
	string eventCity = " ";
	string eventStreet = " ";
	int noStreet = 0;

public:
	Event()
	{
		eventName = nullptr;
		eventDay = 00;
		eventMonth = "unknown";
		eventYear = 0000;
		eventHour = 00;
		eventMinute = 00;
		eventCity = "unknown";
		eventStreet = "unknown";
		noStreet = 0;
	}

	Event(const char* eventName, int eventDay, string eventMonth, int eventYear, int eventHour, int eventMinute, string eventCity, string eventStreet, int noStreet)
	{
		if (eventName != nullptr)
		{
			this->eventName = new char[strlen(eventName) + 1];
			strcpy_s(this->eventName, strlen(eventName) + 1, eventName);
		}
		this->eventDay = eventDay;
		this->eventMonth = eventMonth;
		this->eventYear = eventYear;
		this->eventHour = eventHour;
		this->eventMinute = eventMinute;
		this->eventCity = eventCity;
		this->eventStreet = eventStreet;
		this->noStreet = noStreet;
	}

	Event(const Event& e)
	{
		if (e.eventName != nullptr)
		{
			this->eventName = new char[strlen(e.eventName) + 1];
			strcpy_s(this->eventName, strlen(e.eventName) + 1, e.eventName);
		}
		this->eventDay = e.eventDay;
		this->eventMonth = e.eventMonth;
		this->eventYear = e.eventYear;
		this->eventHour = e.eventHour;
		this->eventMinute = e.eventMinute;
		this->eventCity = e.eventCity;
		this->eventStreet = e.eventStreet;
		this->noStreet = e.noStreet;
	}

	~Event()
	{
		delete[] eventName;
	}

	Event& operator=(const Event& e)
	{
		if (this != &e)
		{
				delete[] eventName;
				if (e.eventName != nullptr)
				{
					this->eventName = new char[strlen(e.eventName) + 1];
					strcpy_s(this->eventName, strlen(e.eventName) + 1, e.eventName);
				}
				this->eventDay = e.eventDay;
				this->eventMonth = e.eventMonth;
				this->eventYear = e.eventYear;
				this->eventHour = e.eventHour;
				this->eventMinute = e.eventMinute;
				this->eventCity = e.eventCity;
				this->eventStreet = e.eventStreet;
				this->noStreet = e.noStreet;
		}
		return *this;
	}

	void setEventName(const char* eventName)
	{
		if (eventName != nullptr)
		{
			if (this->eventName != nullptr)
			{
				delete[] this->eventName;
			}
			this->eventName = new char[strlen(eventName) + 1];
			strcpy_s(this->eventName, strlen(eventName) + 1, eventName);
		}
	}
	void setEventDay(int day)
	{
		if (day < 1 && day > 30)
		{
			cout << endl << "Cannot change the day. Input should be only from 1 to 30.";
		}
		else
			this->eventDay = day;
	}
	void setEventMonth(string month)
	{
		if (month == "January" || month == "February" || month == "March" || month == "April" || month == "May" || month == "June" || month == "July" || month == "August" || month == "September" || month == "October" || month == "November" || month == "December")
		{
			this->eventMonth = month;
		}
		else
			cout << endl << "Cannot change the month. Input should respect 2 rules: capital first letter, full month name.";
	}
	void setEventYear(int year)
	{
		if (year < 2022 && year > 2025)
		{
			cout << endl << "Cannot change the year. Input should be only from 2022 to 2025.";
			this->eventYear = year;
		}
		else
			this->eventYear = year;
	}
	void setEventHour(int hour)
	{
		if (hour < 0 && hour > 24)
		{
			cout << endl << "Cannot change the hour. Input should be only from 0 to 24.";
		}
		else
			this->eventHour = hour;
	}
	void setEventMinute(int minute)
	{
		if (minute < 0 && minute > 60) 
		{
			cout << endl << "Cannot change the minutes. Input should be only from 0 to 60.";
		}
		else
			this->eventMinute = minute;
	}
	void setEventCity(string city)
	{
		this->eventCity = city;
	}
	void setEventStreet(string street)
	{
		this->eventStreet = street;
	}
	void setNoStreet(int no)
	{
		if (no < 0 && no > 50)
		{
			cout << endl << "Cannot change the street number. Input should be only from 1 to 50.";
		}
		else
			this->noStreet = no;
	}

	char* getEventName()
	{
		return eventName;
	}
	int getEventDay()
	{
		return this->eventDay;
	}
	string getEventMonth()
	{
		return this->eventMonth;
	}
	int getEventYear()
	{
		return this->eventYear;
	}
	int getEventHour()
	{
		return this->eventHour;
	}
	int getEventMinute()
	{
		return this->eventMinute;
	}
	string getEventCity()
	{
		return this->eventCity;
	}
	string getEventStreet()
	{
		return this->eventStreet;
	}
	int getNoStreet()
	{
		return this->noStreet;
	}

	bool operator==(const Event& l)	//returns true if all the fields of two events are equal
	{
		return strcmp(eventName, l.eventName) == 0 && eventDay == l.eventDay && eventMonth == l.eventMonth && eventYear == l.eventYear && eventHour == l.eventHour && eventMinute == l.eventMinute && eventCity == l.eventCity && eventStreet == l.eventStreet && noStreet == l.noStreet;
	}

	int operator[](const string& fieldName)
	{
		if (fieldName == "eventDay") return eventDay;
		if (fieldName == "eventYear") return eventYear;
		if (fieldName == "eventHour") return eventHour;
		if (fieldName == "eventMinute") return eventMinute;
		if (fieldName == "noStreet") return noStreet;
		else
		{
			cout << "Invalid field name." << endl;
		}
	}

	friend void operator<<(ostream& out, Event e);
	friend void operator>>(istream& in, Event& e);
};


void operator<<(ostream& out, Event e) 
{
	if (e.eventName != nullptr) 
	{
		out << endl << "Event name: " << e.eventName;
	}
	out << endl << "Date: " << e.eventDay << "-" << e.eventMonth << "-" << e.eventYear;
	out << endl << "Hour: " << e.eventHour << ":" << e.eventMinute;
	out << endl << "Address: " << e.eventCity << " street " << e.eventStreet << " number " << e.noStreet << endl;
}

void operator>>(istream& in, Event& e) 
{
	cout << endl << "Event name: ";
	char buffer[100];
	in >> buffer;
	if (e.eventName != nullptr) {
		delete[] e.eventName;
		e.eventName = nullptr;
	}
	e.eventName = new char[strlen(buffer) + 1];
	strcpy_s(e.eventName, strlen(buffer) + 1, buffer);
	cout << "Day: ";
	in >> e.eventDay;
	cout <<  "Month: ";
	in >> e.eventMonth;
	cout <<  "Year: ";
	in >> e.eventYear;
	cout <<  "Hour: ";
	in >> e.eventHour;
	cout <<  "Minute: ";
	in >> e.eventMinute;
	cout <<  "City: ";
	in >> e.eventCity;
	cout <<  "Street: ";
	in >> e.eventStreet;
	cout <<  "Number of street: ";
	in >> e.noStreet;
}
