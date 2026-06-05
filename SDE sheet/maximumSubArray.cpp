#include <iostream>
#include <vector>
using namespace std;   


// leetcode solution for maximum sub array problem 
class Solution {  // copy from here
public:
    int maxSubArray(vector<int>& nums) {
        int n =nums.size();
        int currentSum = nums[0];
        int maxSum = nums[0];

        for(int i = 1; i<n ; i++){
            currentSum = max(nums[i],currentSum+nums[i]);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};