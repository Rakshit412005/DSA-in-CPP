#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Geeks for Geeks solution for finding the kth smallest element in an array using a max heap (priority queue).
class Solution {//copy from here 
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        
        priority_queue<int,vector<int>, less<int>> dq;
        
        for(int i =0; i<n; i++){
           
            dq.push(arr[i]);
            
            while(dq.size()>k){
                dq.pop();
            }
        }
        
        return dq.top();
    }
};