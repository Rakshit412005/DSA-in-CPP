#include <iostream>
using namespace std;

/*
=========================================================
        COMPILE-TIME POLYMORPHISM
=========================================================

Compile-time polymorphism means the compiler decides
which function/operator to call BEFORE the program runs.

Types:
1. Function Overloading
2. Operator Overloading
=========================================================
*/

//--------------------------------------------------------
// Function Overloading
//--------------------------------------------------------

class Calculator
{
public:

    // Same function name but different parameters

    int add(int a, int b)
    {
        return a + b;
    }

    double add(double a, double b)
    {
        return a + b;
    }

    int add(int a, int b, int c)
    {
        return a + b + c;
    }
};

//--------------------------------------------------------
// Operator Overloading
//--------------------------------------------------------

class Complex
{
private:

    int real;
    int imaginary;

public:

    Complex(int real = 0, int imaginary = 0)
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    // Overloading + operator
    Complex operator + (const Complex &obj)
    {
        Complex temp;

        temp.real = real + obj.real;
        temp.imaginary = imaginary + obj.imaginary;

        return temp;
    }

    void display()
    {
        cout << real << " + " << imaginary << "i";
    }
};

int main()
{
    cout << "========== FUNCTION OVERLOADING ==========\n\n";

    Calculator calc;

    cout << "add(5,10) = ";
    cout << calc.add(5,10) << endl;

    cout << "add(4.5,6.3) = ";
    cout << calc.add(4.5,6.3) << endl;

    cout << "add(2,3,4) = ";
    cout << calc.add(2,3,4) << endl;

    cout << "\n";

    cout << "========== OPERATOR OVERLOADING ==========\n\n";

    Complex c1(2,3);
    Complex c2(5,4);

    Complex c3 = c1 + c2;

    cout << "Complex Number 1 = ";
    c1.display();

    cout << endl;

    cout << "Complex Number 2 = ";
    c2.display();

    cout << endl;

    cout << "After Addition = ";
    c3.display();

    cout << endl;

    return 0;
}