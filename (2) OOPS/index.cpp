#include<iostream>
using namespace std;

class Student{
   public:

   int id;
   string name;
   int age;
   int rollno;

   Student(int id, string name, int age, int rollno){ //Parameterised constructor
      
      this->id = id;
      this->name = name;
      this->age = age;
      this->rollno = rollno;

      cout<<this->name<<" Student instance created"<<endl;
   }

   Student(const Student &srcObj){ // Copy Constructor
      
      this->id = srcObj.id;
      this->name = srcObj.name;
      this->age = srcObj.age;
      this->rollno = srcObj.rollno;
      cout<<this->name<<" Student Copy instance created from "<<srcObj.name<<endl;

   }

   //Methods
   void study(){
      cout<<this->name<<" Studying"<<endl;
   }

   void bunk(){
      cout<<this->name<<" Bunking"<<endl;
   }

   void sleep(){
      cout<<this->name<<" Sleeping"<<endl;
   }

   void details(){
      cout << this->name << endl;
      cout << this->id << endl;
      cout << this->rollno << endl;
      cout << this->age << endl;
   }

   ~Student(){ //Destructor
      cout<<"Destructor called "<<this->name<< " Student instance deleted"<<endl;
   }
};

int main(){

   Student A(1,"Rakshit",21,755);

   A.details();
   A.study();
   A.bunk();
   A.sleep();

   Student B(A);
   return 0;

}