#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//leetcode solution for removing nth node from end of linked list
class Solution {// copy from here
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return head;
        }
        if(head->next==NULL){
            head = NULL;
            return head;
        }
        ListNode* temp = head;
        ListNode* pt = head;
        int cnt=0;
        while(temp!= NULL){
            temp=temp->next;
            cnt++;
        }
        
        if(n==cnt){
            return head->next;
        }

        for(int i =1;i<cnt-n;i++){
            pt=pt->next;
        }
        pt->next = pt->next->next;
        return head;   
    }
};