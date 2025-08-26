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

void insertAtPosition(Node* &Head,int position, int d){

    if(position==1){
        instertAtHead(Head,d);
        return;
    }

    Node *temp = Head;
    int count = 1;
    while (count < position -1){
        temp = temp->next;
    }
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
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
    insertAtPosition(Head,2,12);
    print(Head);
    return 0;
}