#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// leetcode solution for container with most water problem
class Solution {// copy from here
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        int left = 0;
        int right = n-1;
        int area = 0;
        int maxArea = 0;

        while(left < right){
            int lmax = height[left];
            int rmax = height[right];

            int length = min(lmax,rmax);
            int width = right - left;

            area = length * width;
            maxArea = max(area,maxArea);

            if(lmax > rmax){
                right--;
            }
            else{
                left++;
            }
        }

        return maxArea;

    }
};