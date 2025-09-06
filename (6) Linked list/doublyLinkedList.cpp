#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->prev = NULL;
        this->data = data;
        this->next = NULL;
    }
  
};

void insertAtHead(Node* &Head, int d){
    Node* temp = new Node(d);
    temp->next = Head;
    Head->prev = temp;
    Head = temp;
}

void insertAtTail(Node* &Tail,int d){
    Node* temp = new Node(d);
    Tail->next = temp;
    temp->prev = Tail;
    Tail = temp; 
}

void insertAtPosition(Node* &Head,Node* &Tail,int position,int d){
    Node* temp = Head;

    if(position == 1){
        insertAtHead(Head,d);
        return;
    }

    int count = 1;
    while(count < position-1){
        temp = temp->next;
        count++;
    }
    
    if(temp->next == NULL){
        insertAtTail(Tail,d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->prev = temp;
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;

}

void deleteAtPosition(Node* &Head, Node* &Tail, int position){
    Node* temp = Head;
    int count = 1;

    while(count<position-1){
        temp=temp->next;
        count++;
    }

    if(position==1){
        Node* nodeToDelete = Head;
        Head->next->prev = NULL;
        Head = nodeToDelete->next;
        nodeToDelete->next = NULL;
        delete nodeToDelete;
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next->prev = NULL;
    temp->next->next = NULL;
    temp->next = nodeToDelete->next;
    nodeToDelete->next->prev = temp;
    delete nodeToDelete;


    if(temp->next->next == NULL){
        Node* nodeToDelete = Tail;
        Tail->prev = NULL;
        temp->next= NULL;
        Tail= temp;
        delete nodeToDelete;
        return;
    }

}

void print(Node* &Head)
{
    Node *temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void getLength(Node* &Head){
    Node* temp = Head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    cout<<"Length of linked list is "<<len<<endl;
    
}

int main()
{
    Node* node1 = new Node(10);
    Node* Head = node1;
    Node* Tail = node1;
    print(Head);
    getLength(Head);
}