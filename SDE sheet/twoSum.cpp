#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//leetcode solution for two sum problem
class Solution {//copy from here
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        vector<int> ans;
        int n = nums.size();

        for(int i =0; i<n;i++){
            int comp = target - nums[i];
            if(map.find(comp) != map.end()){
                ans.push_back(map[comp]);
                ans.push_back(i);
            }
            else{
                map[nums[i]] = i;
            }
        }
        return ans;
    }
};