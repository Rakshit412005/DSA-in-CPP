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

void instertAtHead(Node *&Head, int d)
{
    Node *temp = new Node(d);
    temp->next = Head;
    Head = temp;
};

void print(Node *&Head)
{
    Node *temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *node1 = new Node(10);
    Node *Head = node1;
    instertAtHead(Head, 9);
    print(Head);
    return 0;
}