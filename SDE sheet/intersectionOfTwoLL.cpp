#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//leetcode solution for finding the intersection of two linked lists
class Solution {// copy from here
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      

        if(headA == NULL ||   headB == NULL ){
            return NULL;
        }
        else{
            ListNode* tempA = headA;
            ListNode* tempB = headB;

            while(tempA != tempB){
                if(tempA == NULL){
                    tempA = headB;
                }
                else{
                    tempA=tempA->next;
                }
                if(tempB == NULL){
                    tempB = headA;
                }
                else{
                    tempB=tempB->next;
                }
            }
            return tempA;

        }
      
    }
};