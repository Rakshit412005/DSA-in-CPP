#include<iostream>
#include<vector>
using namespace std;

//leetcode solution for majority element 1
class Solution {//copy from here
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int ele =0;
        int n = nums.size();

        for(int i =0;i<n;i++){
            if(cnt == 0){
                cnt++;
                ele =  nums[i];
            }
            else if(ele ==  nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }  
        }
        return ele;
    }
};