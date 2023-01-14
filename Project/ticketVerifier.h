#include <iostream>
using namespace std;

class Verify {
public:
    int lastGeneratedID;

    int generateLastID(int uniqueID)
    {
        lastGeneratedID = uniqueID;
        return uniqueID;
    }

    bool verifyTicket(int uniqueID)
    {
        return uniqueID == lastGeneratedID;
    }
};