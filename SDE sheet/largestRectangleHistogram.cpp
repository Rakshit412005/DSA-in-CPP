#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

// leetcode solution for largest rectangle in histogram problem
class Solution { // copy from here
public:

    vector<int>nextSmaller(vector<int>height, int n){
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);

        for(int i = n-1; i>=0; i--){
            int curr = height[i];
            while(s.top()!= -1 && height[s.top()] >=curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmaller(vector<int>height,int n){
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);

        for(int i = 0; i<n; i++){
            int curr = height[i];
            while(s.top()!= -1 && height[s.top()]>=curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }


    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();

        vector<int>next(n);
        next = nextSmaller(heights,n);
        vector<int>prev(n);
        prev = prevSmaller(heights,n);

        int area = INT_MIN;

        for(int i =0; i<n ; i++){
            
            int height = heights[i];
            if(next[i] == -1){
                next[i] = n;
            }
            int width = next[i]-prev[i]-1;
            
            int newArea = height*width;

            area = max(area,newArea);
        }
        return area;
    }
};