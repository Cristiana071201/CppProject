#include <iostream>
using namespace std;

class Payment {
public:
    virtual void processPayment() = 0;
};

class CreditCardPayment : public Payment {
private:
    float amount;
public:
    virtual void processPayment() 
    {
        cout << "Processing payment of $" << amount << " with a credit card." << endl;
        cout << "Payment Successful!" << endl;
    }
};