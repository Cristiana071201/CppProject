#include <iostream>
using namespace std;
#include "Event.h"
#include "Location.h"
#include "Tickets.h"
#include "ticketVerifier.h"

int main()
{
	Ticket t1;
	cout << "The ticket's unique id is: " << t1.getUniqueId() << endl;
	int tickets[]{ 22, 31, 5 };
	Ticket t2( 1, 1, CHILD, tickets, 3, 12);
	cout << "The ticket's unique id is: " << t2.getUniqueId() << endl;
}