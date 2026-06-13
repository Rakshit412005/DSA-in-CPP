#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//leetcode solution for middle of linked list
class Solution {//copy from here
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL ){
            slow=slow->next;
            fast = fast->next->next;
            
        }
        return slow;
    }
};