# Theory Summary (for Exams)

## 1. Abstraction

> Hiding implementation details and showing only essential features.

Example:

* ATM
* Car
* Mobile Phone

---

## 2. Abstract Class

* Has **at least one pure virtual function**.
* Cannot create objects.
* Can have:

  * Constructors ✅
  * Destructors ✅
  * Data members ✅
  * Normal member functions ✅
  * Virtual functions ✅

Example:

```cpp
class Shape
{
public:
    virtual void draw() = 0;
};
```

---

## 3. Pure Virtual Function

Declared using:

```cpp
virtual void show() = 0;
```

Purpose:

* Forces every child class to provide its own implementation.

---

## 4. Concrete Class

A class that implements all inherited pure virtual functions.

```cpp
class Circle : public Shape
{
public:
    void draw() override
    {
    }
};
```

---

## 5. Interface (C++)

Unlike Java, C++ has **no `interface` keyword**.

An interface is simply an abstract class where **all member functions are pure virtual** (and typically it has no data members).

Example:

```cpp
class Printable
{
public:
    virtual void print() = 0;
    virtual ~Printable() {}
};
```

---

## 6. Runtime Abstraction

Using a base-class pointer or reference to call implementations provided by derived classes.

```cpp
Payment* p = new UPI(1000);
p->makePayment();
```

The caller doesn't need to know *how* the payment is processed—only that it can request a payment.

---

# Does this cover everything?

For a typical C++ OOP syllabus, yes. It includes the core theory and practical concepts related to abstraction:

* ✅ Abstraction
* ✅ Abstract Class
* ✅ Pure Virtual Function
* ✅ Concrete Class
* ✅ Interface
* ✅ Runtime Abstraction
* ✅ Real-life Example
* ✅ Theory Notes
* ✅ Exam-Oriented Comments

This is generally sufficient for college exams and gives you a strong conceptual foundation for interviews as well.
