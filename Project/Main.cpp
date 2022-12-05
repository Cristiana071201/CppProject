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

	Event event1("Concert", 07, "December", 2022, 23, 30, "Bucuresti", "Stefan cel Mare", 7);
	Event event2("Football Game", 12, "November", 2023, 16, 30, "Bacau", "Strada Principala", 12);
	cin >> event1;
	cout <<  "Information about the event: ";
	cout << event1;

}