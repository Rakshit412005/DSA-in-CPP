#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    };
    ~Node(){
        int value = this->data;
        if(this->next == NULL){
            delete next; 
            this->next = NULL;
        }
        cout<<"memory is freed from node with data "<<value<<endl;
    }
};

void instertAtHead(Node* &Head, int d)
{
    Node *temp = new Node(d);
    temp->next = Head;
    Head = temp;
};

void insertAtTail(Node* &Tail, int d){
    Node *temp = new Node(d);
    Tail->next = temp;
    Tail = temp;
}

void insertAtPosition(Node* &Head,Node* &Tail,int position, int d){

    if(position==1){
        instertAtHead(Head,d);
        return;
    }
    
    Node *temp = Head;
    int count = 1;
    while (count < position -1){
        temp = temp->next;
        count++;
    }
    if(temp->next == NULL){
        insertAtTail(Tail,d);
        return;
    }
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteAtPosition(Node* &Head,Node* &Tail, int position){
    Node* temp = Head;
    int count = 1;
    while(count < position -1 ){
        temp = temp->next;
        count++;
    }
    if(position == 1){
        Node* temp = Head;
        Head= Head->next;
        delete temp;
    }
    if(temp->next->next==NULL){
        Node* nodeToDelete = temp->next;
        temp->next = NULL;
        Tail =temp;
        delete nodeToDelete;
        return;
    }
    Node* nodeToDelete = temp->next;      
    temp->next = nodeToDelete->next;       
    delete nodeToDelete;

}

void print(Node *&Head)
{
    Node *temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    Node *node1 = new Node(10);
    Node *Head = node1;
    Node *Tail = node1;
    instertAtHead(Head, 9);
    print(Head);
    insertAtTail(Tail,11);
    print(Head);
    insertAtPosition(Head,Tail,3,12);
    print(Head);
    return 0;
}