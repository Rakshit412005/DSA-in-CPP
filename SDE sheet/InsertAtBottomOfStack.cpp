// User function Template for C++
#include<iostream>
#include<stack>
using namespace std;

// Geeks for Geeks solution for insert at bottom of stack problem
class Solution {// copy from here
  public:
  
  void solve(stack<int>&st,int count, int n,int x){
      
        if(count == n){
            st.push(x);
            return;
        }
        int top = st.top();
        st.pop();
        solve(st,count+1,n,x);
        st.push(top);
  }
  
    stack<int> insertAtBottom(stack<int> st, int x) {
    
        int count =0;
        int n = st.size();
        
        solve(st,count,n,x);
        return st;
        
    }
};