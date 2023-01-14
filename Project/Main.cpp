#include <iostream>
#include <string>
using namespace std;
#include "Event.h"
#include "Location.h"
#include "Tickets.h"
#include "ticketVerifier.h"

int main()
{
	//creating events
	Event Concert("Concert", 7, "December", 2022, 23, 30, "Bucuresti", "Stefan cel Mare", 7);
	Event Football("Football", 9, "March", 2023, 16, 30, "Bacau", "Strada Principala", 9);
	Event Movie("Movie", 12, "November", 2022, 20, 30, "Bucuresti", "Nicolae Balcescu", 2);

	Verify verifier;
	Ticket ticket;
	while (true) {
		cout << "Ticket Management Application" << endl;
		cout << "1. Informations about the location" << endl;
		cout << "2. Informations about the event" << endl;
		cout << "3. Generate tickets" << endl;
		cout << "4. Validate ticket" << endl;
		cout << "5. Exit" << endl;

		int option;
		cin >> option;

		if (option == 1)
		{
			string location;
			cout << "Enter name of the location: " << endl;
			cin >> location;
			if (location == "Concert" || location == "concert")
			{
				cout << Concert;
			}
			else if (location == "Football" || location == "football")
			{
				cout << Football;
			}
			else if (location == "Movie" || location == "movie")
			{
				cout << Movie;
			}
			else
				cout << "Wrong location name. Check spelling or try searching for another location." << endl;
		}
		else if (option == 2)
		{
			string event;
			cout << "Enter name of the event: " << endl;
			cin >> event;
			if (event == "Concert" || event == "concert")
			{
				cout << Concert;
			}
			else if (event == "Football" || event == "football")
			{
				cout << Football;
			}
			else if (event == "Movie" || event == "movie")
			{
				cout << Movie;
			}
			else
				cout << "Wrong event name. Check spelling or try searching for another event." << endl;
		}
		else if (option == 3)
		{
			int uniqueID = ticket.generateUniqueID();
			cout << "Ticket generated with ID: " << uniqueID << endl;
		}
		else if (option == 4)
		{
			int ticketID;
			cout << "Enter ticket ID: ";
			cin >> ticketID;
			if (verifier.verifyTicket(ticketID)) 
			{
				cout << "Ticket is valid." << endl;
			}
			else
			{
				cout << "Ticket is not valid." << endl;
			}
		}
		else if (option == 5)
		{
			break;
		}
		else 
		{
			cout << "Invalid option. Please enter a valid one." << endl;
		}
	}

	//testing
	
	//Concert.setEventMinute(100);

	//Event Film;
	////cout << Film;

	//Event Meci;
	//cin >> Meci;
	//cout << Meci;

	//Ticket t1;
	//cout << endl << "The ticket's unique ID is: " << t1.getUniqueID() << endl;
	////int tickets[]{ 22, 31, 5 };
	////Ticket t2( 1, 1, CHILD, tickets, 3, 12);
	////cout << "The ticket's unique ID is: " << t2.getUniqueID() << endl;

	//int tickets[]{ 14, 15, 16 };
	//Ticket t5(1, 1, 1, ADULT, tickets, 3);

	//cin >> t5;
	//cout << t5;
}