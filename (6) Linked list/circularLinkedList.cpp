#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int val = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory is free for node with data "<<val<<endl;
    }
};

void insertNode(Node* &Tail, int element, int data){
    if(Tail == NULL){
        Node* newNode = new Node(data);
        Tail= newNode;
        newNode->next = newNode;
    }
    else{
        Node* curr = Tail;
        while (curr->data != element){
            curr=curr->next;
        }
        Node* temp =new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
};

void deleteNode(Node* &Tail, int element){
     if(Tail == NULL){
        cout<<"LL is empty"<<endl;
        return;
     }
     else{
         Node* prev = Tail;
         Node* curr = Tail->next;

         while(curr->data != element){
            prev= curr;
            curr=curr->next;
         } 

         prev->next = curr->next;

         if(curr == prev){
            Tail = NULL;
         }

         
         else if(Tail == curr){
            Tail=prev;
         }
         curr->next = NULL;
         delete curr;
     }
}

void print(Node *&Tail)
{
    if(Tail == NULL){
        cout<<"LL is empty"<<endl;
    }

    Node *temp = Tail;
    do{
        cout<<temp->data<<"\t";
        temp = temp->next;
    }
    while (Tail!=temp);
    
    cout<<endl;
}

int main(){
    Node* Tail = NULL;
    insertNode(Tail,2,3);
    print(Tail);
    // insertNode(Tail,3,5);
    // print(Tail);
    // insertNode(Tail,5,7);
    // print(Tail);
    // insertNode(Tail,5,6);
    // print(Tail);
     deleteNode(Tail,3);
    print(Tail);
    return 0;
}
