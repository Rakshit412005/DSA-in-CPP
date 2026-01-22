#include <vector>
#include <iostream>
using namespace std;

// User function template for C++

class Solution {
  public:
    // Function to find elements in the array that are equal to their index.
    vector<int> valueEqualToIndex(vector<int>& arr) {
        vector<int> result;
        int length = arr.size();
        for (int i = 1; i<=length; i++){
            if (i==arr[i-1]){
                result.push_back(i);
            }
        }
        return result;
    }
};