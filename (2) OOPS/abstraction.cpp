#include <iostream>
using namespace std;

/*
============================================================
                    ABSTRACTION IN C++
============================================================

Definition:
------------
Abstraction means hiding the implementation details and
showing only the essential features to the user.

Real-Life Example:
------------------
ATM Machine
You only know:
    -> Withdraw Money
    -> Deposit Money
    -> Check Balance

You DON'T know:
    -> How the bank server works
    -> Database operations
    -> Security checks

Those details are hidden.

This is called ABSTRACTION.

------------------------------------------------------------

Ways to Achieve Abstraction in C++

1. Abstract Class
2. Pure Virtual Function
3. Interface (100% Abstract Class)

============================================================
*/


//============================================================
// ABSTRACT CLASS
//============================================================

/*
An Abstract Class is a class that contains at least
ONE Pure Virtual Function.

Characteristics:
----------------
✓ Cannot create objects.
✓ Can contain normal functions.
✓ Can contain data members.
✓ Used as a base class.
*/

class Payment
{
protected:

    double amount;

public:

    Payment(double amount)
    {
        this->amount = amount;
    }

    /*
        PURE VIRTUAL FUNCTION

        = 0 makes it pure virtual.

        Every derived class MUST implement it.
    */

    virtual void makePayment() = 0;

    /*
        Normal Function

        Abstract classes can also have
        normal (non-virtual) functions.
    */

    void displayAmount()
    {
        cout << "Amount : Rs. " << amount << endl;
    }

    virtual ~Payment()
    {
        cout << "Payment Destructor Called\n";
    }
};


//============================================================
// CONCRETE CLASS
//============================================================

/*
A Concrete Class is a class that implements
all pure virtual functions.
*/

class CreditCard : public Payment
{
public:

    CreditCard(double amount)
        : Payment(amount)
    {
    }

    void makePayment() override
    {
        cout << "Payment Done Using Credit Card\n";
    }

    ~CreditCard()
    {
        cout << "Credit Card Destructor Called\n";
    }
};


class UPI : public Payment
{
public:

    UPI(double amount)
        : Payment(amount)
    {
    }

    void makePayment() override
    {
        cout << "Payment Done Using UPI\n";
    }

    ~UPI()
    {
        cout << "UPI Destructor Called\n";
    }
};


//============================================================
// INTERFACE
//============================================================

/*
Interface

In C++, there is NO separate keyword called interface.

Instead,

A class having ONLY Pure Virtual Functions
is treated as an Interface.

Interfaces provide 100% abstraction.
*/

class Notification
{
public:

    virtual void sendNotification() = 0;

    virtual ~Notification() {}
};


class SMS : public Notification
{
public:

    void sendNotification() override
    {
        cout << "SMS Notification Sent\n";
    }
};


class Email : public Notification
{
public:

    void sendNotification() override
    {
        cout << "Email Notification Sent\n";
    }
};


//============================================================
// MAIN
//============================================================

int main()
{

//------------------------------------------------------------
// ABSTRACT CLASS
//------------------------------------------------------------

cout << "========== ABSTRACT CLASS ==========\n\n";

/*
The following line is NOT allowed.

Payment p(500);

Reason:
Payment is an Abstract Class.
*/

Payment *payment;

CreditCard card(2500);

payment = &card;

payment->displayAmount();
payment->makePayment();

cout << endl;


//------------------------------------------------------------
// RUNTIME ABSTRACTION
//------------------------------------------------------------

cout << "========== RUNTIME ABSTRACTION ==========\n\n";

/*
Same base pointer,
Different implementations.
*/

UPI upi(1500);

payment = &upi;

payment->displayAmount();
payment->makePayment();

cout << endl;


//------------------------------------------------------------
// INTERFACE
//------------------------------------------------------------

cout << "========== INTERFACE ==========\n\n";

Notification *notify;

SMS sms;

notify = &sms;

notify->sendNotification();

Email email;

notify = &email;

notify->sendNotification();

cout << endl;


//------------------------------------------------------------
// BENEFITS
//------------------------------------------------------------

cout << "========== BENEFITS OF ABSTRACTION ==========\n\n";

cout << "1. Hides implementation details.\n";
cout << "2. Improves security.\n";
cout << "3. Reduces code complexity.\n";
cout << "4. Increases code reusability.\n";
cout << "5. Makes maintenance easier.\n";

cout << endl;


//------------------------------------------------------------
// IMPORTANT THEORY
//------------------------------------------------------------

cout << "========== THEORY ==========\n\n";

cout << "Abstract Class\n";
cout << "- Has at least one Pure Virtual Function.\n";
cout << "- Cannot create objects.\n";
cout << "- Can have constructors.\n";
cout << "- Can have normal functions.\n";
cout << "- Can have data members.\n";

cout << endl;

cout << "Pure Virtual Function\n";
cout << "- Declared using = 0.\n";
cout << "- Must be overridden by child class.\n";

cout << endl;

cout << "Interface\n";
cout << "- Contains only Pure Virtual Functions.\n";
cout << "- Provides 100% abstraction.\n";

cout << endl;

return 0;

}