#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// leetcode solution for trapping rain water problem
class Solution { // copy from here
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int lmax = INT_MIN;
        int rmax = INT_MIN;
        int ans =0;

        while(left<right){
            lmax = max(lmax,height[left]);
            rmax = max(rmax,height[right]);

            if(lmax<rmax){
                ans+= lmax-height[left];
                left++;
            }
            else{
                ans+= rmax - height[right];
                right--;
            }
        }
        return ans;
    }
};