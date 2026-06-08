#include<iostream>
#include<stack>
using namespace std;

// Geeks for Geeks solution for delete middle of stack problem
class Solution { // copy from here
  public:
    // Function to delete middle element of a stack.

    void solve(stack<int>&s, int n, int count){
        if(count == n/2){
            s.pop();
            return;
        }
        int top = s.top();
        s.pop();
        solve(s,n,count+1);
        s.push(top);
    }

    void deleteMid(stack<int>& s) {
        // code here..
        int n = s.size();
        int count = 0;
        
        solve(s,n,count);
        
    }
};