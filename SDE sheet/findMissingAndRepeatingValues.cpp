#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//leetcode solution for find missing and repeating values problem
class Solution {// copy from here
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int>map;
        vector<int> res;
       int n= grid.size();
        for(int i = 0; i<n; i++){
            for(int j =0;j<n;j++){
                map[grid[i][j]]++;
            }
            
        }
        int currSum = 0;
        for(auto it= map.begin(); it!= map.end(); it++){
            currSum+=it->first;
            if(it->second >1){
                res.push_back(it->first);
            }
           
        }
        
        long long N = 1LL * n * n;
        long long totalSum = N * (N + 1) / 2;

        res.push_back(totalSum-currSum);



        return res;
    }
};