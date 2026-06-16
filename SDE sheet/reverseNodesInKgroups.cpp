#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//leetcode solution for reversing nodes in k groups in a linked list
class Solution {// copy from here
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        for(int i=0;i<k;i++){ // checked if there are k nodes in the LL
            if(temp==NULL){
                return head;
            }
            else{
                temp = temp->next; 
            }
        }

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        for(int j =0; j<k;j++){ // reversing upto k elements
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if(next != NULL){ // checking if nodes are still remaining to reverse
            head->next = reverseKGroup(next,k); // if yes then connecting them
        }
        return prev; // returning the head of the reversed LL
    }
};