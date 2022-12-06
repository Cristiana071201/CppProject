#include <iostream>
using namespace std;
#include "Event.h"
#include "Location.h"
#include "Tickets.h"
#include "ticketVerifier.h"

int main()
{
	//Ticket t1;
	//cout << "The ticket's unique id is: " << t1.getUniqueId() << endl;
	//int tickets[]{ 22, 31, 5 };
	//Ticket t2( 1, 1, CHILD, tickets, 3, 12);
	//cout << "The ticket's unique id is: " << t2.getUniqueId() << endl;

	Event Concert("Concert", 7, "December", 2022, 23, 30, "Bucuresti", "Stefan cel Mare", 7);
	Event Football("Football", 9, "March", 2023, 16, 30, "Bacau", "Strada Principala", 9);
	Event Movie("Movie", 12, "November", 2022, 20, 30, "Bucuresti", "Nicolae Balcescu", 2);

	//testing information
	//cin >> Concert;
	//cout << "Information about the event: ";
	//cout << Concert;
	
	//if (eventName == "Concert" || eventName == "concert")
	//{
	//	cout << Concert;
	//}
	//else
	//	cout << "Wrong event name.";
	//if (eventName == "Football Game" || eventName == "football game" || eventName == "Football game")
	//{
	//	cout << FootballGame;
	//}
	//else 
	//	cout << "Wrong event name.";
	//if (eventName == "Theatre Show" || eventName == "theatre show" || eventName == "Theatre show")
	//{
	//	cout << TheatreShow;
	//}
	//else
	//	cout << "Wrong event name.";

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

	Concert.setEventMinute(100);

	Event Film;
	cout << Film;
}