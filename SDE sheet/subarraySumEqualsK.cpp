#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//LeetCode solution for Subarray Sum Equals K 
class Solution {//copy from here
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int count = 0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end()){
                count+=mp[sum-k];
            }
            mp[sum]++;
        }
        return count;
 
    }
};