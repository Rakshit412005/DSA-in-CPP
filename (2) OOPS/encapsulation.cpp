#include<iostream>
using namespace std;

class Student{

   private:
   
   int id;
   string name;
   int age;
   int rollno;
   int studyHrs;

   public:
   Student(int id, string name, int age, int rollno,int studyHrs){ //Parameterised constructor
      
      this->id = id;
      this->name = name;
      this->age = age;
      this->rollno = rollno;
      this->studyHrs = studyHrs;

      cout<<this->name<<" Student instance created"<<endl;
   }

   Student(const Student &srcObj){ // Copy Constructor
      
      this->id = srcObj.id;
      this->name = srcObj.name;
      this->age = srcObj.age;
      this->rollno = srcObj.rollno;
      cout<<this->name<<" Student Copy instance created from "<<srcObj.name<<endl;

   }

   private:
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

   public:
   void getDetails(){
      cout <<"Name - "<< this->name << endl;
      cout<< "ID - "<< this->id << endl;
      cout<<"Roll no - " << this->rollno << endl;
      cout<<"Age - " << this->age << endl;
      cout<<"Studying Hours - " << this->studyHrs << endl;
   }

   private:
   void studyingHrs(){
    cout<<this->name<<"Studying hours are"<<studyHrs<<endl;
   }

   public:
   ~Student(){ //Destructor
      cout<<"Destructor called "<<this->name<< " Student instance deleted"<<endl;
   }
};

int main(){

   Student A(1,"Rakshit",21,755,7);
   A.getDetails(); 
   return 0;

}