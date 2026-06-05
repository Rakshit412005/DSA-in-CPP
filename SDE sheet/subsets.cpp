#include <iostream>
#include <vector>
using namespace std;  

// leetcode solution for subsets problem
class Solution { // copy from here
public:

    void solve(int index, vector<int>&nums, vector<int>output, vector<vector<int>>&ans){
        
        if(index >= nums.size()){
            ans.push_back(output);
            return;
        }

        solve(index+1,nums,output,ans); //excluded
        
        int element = nums[index];
        output.push_back(element);
        solve(index+1,nums,output,ans);
        
        output.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
      
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;

        solve(index,nums,output,ans);
        return ans;
    }
};