#include <vector>
#include <iostream>
#include <climits>
using namespace std;

// leetcode solution for best time to buy and sell a stock problem
class Solution { // copy from here
public:


    int maxProfit(vector<int>& prices) {
       int maxProfit = 0;
       int n = prices.size();
       int min = INT_MAX;
       
       for(int i = 0; i<n; i++){
        if(prices[i]<min){
            min = prices[i];
        }
        int profit = prices[i]-min;
        if(profit>maxProfit){
            maxProfit = profit;
        }

       }
       return maxProfit;
    }
};