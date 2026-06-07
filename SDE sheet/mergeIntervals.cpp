#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;  

// leetcode solution for merge intervals problem
class Solution { // copy from here
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            if(result.empty() || result.back()[1]<intervals[i][0] ){
                result.push_back(intervals[i]);
            }
            else{
                result.back()[1]=max(result.back()[1], intervals[i][1]);
            }
        }
        return result;
        
    }
};