#include<iostream>
using namespace std;

class Student{
   public:

   int id;
   string name;
   int age;
   int rollno;

   Student(int id, string name, int age, int rollno){
      
      this->id = id;
      this->name = name;
      this->age = age;
      this->rollno = rollno;

      cout<<this->name<<" Student instance created"<<endl;
   }

   void study(){
      cout<<this->name<<" Studying"<<endl;
   }

   void bunk(){
      cout<<this->name<<" Bunking"<<endl;
   }

   void sleep(){
      cout<<this->name<<" Sleeping"<<endl;
   }
};

int main(){

   Student A(1,"Rakshit",21,755);

   cout<<A.name<<endl;
   cout<<A.id<<endl;
   cout<<A.rollno<<endl;
   cout<<A.age<<endl;

   A.study();
   A.bunk();
   A.sleep();

   return 0;

}