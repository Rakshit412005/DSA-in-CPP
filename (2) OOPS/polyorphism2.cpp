#include <iostream>
using namespace std;

/*
=========================================================
            RUNTIME POLYMORPHISM
=========================================================

Topics Covered

1. Function Overriding
2. Virtual Function
3. Base Class Pointer
4. Base Class Reference
5. Early Binding
6. Late Binding
7. Pure Virtual Function
8. Abstract Class
9. Virtual Destructor
10. Object Slicing
11. Upcasting
12. Downcasting (dynamic_cast)
13. override keyword
=========================================================
*/

//--------------------------------------------------------
// Abstract Base Class
//--------------------------------------------------------

class Animal
{
public:

    // Pure Virtual Function
    virtual void sound() = 0;

    // Another virtual function
    virtual void eat()
    {
        cout << "Animal is eating." << endl;
    }

    // Virtual Destructor
    virtual ~Animal()
    {
        cout << "Animal Destructor Called" << endl;
    }
};

//--------------------------------------------------------
// Derived Class
//--------------------------------------------------------

class Dog : public Animal
{
public:

    void sound() override
    {
        cout << "Dog says: Bark Bark" << endl;
    }

    void eat() override
    {
        cout << "Dog is eating meat." << endl;
    }

    void fetch()
    {
        cout << "Dog is fetching the ball." << endl;
    }

    ~Dog()
    {
        cout << "Dog Destructor Called" << endl;
    }
};

//--------------------------------------------------------
// Another Derived Class
//--------------------------------------------------------

class Cat : public Animal
{
public:

    void sound() override
    {
        cout << "Cat says: Meow" << endl;
    }

    void eat() override
    {
        cout << "Cat is drinking milk." << endl;
    }

    ~Cat()
    {
        cout << "Cat Destructor Called" << endl;
    }
};

int main()
{

//========================================================
// EARLY BINDING
//========================================================

cout<<"========== EARLY BINDING ==========\n";

Dog d;

d.sound();
d.eat();

cout<<"\n";

//========================================================
// UPCASTING
//========================================================

cout<<"========== UPCASTING ==========\n";

/*
Derived object assigned to Base pointer.
This is called Upcasting.
*/

Animal *ptr;

ptr = &d;

ptr->sound();
ptr->eat();

cout<<"\n";

//========================================================
// LATE BINDING
//========================================================

cout<<"========== LATE BINDING ==========\n";

/*
Since sound() is virtual,
the decision is taken at runtime.
*/

Cat c;

ptr = &c;

ptr->sound();
ptr->eat();

cout<<"\n";

//========================================================
// BASE CLASS REFERENCE
//========================================================

cout<<"========== BASE CLASS REFERENCE ==========\n";

Animal &ref = d;

ref.sound();
ref.eat();

cout<<"\n";

//========================================================
// DOWNCASTING
//========================================================

cout<<"========== DOWNCASTING ==========\n";

/*
Convert Base Pointer back to Derived Pointer
using dynamic_cast.
*/

Animal *animal = new Dog();

Dog *dogPointer = dynamic_cast<Dog*>(animal);

if(dogPointer != nullptr)
{
    dogPointer->fetch();
}

delete animal;

cout<<"\n";

//========================================================
// OBJECT SLICING
//========================================================

cout<<"========== OBJECT SLICING ==========\n";

/*
Object slicing happens when
a derived object is copied into
a base object.

Since Animal is abstract,
we cannot demonstrate slicing here.
Instead, let's explain it.

Example:

class A
{
public:
virtual void show(){}
};

class B : public A
{
};

B obj;
A base = obj;

Only A part is copied.
B specific members are lost.

This is called Object Slicing.
*/

cout<<"Object Slicing cannot be demonstrated because\n";
cout<<"Animal is an Abstract Class.\n";

cout<<"\n";

//========================================================
// VIRTUAL DESTRUCTOR
//========================================================

cout<<"========== VIRTUAL DESTRUCTOR ==========\n";

Animal *obj = new Dog();

delete obj;

/*
Output

Dog Destructor Called
Animal Destructor Called

Without virtual destructor,
only Animal destructor would execute.
*/

cout<<"\n";

//========================================================
// ABSTRACT CLASS
//========================================================

cout<<"========== ABSTRACT CLASS ==========\n";

cout<<"Animal is an Abstract Class.\n";
cout<<"We cannot create Animal objects.\n";

cout<<"\n";

//========================================================
// PURE VIRTUAL FUNCTION
//========================================================

cout<<"========== PURE VIRTUAL FUNCTION ==========\n";

cout<<"sound() is Pure Virtual Function.\n";
cout<<"Every derived class MUST implement it.\n";

return 0;

}